#include <iostream>
#include "databasebst.h"
#include <QString>
#include <QCoreApplication>
#include <QtDebug>

// constructor
DatabaseBST::DatabaseBST()
{
    total_spots = 20;
    for (int i = 0; i < 20; i++)
    {
        free_spots[i] = true;
    }
    root = NULL;
    marker = "#";

    CreateDataFiles();
}

DatabaseBST::~DatabaseBST() {
    DestroyBST(this->root);
}

// we need to create a hash value in order to uniquely identify each entry
unsigned long DatabaseBST::CreateHash(std::string s) {
    unsigned long hash = 5381;

    for (int i = 0; i < (int)s.length(); i++)
    {
        hash = ((hash << 5) + hash) + (unsigned long)s[i];
    }

    qDebug() << hash;
    return hash;
}

// recursively destroying the bst in order to avoid any memory issues
void DatabaseBST::DestroyBST(struct Node* node) {
    if (node) {
        DestroyBST(node->left);
        DestroyBST(node->right);
        delete node;
    }
}

// after we rebuilding the BST, we do an inorder traversal so that we can append
// the nodes into the inorder_trav_rebuild arr
// the inorder_trav_rebuild_arr gets used in order to rebuild the table in the UI
void DatabaseBST::InOrderTravRebuild(struct Node *node) {
    if (node == nullptr) {
        return;
    }

    InOrderTravRebuild(node->left);
    inorder_trav_rebuild.push_back(node);
    InOrderTravRebuild(node->right);
}

std::vector<struct Node*> DatabaseBST::get_inorder_trav_rebuild() {
    return inorder_trav_rebuild;
}

void DatabaseBST::CreateDataFiles() {
    std::ofstream my_data_file("data.txt", std::ios::app);
    my_data_file.close();
    std::ofstream my_storage_file("storage.txt", std::ios::app);
    my_storage_file.close();
}

// setters and getters for the files
void DatabaseBST::set_file_path(std::string file_name, std::string file_path) {
    if (file_name == "storage.txt") {
        storage_file_path = file_path;
    } else {
        data_file_path = file_path;
    }
}

std::string DatabaseBST::get_file_path(std::string file_name) {
    if (file_name == "storage.txt") {
        return storage_file_path;
    } else {
        return data_file_path;
    }
}

void DatabaseBST::ExpandFreeSpace() {
    for (int i = 0; i < 20; i++)
    {
        free_spots.insert(std::pair<int, bool>(i, false));
    }

    total_spots += 20;
}

// serializing the data into the storage file
void DatabaseBST::Serialize(Node *root, FILE *fp) {
    if (root == NULL)
    {
        fprintf(fp, "%s ", marker.c_str());
        return;
    }

    std::string storage_input = "";

    std::array<char, 16> hash_arr = ConvHashToStr(root->hash);
    for (auto i : hash_arr)
    {
        if (i == '$')
        {
            storage_input += "$";
        }
        else
        {
            storage_input += std::string(1, i);
        }
    }

    for (auto i : root->key)
    {
        if (i == '$')
        {
            storage_input += "$";
        }
        else
        {
            storage_input += std::string(1, i);
        }
    }

    for (auto i : root->value)
    {
        if (i == '$')
        {
            storage_input += "$";
        }
        else
        {
            storage_input += std::string(1, i);
        }
    }

    fprintf(fp, "%s ", storage_input.c_str());
    Serialize(root->left, fp);
    Serialize(root->right, fp);
}

// recreating the BST from the storage file
void DatabaseBST::Deserialize(Node *&curr_node, FILE *fp) {
    char val[80];
    std::vector<char> key(32, '$');
    std::vector<char> value(32, '$');

    if (!fscanf(fp, "%s ", val) || std::string(val) == "#")
        return;

    // std::cout << val << std::endl;

    unsigned long hash = 0;
    std::vector<char> hash_vec;
    int key_idx = 0;
    int value_idx = 0;
    for (int i = 0; i < 80; i++)
    {
        if (i >= 0 && i < 16 && val[i] != '$')
        {
            hash_vec.push_back(val[i]);
        }
        else if (i >= 16 && i < 48)
        {
            key[key_idx] = val[i];
            key_idx += 1;
        }
        else
        {
            value[value_idx] = val[i];
            value_idx += 1;
        }
    }

    std::string hash_str = std::string(std::begin(hash_vec), std::end(hash_vec));
    hash = stoul(hash_str);
    int spot_idx = FindFreeSpace();
    // std::cout << "The spot idx is " << std::to_string(spot_idx) << std::endl;

    curr_node = Insert(get_root(), hash, key, value, spot_idx * 80);
    Deserialize(curr_node->left, fp);
    Deserialize(curr_node->right, fp);
}

// setter ang getter for the root node of the BST
void DatabaseBST::set_root(Node *node) {
    root = node;
}

Node* DatabaseBST::get_root() {
    return root;
}

// this finds an open spot starting from the beginning of the file
int DatabaseBST::FindFreeSpace()
{
    for (auto p : free_spots)
    {
        if (p.second == true)
        {
            free_spots.at(p.first) = false;
            return p.first;
        }
    }

    // if we get to this point, that means that we ran out of free spots
    // and we need to expand
    int old_total_spots = total_spots;
    ExpandFreeSpace();
    return old_total_spots;
}

std::array<char, 16> DatabaseBST::ConvHashToStr(unsigned long hash)
{
    std::string hash_str = std::to_string(hash);
    std::array<char, 16> hash_arr;
    hash_arr.fill('$');
    for (int i = 0; i < (int)hash_str.length(); i++)
    {
        hash_arr[i] = (char)hash_str[i];
    }

    return hash_arr;
}

// inserting the entry into the data file
void DatabaseBST::InsertDataFile(unsigned long hash, std::vector<char> key, std::vector<char> value, int starting)
{
    std::fstream myfile(data_file_path, std::ios::in | std::ios::out);
    myfile.seekg(starting, std::ios::beg);
    std::array<char, 16> hash_arr = ConvHashToStr(hash);

    for (int i = 0; i < 16; i++)
    {
        myfile << hash_arr[i];
    }

    for (int i = 0; i < 32; i++)
    {
        myfile << key[i];
    }

    for (int i = 0; i < 32; i++)
    {
        myfile << value[i];
    }

    myfile.close();
}

// deleting the entry from the data file using the offset
void DatabaseBST::DeleteDataFile(int offset)
{
    std::fstream myfile(data_file_path, std::ios::in | std::ios::out);
    myfile.seekg(offset, std::ios::beg);

    for (int i = 0; i < 80; i++)
    {
        myfile << ' ';
    }

    myfile.close();
    std::cout << "About to free up index " << std::to_string(offset / 80) << std::endl;
    std::map<int, bool>::iterator it = free_spots.find(offset / 80);
    if (it != free_spots.end())
        it->second = true;
}

// updating the value char array of the node; this was called from doing a
// put request
void DatabaseBST::Update(struct Node *node, std::vector<char> new_value) {
    node->value.clear();
    for (char i : new_value) {
        node->value.push_back(i);
    }
    UpdateDataFile(node->starting, new_value);
}

// updates how the node is represented in the file
void DatabaseBST::UpdateDataFile(int offset, std::vector<char> new_value)
{
    std::fstream myfile(data_file_path, std::ios::in | std::ios::out);
    // we need to add an extra 48 since we want to skip the hash (which is 16 bytes) and the
    // the key (which is 32 bytes)
    myfile.seekg(offset+48, std::ios::beg);

    for (int i = 0; i < 32; i++)
    {
        myfile << new_value[i];
    }

    myfile.close();
}

struct Node* DatabaseBST::SearchNode(struct Node *root, unsigned long hash)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->hash == hash)
    {
        return root;
    }
    if (root->hash < hash)
    {
        return SearchNode(root->right, hash);
    }

    else
    {
        return SearchNode(root->left, hash);
    }
}

struct Node* DatabaseBST::Insert(struct Node *node, unsigned long hash, std::vector<char> key, std::vector<char> value, int starting)
{
    if (node == NULL)
    {
        Node* new_root= new Node(hash, key, value, NULL, NULL, starting);
        InsertDataFile(hash, key, value, starting);
        std::map<int, bool>::iterator it = free_spots.find(starting / 80);
        if (it != free_spots.end())
            it->second = false;
        return new_root;
    }

    if (hash < node->hash)
    {
        node->left = Insert(node->left, hash, key, value, starting);
    }
    else
    {
        node->right = Insert(node->right, hash, key, value, starting);
    }
    return node;
}

// this method gets called whenever we delete a node with two children nodes
struct Node* DatabaseBST::FindInOrdSucc(struct Node *curr_node)
{
    while (curr_node && curr_node->left != NULL)
    {
        curr_node = curr_node->left;
    }

    // by this point, we must be at the left most leaf
    // which should be the inorder successor
    return curr_node;
}

struct Node* DatabaseBST::Delete(struct Node *root, unsigned long hash)
{
    if (!root)
    {
        return root;
    }

    if (hash < root->hash)
    {
        root->left = Delete(root->left, hash);
    }
    else if (hash > root->hash)
    {
        root->right = Delete(root->right, hash);
    }
    else
    {
        // this is the case where we found the node with the target hash

        // check if the left child is null
        if (root->left == NULL)
        {
            struct Node *tmp = root->right;
            unsigned long the_offset = root->starting;
            DeleteDataFile(the_offset);
            free(root);
            return tmp;
        }
        else if (root->right == NULL)
        {
            struct Node *tmp = root->left;
            unsigned long the_offset = root->starting;
            DeleteDataFile(the_offset);
            free(root);
            return tmp;
        }

        // by here, it means that the node has two children
        struct Node *tmp = FindInOrdSucc(root->right);

        root->hash = tmp->hash;
        root->right = Delete(root->right, tmp->hash);
    }

    return root;
}

std::string DatabaseBST::ConvertToStr(std::vector<char> data)
{
    std::string s = "";
    for (int i = 0; i < (int)data.size(); i++)
    {
        if (data[i] != '$') {
            s += data[i];
        }
    }

    return s;
}

void DatabaseBST::Inorder(Node *root)
{
    if (!root)
    {
        return;
    }
    Inorder(root->left);
    std::cout << root->hash << std::endl;
    Inorder(root->right);
}

// some helper functions
void DatabaseBST::IncrTotalSpots()
{
    total_spots += 1;
}

void DatabaseBST::DecrTotalSpots()
{
    total_spots -= 1;
}



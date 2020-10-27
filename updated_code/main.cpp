#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <map>
#include <sstream>
#include <algorithm>
#include <string>

int GetFileSize(std::string file_name)
{
    std::ifstream in_file(file_name);
    in_file.seekg(0, std::ios::end);
    int file_size = in_file.tellg();
    in_file.close();
    return file_size;
}

struct Node
{

    Node(unsigned long hash, std::array<char, 32> key, std::array<char, 32> value, Node *left, Node *right, int starting)
    {
        this->hash = hash;
        this->key = key;
        this->value = value;
        this->left = left;
        this->right = right;
        this->starting = starting;
    }

    // total 80
    unsigned long hash;         // 16
    std::array<char, 32> key;   // 32
    std::array<char, 32> value; // 32
    Node *left;
    Node *right;
    int starting;
};

class Database
{
public:
    Node *root;

    Database()
    {
        total_spots = 20;
        for (int i = 0; i < 20; i++)
        {
            free_spots[i] = true;
        }
        root = NULL;
        marker = "#";

        CreateDataFile();
    }

    void CreateDataFile()
    {
        std::ofstream myfile("data.txt", std::ios::app);
        myfile.close();
    }

    void ExpandFreeSpace()
    {
        for (int i = 0; i < 20; i++)
        {
            free_spots.insert(std::pair<int, bool>(i, false));
        }

        total_spots += 20;
    }

    void Serialize(Node *root, FILE *fp)
    {
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

    void Deserialize(Node *&curr_node, FILE *fp, int file_size)
    {
        char val[80];
        std::array<char, 32> key;
        std::array<char, 32> value;
        key.fill('$');
        value.fill('$');

        if (!fscanf(fp, "%s ", val) || std::string(val) == "#")
            return;

        // std::cout << val << std::endl;

        unsigned long hash = 0;
        std::array<char, 16> hash_arr;
        hash_arr.fill('$');
        int key_idx = 0;
        int value_idx = 0;
        for (int i = 0; i < 80; i++)
        {
            if (i >= 0 && i < 16)
            {
                hash_arr[i] = val[i];
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

        std::string hash_str = std::string(std::begin(hash_arr), std::end(hash_arr));
        std::stringstream ss(hash_str);
        int hash_int = 0;
        ss >> hash_int;
        hash = (unsigned long)hash_int;
        int spot_idx = FindFreeSpace();
        // std::cout << "The spot idx is " << std::to_string(spot_idx) << std::endl;

        curr_node = Insert(get_root(), hash, key, value, spot_idx * 80);
        Deserialize(curr_node->left, fp, file_size);
        Deserialize(curr_node->right, fp, file_size);
    }

    void set_root(Node *node)
    {
        root = node;
    }

    Node *get_root()
    {
        return root;
    }

    // this finds an open spot starting from the beginning of the file
    int FindFreeSpace()
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

    std::array<char, 16> ConvHashToStr(unsigned long hash)
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

    void InsertDataFile(unsigned long hash, std::array<char, 32> key, std::array<char, 32> value, int starting)
    {
        std::fstream myfile("data.txt", std::ios::in | std::ios::out);
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

    void DeleteDataFile(int offset)
    {
        std::fstream myfile("data.txt", std::ios::in | std::ios::out);
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

    struct Node *SearchNode(struct Node *root, unsigned long hash)
    {
        if (root == NULL)
        {
            std::cout << "Didn't find in database" << std::endl;
            return root;
        }
        if (root->hash == hash)
        {
            std::cout << "Info found in database" << std::endl;
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

    struct Node *Insert(struct Node *node, unsigned long hash, std::array<char, 32> key, std::array<char, 32> value, int starting)
    {
        if (node == NULL)
        {
            Node *new_root = new Node(hash, key, value, NULL, NULL, starting);
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

    struct Node *FindInOrdSucc(struct Node *curr_node)
    {
        while (curr_node && curr_node->left != NULL)
        {
            curr_node = curr_node->left;
        }

        // by this point, we must be at the left most leaf
        return curr_node;
    }

    struct Node *Delete(struct Node *root, unsigned long hash)
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

    std::string convertToStr(Node *tempNode, int size)
    {
        std::string s = "";
        for (int i = 0; i < size; i++)
        {
            s += tempNode->value[i];
        }

        s.erase(remove(s.begin(), s.end(), '$'), s.end());

        return s;
    }

    void Inorder(Node *root)
    {
        if (!root)
        {
            return;
        }
        Inorder(root->left);
        std::cout << root->hash << std::endl;
        Inorder(root->right);
    }

    void IncrTotalSpots()
    {
        total_spots += 1;
    }

    void DecrTotalSpots()
    {
        total_spots -= 1;
    }

private:
    std::vector<std::string> data_vec;

    // the key is an int to represent the index
    // the value is a bool to represent whether that spot in the vector is free
    std::map<int, bool> free_spots;
    int total_spots;

    std::string marker; // this is a marker for the serialization of the binary tree; it indicates if the node is NULL
};

unsigned long CreateHash(std::string s)
{
    unsigned long hash = 5381;

    for (int i = 0; i < (int)s.length(); i++)
    {
        hash = ((hash << 5) + hash) + (unsigned long)s[i];
    }

    return hash;
}

int main()
{

    Database *db = new Database();

    FILE *fp = fopen("storage.txt", "r");

    Node *tmp_root = db->get_root();

    int size_storage = GetFileSize("storage.txt");

    if (size_storage)
    {
        std::cout << "Rebuilding the BST" << std::endl;
        db->Deserialize(tmp_root, fp, GetFileSize("storage.txt"));
        db->set_root(tmp_root);
    }

    std::string data_file = "data.txt";
    std::fstream streamer(data_file, std::ios::in | std::ios::out);

    std::array<char, 32> key_arr;
    std::array<char, 32> value_arr;

    key_arr.fill('$');
    value_arr.fill('$');

    std::string user_input_key;
    std::string user_input_value;
    unsigned long hash;

    while (true)
    {

        int option = 0;
        std::cout << "Choose your option" << std::endl;
        std::cout << "Option 1: Insert(1)" << std::endl;
        std::cout << "Option 2: Search(2)" << std::endl;
        std::cout << "Option 3: Delete(3)" << std::endl;
        std::cout << "Option 4: Exit(4)" << std::endl;
        std::cin >> option;

        if (option == 1)
        {
            std::cout << "Input a key" << std::endl;
            std::cin >> user_input_key;

            std::cout << "Input a value" << std::endl;
            std::cin >> user_input_value;

            for (int i = 0; i < (int)user_input_key.size(); i++)
            {
                key_arr[i] = user_input_key[i];
            }
            for (int i = 0; i < (int)user_input_value.size(); i++)
            {
                value_arr[i] = user_input_value[i];
            }

            hash = CreateHash(user_input_key);
            std::cout << hash << std::endl;

            int spot_idx = db->FindFreeSpace();
            std::cout << "The spot idx is " << std::to_string(spot_idx) << std::endl;
            db->set_root(db->Insert(db->get_root(), hash, key_arr, value_arr, spot_idx * 80));

            std::cout << "Size of the file is " << std::to_string(GetFileSize("data.txt")) << " bytes\n";
        }

        if (option == 2)
        {
            // db->Inorder(db->get_root());
            std::cout << "Input a key to search for" << std::endl;
            std::cin >> user_input_key;
            hash = CreateHash(user_input_key);
            // std::cout << hash << std::endl;
            Node *temp_root = db->get_root();
            Node *tempNode = db->SearchNode(temp_root, hash);
            std::string value = "";
            db->IncrTotalSpots();

            if (tempNode != NULL)
            {
                int size = (sizeof(tempNode->value) / sizeof(char));
                value = db->convertToStr(tempNode, size);
                std::cout << "The corresponding value is " + value << std::endl;
            }
        }

        if (option == 3)
        {
            Node *temp_root = db->get_root();
            db->DecrTotalSpots();
            db->Inorder(db->get_root());
            std::cout << "Input a key to delete" << std::endl;
            std::cin >> user_input_key;
            hash = CreateHash(user_input_key);
            db->set_root(db->Delete(temp_root, hash));
        }

        if (option == 4)
        {
            FILE *fp = fopen("storage.txt", "w");
            if (fp == NULL)
            {
                puts("Could not open the file");
            }

            std::ofstream myfile;
            myfile.open("data.txt", std::ofstream::out | std::ofstream::trunc);
            myfile.close();

            std::cout << "Saving data to the storage file." << std::endl;
            db->Serialize(db->get_root(), fp);
            std::cout << "All done. Closing off.";
            fclose(fp);

            return 0;
        }
    }

    return 0;
}
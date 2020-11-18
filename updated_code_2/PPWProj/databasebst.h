#ifndef DATABASEBST_H
#define DATABASEBST_H
#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <map>
#include <sstream>
#include <algorithm>
#include <string>
#include <QString>

struct Response {
    bool successful;
    QString body_info;
    Response() {}
    Response(bool successful, QString body_info):
        successful(successful),
        body_info(body_info) {}
};

struct Node
{

    Node(unsigned long hash, std::vector<char> key, std::vector<char> value, Node *left, Node *right, int starting)
    {
        this->hash = hash;
        this->key = key;
        this->value = value;
        this->left = left;
        this->right = right;
        this->starting = starting;
    }

    // total 80
    unsigned long hash;      // 16
    std::vector<char> key;   // 32
    std::vector<char> value; // 32
    Node *left;
    Node *right;
    int starting;
};

// this is where the logic of querying in the database occurs
// we use a BST data structure to handle all of the necessary requests
// that would call its corresponding BST operation (i.e. a GET request
// would call the Search() method of the BST)
class DatabaseBST
{
public:
    Node *root;

    DatabaseBST();
    ~DatabaseBST();
    void DestroyBST(struct Node* node);
    unsigned long CreateHash(std::string s);
    void CreateDataFiles();
    void set_file_path(std::string file_name, std::string file_path);
    std::string get_file_path(std::string file_name);
    void ExpandFreeSpace();
    void Serialize(Node *root, FILE *fp);
    void Deserialize(Node *&curr_node, FILE *fp);
    void set_root(Node *node);
    Node *get_root();
    int FindFreeSpace();
    std::array<char, 16> ConvHashToStr(unsigned long hash);
    void InsertDataFile(unsigned long hash, std::vector<char> key, std::vector<char> value, int starting);
    void DeleteDataFile(int offset);
    void Update(struct Node *node, std::vector<char> new_value);
    void UpdateDataFile(int offset, std::vector<char> new_value);
    struct Node *SearchNode(struct Node *root, unsigned long hash);
    struct Node *Insert(struct Node *node, unsigned long hash, std::vector<char> key, std::vector<char> value, int starting);
    struct Node *FindInOrdSucc(struct Node *curr_node);
    struct Node *Delete(struct Node *root, unsigned long hash);
    std::string convertToStr(Node *tempNode, int size);
    void Inorder(Node *root);
    void IncrTotalSpots();
    void DecrTotalSpots();
private:
    // the key is an int to represent the index
    // the value is a bool to represent whether that spot in the vector is free
    std::map<int, bool> free_spots;
    int total_spots;

    std::string data_file_path;
    std::string storage_file_path;

    std::string marker; // this is a marker for the serialization of the binary tree; it indicates if the node is NULL
};

#endif // DATABASEBST_H

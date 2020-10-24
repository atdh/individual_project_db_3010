#ifndef BTreeNode_H
#define BTreeNode_H
#include <iostream>
#include <string>
#include <array>
#include <map>
#include <memory>

struct UserInfo
{
    int id;
    std::string username;
    std::string password;
};

class BTreeNode
{
public:
    BTreeNode(int _t, bool _leaf);
    void set_key(int idx, unsigned long value);
    int get_key(int idx);
    void set_child(int idx, std::unique_ptr<BTreeNode> C);
    void set_curr_num_keys(int n);
    int get_curr_num_keys();

    void splitChild(int idx, std::unique_ptr<BTreeNode> C);
    void insertNonFull(unsigned long k);

    void traverse();
    BTreeNode *search(unsigned long k);

    int get_t();
    bool get_is_leaf();

    void print_keys();

private:
    int curr_num_keys;
    std::array<unsigned long, 13> keys; // the keys are hashes of the keys
    std::array<std::unique_ptr<BTreeNode>, 14> C;
    UserInfo ui;
    int t;
    bool is_leaf = false;

    friend class BTree;
};

#endif // BTREENODE_H

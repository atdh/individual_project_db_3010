#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <databasebst.h>
#include <logininterface.h>

std::map<std::string, std::string> LoginInterface::table;
std::unordered_set<std::string> LoginInterface::admin_set;
bool LoginInterface::user_is_admin = false;
std::string LoginInterface::username = "";
std::string LoginInterface::password = "";

TEST_CASE( "Database Functionality", "[db]" ) {
    DatabaseBST db;
    Node *tmp_root = db.get_root();

    // inserting the first node (the root)
    REQUIRE(tmp_root == nullptr);

    unsigned long test_hash = 10;
    std::vector<char> test_key{'k','e','y'};
    std::vector<char> test_val{'v', 'a', 'l'};
    int test_offset = 0;
    tmp_root = db.Insert(tmp_root, test_hash, test_key, test_val, test_offset);

    REQUIRE(tmp_root != nullptr);

    // inserting another node
    // we haven't inserted any other nodes yet so the left and right child of the root
    // should be null
    REQUIRE(tmp_root->left == nullptr);
    REQUIRE(tmp_root->right == nullptr);

    unsigned long old_root_hash = tmp_root->hash;
    std::vector<char> old_root_key = tmp_root->key;
    std::vector<char> old_root_val = tmp_root->value;
    int old_root_offset = tmp_root->starting;

    unsigned long test_hash_2 = 5;
    std::vector<char> test_key_2{'k','e','y','2'};
    std::vector<char> test_val_2{'v', 'a', 'l','2'};
    int test_offset_2 = 1;
    tmp_root = db.Insert(tmp_root, test_hash_2, test_key_2, test_val_2, test_offset_2);

    // inserting a new node shouldn't change the root or make it null
    REQUIRE(tmp_root != nullptr);
    REQUIRE(tmp_root->hash == old_root_hash);
    REQUIRE(tmp_root->key == old_root_key);
    REQUIRE(tmp_root->value == old_root_val);
    REQUIRE(tmp_root->starting == old_root_offset);

    // we just inserted a left child of the root (since 5 is less than 10, the root)
    // so let's check that it's not null
    REQUIRE(tmp_root->left != nullptr);

    // searching for a valid node
    Node* tmp_node = db.SearchNode(tmp_root, test_hash);
    REQUIRE(tmp_node != nullptr);

    // searching for an invalid node
    tmp_node = db.SearchNode(tmp_root, 40);
    REQUIRE(tmp_node == nullptr);

    // deleting a node
    tmp_root = db.Delete(tmp_root, test_hash);

    // we just deleted the root so the new root should be 5 (the left child of the old root)
    REQUIRE(tmp_root->hash == 5);
}

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <databasebst.h>
#include <logininterface.h>
#include <map>

std::map<std::string, std::string> LoginInterface::table;
std::unordered_set<std::string> LoginInterface::admin_set;
bool LoginInterface::user_is_admin = false;
std::string LoginInterface::username = "";
std::string LoginInterface::password = "";



//Testing updating the data base
TEST_CASE("Testing Database update", "[db]"){

    DatabaseBST db2;
    Node *tmp_root2 = db2.get_root();

    //If there is no nodes then insert in the root
    REQUIRE(tmp_root2 == nullptr);
    unsigned long hash1 = 10;
    std::vector<char> key1{'a','t','u','l'};
    std::vector<char> val1{'d','h','u','n','g','e','l'};
    int offset1 = 0;
    tmp_root2 = db2.Insert(tmp_root2, hash1, key1, val1, offset1);

    //We have one value already added so tmp_roor2 should not be a null ptr cus theres already a root node
    REQUIRE(tmp_root2 != nullptr);
    //check to see if there is left and right child. It should both be null
    REQUIRE(tmp_root2->left == nullptr);
    REQUIRE(tmp_root2->right == nullptr);

    unsigned long hash2=15;
    unsigned long old_root_hash = tmp_root2->hash;
    std::vector<char>old_root_key = tmp_root2->key;
    std::vector<char>old_root_val = tmp_root2->value;
    int old_root_offset = tmp_root2->starting;

    std::vector<char>key2{'a','t','u','l','2'};
    std::vector<char>val2{'d','h','u','n','g','e','l','2'};
    int offset2 = 1;
    tmp_root2 = db2.Insert(tmp_root2, hash2, key2, val2, offset2);
    //currently I have head and left tree
    //Now I want to update left tree value with difft value
    std::vector<char>val3{'d','h','u','n','g','e','l','1','3'};

    //currently tmp_root is point at head
    REQUIRE(tmp_root2->value == val1);
    //updating with new value
    db2.Update(tmp_root2,val3);
    //should point to val3 now
    REQUIRE(tmp_root2->value == val3);
}


TEST_CASE("Testing Database insertion,search,delete", "[db]"){
    DatabaseBST db2;
    Node *tmp_root2 = db2.get_root();

    //If there is no nodes then insert in the root
    REQUIRE(tmp_root2 == nullptr);
    unsigned long hash1 = 10;
    std::vector<char> key1{'a','t','u','l'};
    std::vector<char> val1{'d','h','u','n','g','e','l'};
    int offset1 = 0;
    tmp_root2 = db2.Insert(tmp_root2, hash1, key1, val1, offset1);

    //We have one value already added so tmp_roor2 should not be a null ptr cus theres already a root node
    REQUIRE(tmp_root2 != nullptr);
    //check to see if there is left and right child. It should both be null
    REQUIRE(tmp_root2->left == nullptr);
    REQUIRE(tmp_root2->right == nullptr);

    unsigned long hash2=15;
    unsigned long old_root_hash = tmp_root2->hash;
    std::vector<char>old_root_key = tmp_root2->key;
    std::vector<char>old_root_val = tmp_root2->value;
    int old_root_offset = tmp_root2->starting;

    std::vector<char>key2{'a','t','u','l','2'};
    std::vector<char>val2{'d','h','u','n','g','e','l','2'};
    int offset2 = 1;
    tmp_root2 = db2.Insert(tmp_root2, hash2, key2, val2, offset2);

    //root shouldnt be changed from the last one
    REQUIRE(tmp_root2 != nullptr);
    REQUIRE(tmp_root2->hash == old_root_hash);
    REQUIRE(tmp_root2->key == old_root_key);
    REQUIRE(tmp_root2->value == old_root_val);
    REQUIRE(tmp_root2->starting == old_root_offset);

    // we just inserted a right child of the root (since 15> 10, the root)
    // so let's check that it's not null
    REQUIRE(tmp_root2->right != nullptr);
    //left child should be null
    REQUIRE(tmp_root2->left == nullptr);

    //now we add to left child
    unsigned long hash3=12;
    unsigned long old_root_hash2 = tmp_root2->hash;
    std::vector<char>old_root_key2 = tmp_root2->key;
    std::vector<char>old_root_val2 = tmp_root2->value;
    int old_root_offset2 = tmp_root2->starting;

    //right now it should be0 because we just initialized it
    REQUIRE(tmp_root2->starting == 0);
    std::vector<char>key3{'a','t','u','l','2','3'};
    std::vector<char>val3{'d','h','u','n','g','e','l','2','3'};
    int offset3 = 2;

    //REQUIRE(tmp_root2->starting == 1);

    REQUIRE(tmp_root2 != nullptr);
    REQUIRE(tmp_root2->hash == old_root_hash2);
    REQUIRE(tmp_root2->key == old_root_key2);
    REQUIRE(tmp_root2->value == old_root_val2);
    REQUIRE(tmp_root2->starting == old_root_offset2);

    tmp_root2 = db2.Insert(tmp_root2, hash3, key3, val3, offset3);

    REQUIRE(tmp_root2->right != nullptr);
    //REQUIRE(tmp_root2->left != nullptr);

    // searching for a valid node
    Node* tmp_node = db2.SearchNode(tmp_root2, hash3);
    REQUIRE(tmp_node != nullptr);
    //deleting a node
    Node *tmp_node2 = db2.Delete(tmp_root2,hash3);
    REQUIRE(tmp_root2->hash != hash3);

    //update
    /*
     *void DatabaseBST::Update(struct Node *node, std::vector<char> new_value)
    */

   //unsigned long hash4=13;//
    //unsigned long old_root_hash3 = tmp_root2->hash;//
    std::vector<char>old_root_key3 = tmp_root2->key;
    std::vector<char>old_root_val3 = tmp_root2->value;
    //int old_root_offset3 = tmp_root2->starting;//

    //right now it should be0 because we just initialized it
    //REQUIRE(tmp_root2->starting == 0);
    std::vector<char>key4{'a','t','u','l','2','8'};
    std::vector<char>val4{'d','h','u','n','g','e','l','1','3'};
    //int offset4 = 3;//
    //REQUIRE(tmp_node2->value == val3);
    db2.Update(tmp_node2,val4);
    REQUIRE(tmp_node2->value==val4);

}

//testing the entire search,delete,insert,update. Everything works
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


    //update
    std::vector<char> test_val_3{'v', 'a', 'l','2'};
    REQUIRE(tmp_root->value == test_val_2);
    db.Update(tmp_root,test_val_2);
    REQUIRE(tmp_root->value == test_val_3);

    //find in order successor


}

TEST_CASE("testing authentication","[auth]"){
    LoginInterface auth;
    LoginResp login_resp;

    auth.ReadFile();
    //table should be initially empty
    REQUIRE(auth.table.empty());

    //login given username and password
    auth.Login("test1","test2");

    //shoudl return false because havent signed up yet
    REQUIRE(login_resp.succ);
    //should not be admin
    REQUIRE(login_resp.is_admin);

    //REQUIRE (login_resp.body_info[0]=="true");

    auth.DeleteUserFromFile("test1");
    //REQUIRE(auth.table.find("test1"));

}

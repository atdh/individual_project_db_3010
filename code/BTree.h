#ifndef BTree_H
#define BTree_H
#include <iostream>
#include <string>
#include <array>
#include "BTreeNode.h"
#include <memory>

class BTree 
{ 
	int t = 8; 
    public: 
        std::unique_ptr<BTreeNode> root;
        std::string location_root_file;

        int num_index_files = 0;

        BTree(int _t) 
        { root = NULL; t = _t; } 

        void traverse() 
        { if (root != NULL) root->traverse(); } 

        BTreeNode* search(int k) 
        { return (root == NULL)? NULL : root->search(k); } 

        void insert(unsigned long k); 

        void remove(int k);

        void CreateFile();
}; 

#endif // BTREE_H

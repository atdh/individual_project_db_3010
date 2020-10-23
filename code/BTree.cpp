#include "BTree.h"
#include "BTreeNode.h"
#include <string>
#include <memory>
#include <fstream>

void BTree::CreateFile() {

    std::string filename= "index_file_0.txt";
    std::ofstream fout(filename);
    fout.fill (' ');
    fout.width (500);
    fout << " ";

    return;
}

void BTree::insert(unsigned long k) {

    // case where we still need to make our first insertion 
    // in other words, when root = NULL

    if (root == NULL) {
        std::unique_ptr<BTreeNode> new_root(new BTreeNode(t, true));
        root = move(new_root);
        root->set_key(0, k);
        root->set_curr_num_keys(1);

        this->CreateFile();
        std::ofstream outfile;
        outfile << k;
        this->location_root_file = "index_file_0.txt";
        outfile.open(this->location_root_file, std::ios::app);
        std::string data_loc = "testFile.txt";

        std::array<char, 32> data_loc_arr = {0};
        
        for (int i = 0; i < (int)data_loc.size(); i++) {
            data_loc_arr[i] = data_loc[i];
        }

        for (int i = 0; i < 32; i++) {
            outfile << data_loc_arr[i];
        }

        outfile.close();
    } else {

        // the case where the root is full, then the tree must grow in height
        // note: the b-tree grows bottom up
        if (root->get_curr_num_keys() == 2*t-1) {
            std::unique_ptr<BTreeNode> new_root(new BTreeNode(t, false));

            // we need to make the current old root a child of the new root
            new_root->set_child(0, move(root));

            // we need to split the child; move one of the keys to the new root node
            new_root->splitChild(0, move(root));

            // the new root has two children now
            // now, we need to choose the proper child to hold the new key 
            // so, we just iterate through the list of children (really it's just one child) to see if the
            // new key should be placed in the left or right child

            // we probably set what new_root->keys[0] is during the splitChild() method
            // if the new key is greater than the new_root's key, then we put the new key
            // in the right child of the new_root; otherwise, we put the new key
            // in the left child of the new_root
            if (new_root->get_key(0) < k) {
                new_root->C[1]->insertNonFull(k);
            } else {
                new_root->C[0]->insertNonFull(k);
            }

            // finally, we update the root
            root = move(new_root);
        } else {
            // if the root is not full, call insertNonFull for the root
            root->insertNonFull(k);
        }
    }

    root->print_keys();
}


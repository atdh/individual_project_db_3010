#include "BTreeNode.h"
#include <string>
#include <map>
#include <fstream>
#include <memory>

BTreeNode::BTreeNode(int _t, bool _leaf) {
    t = _t;
    is_leaf = _leaf;

    keys = {};
    C = {}; 

    curr_num_keys = 0;
}

void BTreeNode::print_keys() {
    for (auto k : keys) {
        std::cout << k << std::endl;
    }
}

void BTreeNode::set_key(int idx, unsigned long value) {
    this->keys[idx] = value;
}

int BTreeNode::get_key(int idx) {
    return this->keys[idx];
}

void BTreeNode::set_child(int idx, std::unique_ptr<BTreeNode> new_C) {
    this->C[idx] = move(new_C);
}

void BTreeNode::set_curr_num_keys(int n) {
    this->curr_num_keys = n;
}

int BTreeNode::get_curr_num_keys() {
    return this->curr_num_keys;
}

int BTreeNode::get_t() {
    return this->t;
}

bool BTreeNode::get_is_leaf() {
    return this->is_leaf;
}

// this is a helper function to split the child of y of this node
// we must assume that y is full when this was called
void BTreeNode::splitChild(int i, std::unique_ptr<BTreeNode> y) {
    // we need to create a node that will store t-1 keys of y
    std::unique_ptr<BTreeNode> z(new BTreeNode(y->get_t(), y->get_is_leaf()));
    z->set_curr_num_keys(this->get_t()-1);

    // we copy the last (t-1) keys of y to z
    for (int j = 0; j < t-1; j++) {
        z->keys[j] = y->keys[j+t];
    }

    // copy the last t children of y to z
    if (y->get_is_leaf() == false) {
        for (int j = 0; j < t; j++) {
            z->set_child(j, move(y->C[j+t]));
        }
    }

    // we need to remember to reduce the number of keys in y
    y->set_curr_num_keys(t-1);

    // since this node is going to have a new child,
    // create space of new child
    for (int j = this->get_curr_num_keys(); j >= i+1; j--) {
        this->set_child(j+1, move(C[j]));
    }

    // link the new child to this node
    this->set_child(i+1, move(z));

    // a key of y will move to this node. find the location of the new key and move all greater keys
    // one space ahead
    for (int j = this->get_curr_num_keys()-1; j >= i; j--) {
        keys[j+1] = keys[j];
    }

    // copy the middle key of y to this node
    keys[i] = y->keys[t-1];

    // increment count of keys in this node
    this->set_curr_num_keys(this->get_curr_num_keys()+1);
}

void BTreeNode::insertNonFull(unsigned long k) {
    // initialize index as the index of the rightmost element
    // it will EVENTUALLY be the index where we insert the new key
    int i = this->get_curr_num_keys()-1;

    int file_idx = (this->get_curr_num_keys()*73)-73;

    if (this->get_is_leaf() == true) {
        // finds the location of new key to be inserted
        // and it also moves all greater keys to one place ahead
        while (i >= 0 && keys[i] > k) {
            keys[i+1] = keys[i];
            i--;
        }

        // then we insert the new key at the found location
        keys[i+1] = k;
        this->set_curr_num_keys(this->get_curr_num_keys()+1);
    } else {

        // first, we need to find the child which going to have the new key
        while (i >= 0 && keys[i] > k) {
            i--;
        }

        // if the found child is full then we'll have to split it
        if (C[i+1]->get_curr_num_keys() == 2*t-1) {
            splitChild(i+1, move(C[i+1]));

            // after the split, the middle key of C[i] moves up and 
            // C[i] is splitted into two
            // then we have to see which child is going to have the new key
            if (keys[i+1] < k) {
                i++;
            }
        }

        C[i+1]->insertNonFull(k);
    }
}

void BTreeNode::traverse()
{
    int i;

    // first, we traverse through the keys
    for (i = 0; i < get_curr_num_keys(); i++)
    {
        if (get_is_leaf() == false)
        {
            C[i]->traverse();
        }
        std::cout << " " << keys[i];
    }

    // then, we need to make sure that traverse through the children as well
    if (get_is_leaf() == false)
    {
        C[i]->traverse();
    }
}
BTreeNode *BTreeNode::search(unsigned long k) {
    // first, we iterate through the list of keys to find the first key greater than or equal to k
    // we take advantage of the fact that the nodes in the tree are ordered/structured in a way
    // such that searching for the key takes O(log n)
    // we still need to go through the list of keys of the current node to decide which subtree to 
    // travel down though
    int i = 0;
    while (i < get_curr_num_keys() && k > keys[i]) {
        i++;
    }

    // if the found key is equal to k, then we return the current node
    if (keys[i] == k) {
        return this;
    }

    // if the key is not found here and this is a leaf node, and this means that the key doesn't exist
    // there isn't a need to explore every subtree since the order/structure of the tree should 
    // prevent us from needing to check them all
    if (get_is_leaf() == true) {
        return NULL;
    }

    // if we reach this point, then that means we must continue our search down the subtree, which may or may not have the key
    // we are searching for
    return C[i]->search(k);
}

#include <iostream>
#include <string>

/**
 * Terminology for a B-tree:
 * m, or order = the max number of children a non-leaf node can have
 * t, k, or degree = helps define the max and min number of keys for a node; in this case, it is to indicate the min degree; t = ceil(m/2)
 * 
 * Rules for a B-tree
 * 1. every non-leaf node has at least ceil(m/2) children
 * 2. every node has at most m children, or 2t children
 * 3. each node has at most 2t-1 keys
 * 3. if node is not root, it has at least t-1 keys
 * 4. the root has at least two children if it is not a leaf node
 * 5. all leaves appear in the same level
 */

class BTreeNode {
    private:
        int *keys; // need to keep track of the keys, so we use an array
        int t; // min degree; this specifies the min number of keys and the 
        BTreeNode **C; // to keep track of the children, we use an array (array of pointers)
        int n; // the current number of keys in the node
        bool leaf; // indicating whether the node is a leaf
    
    public:
        BTreeNode(int t, bool leaf);

        // traverse through a subtree starting at this node as the root
        void traverse();

        // traverse through subtree starting at this node as the root
        // returns null if the key isn't found
        BTreeNode *search(int k);

        // the function that actually inserts a new key in the subtree rooted with the node
        // assumption: the node must be non-full when this function is called
        void insertNonFull(int k);

        // function to split the child y of this node
        // i is the index of y in the child array C[]
        // child y must be full when this function is called (because if there's still space in the C[] array to put the node into it then we should just do that)
        void splitChild(int i, BTreeNode *y);

        
        //** the functions below are used for deletion
        
        // returns the index of the first key that is greater or equal to k
        int findKey(int k);

        // removes the key k in the subtree in the current node
        void remove(int k);

        // removes the key present in the idx-th position in this node
        // we assume that this node is a leaf
        void removeFromLeaf(int idx);

        // removes the key present in the idx-th position in this node
        // we assume that this node isn't a leaf
        void removeFromNonLeaf(int idx);

        // gets the predecessor the the key - where the key
        // is present in the idx-th position in the node
        int getPred(int idx);

        // gets the successor of the key - where the key is present
        // in the idx-th position in the node
        int getSucc(int idx);

        // fill up the child node present in the idx-th position the
        // C[] array if that child has less than t-1 keys
        void fill(int idx);

        // take a key from teh C[idx-1]-th node and place it in 
        // it in C[idx]th node
        void borrowFromPrev(int idx);

        // take a key from the C[idx+1]-th node and place it 
        // in C[idx]th node 
        void borrowFromNext(int idx); 

        // merge idx-th child of the node with (idx+1)th child of the
        // node
        void merge(int idx); 

        // make the BTree a friend of this so that the BTree can access the private members of the BTreeNode
    friend class BTree;
};

// A BTree 
class BTree 
{ 
	BTreeNode *root; // Pointer to root node 
	int t; // Minimum degree 
    public: 
        // Constructor (Initializes tree as empty) 
        BTree(int _t) 
        { root = NULL; t = _t; } 

        // function to traverse the tree 
        void traverse() 
        { if (root != NULL) root->traverse(); } 

        // function to search a key in this tree 
        BTreeNode* search(int k) 
        { return (root == NULL)? NULL : root->search(k); } 

        // The main function that inserts a new key in this B-Tree 
        void insert(int k); 

        //** this is for deletion
        void remove(int k);
}; 

// constructor for the BTreeNode
BTreeNode::BTreeNode(int _t, bool _leaf) {
    t = _t;
    leaf = _leaf;

    // need to allocate enough meory to store the max number of keys possible, which is 2t-1
    // do the same for the child pointers
    keys = new int[2*t-1];
    C = new BTreeNode *[2*t]; // an array of pointers to the children BTreeNodes

    n = 0;
}

int BTreeNode::findKey(int k) { 
    int idx=0; 
    while (idx<n && keys[idx] < k) 
        ++idx; 
    return idx; 
} 

void BTreeNode::remove(int k) {
    int idx = findKey(k);

    // this checks to see if the key we want to remove is
    // present in this node
    if (idx < n && keys[idx] == k) {
        if (leaf) {
            removeFromLeaf(idx);
        } else {
            removeFromNonLeaf(idx);
        }
    } else {
        if (leaf) {
            std::cout << "The key " << k << " does not exist in the tree" << std::endl;
            return;
        } 

        // the key to be removed is present in the sub-tree rooted with this node
        // the flag indicates whether the key is present in the sub-tree rooted
        // with the last child of this node
        bool flag = ((idx == n)? true : false);

        // if the child where the key is supposed to exist has less than t keys,
        // we fill that child
        if (C[idx]->n < t) {
            fill(idx);
        }

        // if the last child has been merged, it must have merged with the previous 
        // child and so we recurse on the (idx-1)th child. else, we recurse on the
        // (idx)th child which now has at least t keys
        if (flag && idx > n) {
            C[idx-1]->remove(k);
        } else {
            C[idx]->remove(k);
        }
    }
}

void BTreeNode::fill(int idx) {
    if (idx != 0 && C[idx-1]->n >= t) {
        borrowFromPrev(idx);
    } else if (idx != n && C[idx+1]->n >= t) {
        borrowFromNext(idx);
    } else {
        if (idx != n) 
            merge(idx); 
        else
            merge(idx-1); 
    }

    return;
}

void BTreeNode::borrowFromPrev(int idx) {
    BTreeNode *child = C[idx];
    BTreeNode *sibling = C[idx-1];

    // the last key from C[idx-1] goes up to the parent and key[idx-1]
    // from parent is inserted as the first key in C[idx]. thus, the sibling
    // loses one key and the child gains one key

    // move all keys in C[idx] one spot ahead
    // since we be putting the key (from the parent at key[idx-1])
    // as the first spot in the child's keys
    for (int i = child->n-1; i >= 0; i--) {
        child->keys[i+1] = child->keys[i];
    }

    // if C[idx] is not a leaf, move all its child opitners one step ahead
    if (!child->leaf) {
        for (int i = child->n; i>=0; i++) {
            child->C[i+1] = child->C[i];
        }
    }

    child->keys[0] = keys[idx-1];
    
    // moving sibling's last child as C[idx]'s first child
    if (!child->leaf) {
        child->C[0] = sibling->C[sibling->n];
    }

    // moving the key from the sibling to the parent
    keys[idx-1] = sibling->keys[sibling->n-1];

    // make sure that we update the number of keys in the child and sibling
    child->n += 1;
    sibling->n -= 1;
}

// A function to borrow a key from the C[idx+1] and place 
// it in C[idx] 
void BTreeNode::borrowFromNext(int idx) 
{ 
  
    BTreeNode *child=C[idx]; 
    BTreeNode *sibling=C[idx+1]; 
  
    // keys[idx] is inserted as the last key in C[idx] 
    child->keys[(child->n)] = keys[idx]; 
  
    // Sibling's first child is inserted as the last child 
    // into C[idx] 
    if (!(child->leaf)) 
        child->C[(child->n)+1] = sibling->C[0]; 
  
    //The first key from sibling is inserted into keys[idx] 
    keys[idx] = sibling->keys[0]; 
  
    // Moving all keys in sibling one step behind 
    for (int i=1; i<sibling->n; ++i) 
        sibling->keys[i-1] = sibling->keys[i]; 
  
    // Moving the child pointers one step behind 
    if (!sibling->leaf) 
    { 
        for(int i=1; i<=sibling->n; ++i) 
            sibling->C[i-1] = sibling->C[i]; 
    } 
  
    // Increasing and decreasing the key count of C[idx] and C[idx+1] 
    // respectively 
    child->n += 1; 
    sibling->n -= 1; 
  
    return; 
} 

void BTreeNode::removeFromLeaf(int idx) {
    // Move all the keys after the idx-th pos one place backward 
    for (int i=idx+1; i<n; ++i) 
        keys[i-1] = keys[i]; 
  
    // Reduce the count of keys 
    n--; 
  
    return; 
}

void BTreeNode::removeFromNonLeaf(int idx) {
    int k = keys[idx];

    // if the child that precedes k (C[idx]) has at least t keys
    // find the predecessor 'pred' of k in the subtree rooted at
    // C[idx]. replace k by pred. recursively delete pred
    // in C[idx]
    if (C[idx]->n >= t) {
        int pred = getPred(idx);
        keys[idx] = pred; // we replace the key with its predecessor
        C[idx]->remove(pred);
    } else if (C[idx]->n >= t) {
        // if we can't take a value from the predecessor, then we see if we can take a value
        // from the successor
        int succ = getSucc(idx);
        keys[idx] = succ;
        C[idx+1]->remove(succ);
    } else {
        // this is the case when we can't a value from either the predecessor or the successor
        // so, we merge the child (C[idx]) and sibling (C[idx+1]) of the current node to form a larger child node 
        // the sibling node will be deleted
        merge(idx);

        // the current key that we want to remove was put into the child (C[idx]) from the merge method(), so
        // now we finally remove the key 
        C[idx]->remove(k);
    }

    return;
}

int BTreeNode::getPred(int idx) 
{ 
    // keep moving to the right most node
    // until we reach a leaf; the leaf should be the node
    // that contains the inorder predecessor
    BTreeNode *cur=C[idx]; 
    while (!cur->leaf) 
        cur = cur->C[cur->n]; 
  
    // return the last key of the leaf, which is the inorder predecessor 
    return cur->keys[cur->n-1]; 
} 
  
int BTreeNode::getSucc(int idx) 
{ 
  
    // keep moving the left most node starting from C[idx+1] until we reach a leaf 
    // the leaf should be the node that contains the inorder
    // successor
    BTreeNode *cur = C[idx+1]; 
    while (!cur->leaf) 
        cur = cur->C[0]; 
  
    // return the first key of the leaf, which is the inorder successor
    return cur->keys[0]; 
} 

// this will merge C[idx] with C[idx+1]
// this happens because neither the predecessor nor the
// successor don't have enough keys to take from
// in the future
// C[idx+1] is freed after
// Step 1: we essentially create a node containing the values of the child node, the key (we are going to remove), and the sibling node
// Step 2: then we need to make sure that we shift the keys after idx back one spot
// Step 3: then we need to make sure that we shift the child pointers after (idx+1) back one spot
void BTreeNode::merge(int idx) {
    BTreeNode *child = C[idx];
    BTreeNode *sibling = C[idx+1];

    // pulling a key from the current node and inserting it into (t-1)th
    // position of C[idx]
    child->keys[t-1] = keys[idx];

    // copying the keys from C[idx+1] to C[idx] at the end
    for (int i = 0; i < sibling->n; i++) {
        // we need to remember adding the offset of t
        child->keys[i+t] = sibling->keys[i];
    }

    // copying the child pointers from C[idx+1] to C[idx]
    // this is the case where we essentially decrease the height of the btree
    // by removing the current key
    if (!child->leaf) {
        for (int i = 0; i <= sibling->n; i++) {
            child->C[i+t] = sibling->C[i];
        }
    }

    // moving all keys after idx in the current node one spot back 
    // to fill the gap created by moving keys[idx] to C[idx]
    for (int i = idx+1; i < n; i++) {
        keys[i-1] = keys[i];
    }

    // moving the child pointers after (idx+1) in the current node one
    // spot back
    for (int i = idx+2; i <= n; i++) {
        C[i-1] = C[i];
    }

    // update the key count of child
    child->n += sibling->n+1;

    // update the key count of the current node
    n--;

    // free the memory allocated for the sibling
    delete(sibling);
    return;
}

void BTreeNode::traverse() {
    int i;

    // first, we traverse through the keys 
    for(i = 0; i < n; i++) {
        if (leaf == false) {
            C[i]->traverse();
        }
        std::cout << " " << keys[i];
    }

    // then, we need to make sure that traverse through the children as well
    if (leaf == false) {
        C[i]->traverse();
    }
}

BTreeNode *BTreeNode::search(int k) {
    // first, we iterate through the list of keys to find the first key greater than or equal to k
    // we take advantage of the fact that the nodes in the tree are ordered/structured in a way
    // such that searching for the key takes O(log n)
    // we still need to go through the list of keys of the current node to decide which subtree to 
    // travel down though
    int i = 0;
    while (i < n && k > keys[i]) {
        i++;
    }

    // if the found key is equal to k, then we return the current node
    if (keys[i] == k) {
        return this;
    }

    // if the key is not found here and this is a leaf node, and this means that the key doesn't exist
    // there isn't a need to explore every subtree since the order/structure of the tree should 
    // prevent us from needing to check them all
    if (leaf == true) {
        return NULL;
    }

    // if we reach this point, then that means we must continue our search down the subtree, which may or may not have the key
    // we are searching for
    return C[i]->search(k);
}

void BTree::insert(int k) {

    // case where we still need to make our first insertion 
    // in other words, when root = NULL
    if (root == NULL) {
        root = new BTreeNode(t, true);
        root->keys[0] = k;
        root->n = 1;
    } else {
        // the case where the root is full, then the tree must grow in height
        // note: the b-tree grows bottom up
        if (root->n == 2*t-1) {
            BTreeNode *new_root = new BTreeNode(t, false);

            // we need to make the current old root a child of the new root
            new_root->C[0] = root;

            // we need to split the child; move one of the keys to the new root node
            new_root->splitChild(0, root);

            // the new root has two children noe
            // now, we need to choose the proper child to hold the new key 
            // so, we just iterate through the list of children (really it's just one child) to see if the
            // new key should be placed in the left or right child

            // we probably set what new_root->keys[0] is during the splitChild() method
            // if the new key is greater than the new_root's key, then we put the new key
            // in the right child of the new_root; otherwise, we put the new key
            // in the left child of the new_root
            if (new_root->keys[0] < k) {
                new_root->C[1]->insertNonFull(k);
            } else {
                new_root->C[0]->insertNonFull(k);
            }

            // finally, we update the root
            root = new_root;
        } else {
            // if the root is not full, call insertNonFull for the root
            root->insertNonFull(k);
        }
    }
}

// this is a helper function to split the child of y of this node
// we must assume that y is full when this was called
void BTreeNode::splitChild(int i, BTreeNode *y) {
    // we need to create a node that will store t-1 keys of y
    BTreeNode *z = new BTreeNode(y->t, y->leaf);
    z->n = t-1; // this comes from Rule 3 from the notes way top

    // we copy the last (t-1) keys of y to z
    for (int j = 0; j < t-1; j++) {
        z->keys[j] = y->keys[j+t];
    }

    // copy the last t children of y to z
    if (y->leaf == false) {
        for (int j = 0; j < t; j++) {
           z->C[j] = y->C[j+t];
        }
    }

    // we need to remember to reduce the number of keys in y
    y->n = t - 1;

    // since this node is going to have a new child,
    // create space of new child
    for (int j = n; j >= i+1; j--) {
        C[j+1] = C[j];
    }

    // link the new child to this node
    C[i+1] = z;

    // a key of y will move to this node. find the location of the new key and move all greater keys
    // one space ahead
    for (int j = n-1; j >= i; j--) {
        keys[j+1] = keys[j];
    }

    // copy the middle key of y to this node
    keys[i] = y->keys[t-1];

    // increment count of keys in this node
    n = n + 1;
}

void BTreeNode::insertNonFull(int k) {
    // initialize index as the index of the rightmost element
    // i will EVENTUALLY be the index where we insert the new key
    int i = n-1;

    if (leaf == true) {
        // finds the location of new key to be inserted
        // and it also moves all greater keys to one place ahead
        while (i >= 0 && keys[i] > k) {
            keys[i+1] = keys[i];
            i--;
        }

        // then we insert the new key at the found location
        keys[i+1] = k;
        n += 1;
    } else {

        // first, we need to find the child which going to have the new key
        while (i >= 0 && keys[i] > k) {
            i--;
        }

        // if the found child is full then we'll have to split it
        if (C[i+1]->n == 2*t-1) {
            splitChild(i+1, C[i+1]);

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

int main() {
    BTree t(3); // A B-Tree with minium degree 3 
    t.insert(10); 
    t.insert(20); 
    t.insert(5); 
    t.insert(6); 
    t.insert(12); 
    t.insert(30); 
    t.insert(7); 
    t.insert(17); 
  
    std::cout << "Traversal of the constucted tree is "; 
    t.traverse(); 
  
    int k = 6; 
    (t.search(k) != NULL)? std::cout << "\nPresent" : std::cout << "\nNot Present"; 
  
    k = 15; 
    (t.search(k) != NULL)? std::cout << "\nPresent" : std::cout << "\nNot Present"; 

    std::cout << "\n";
  
    return 0; 
}
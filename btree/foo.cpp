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
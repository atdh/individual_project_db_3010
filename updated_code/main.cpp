#include <iostream>
#include <fstream>
#include <vector>
#include <array>
#include <unordered_map>

struct Node {

    Node (unsigned long hash, std::array<char, 32> key, std::array<char, 32> value, Node* left, Node* right, int starting) {
        this->hash = hash;
        this->key = key;
        this->value = value;
        this->left = left;
        this->right = right;
        this->starting = starting;
    }

    // total 72
    unsigned long hash; // 8
    std::array<char, 32> key; // 32
    std::array<char, 32> value; // 32
    Node* left; 
    Node* right; 
    int starting; 
};

class Database {
    public:
        Node *root;

        Database() {
            total_spots = 20;
            for (int i = 0; i < 20; i++) {
                free_spots[i] = true;
            }

            CreateDataFile();
        }

        void CreateDataFile() {
            std::ofstream myfile("data.txt", std::ios::app);
            myfile.close();
        }

        void ExpandFreeSpace() {
            for (int i = 0; i < 20; i++) {
                free_spots[i+total_spots] = true;
            }

            total_spots += 20;
        }

        // this finds an open spot starting from the beginning of the file
        int FindFreeSpace() {
            for (auto p : free_spots) {
                if (p.second == true) {
                    free_spots[p.first] = false;
                    return p.first;
                }
            }

            // if we get to this point, that means that we ran out of free spots
            // and we need to expand
            ExpandFreeSpace();
        }

        void InsertDataFile(unsigned long hash, std::array<char, 32> key, std::array<char, 32> value, int starting) {
            std::ofstream myfile;
            myfile.open("data.txt", std::ios::app);
            myfile.seekp(starting);
            myfile << hash; // 8

            for (int i = 0; i < 32; i++) {
                myfile << key[i]; 
            }

            for (int i = 0; i < 32; i++) {
                myfile << value[i]; 
            }
            
            myfile.close();
        }

        struct Node* Insert(struct Node* node, unsigned long hash, std::array<char, 32> key, std::array<char, 32> value, int starting) {
             if (node == NULL) {
                Node *new_root = new Node(hash, key , value, NULL, NULL, starting);
                InsertDataFile(hash, key, value, starting);
                return new_root;
             }

             if (hash < node->hash) {
                 node->left = Insert(node->left, hash, key, value, starting);
             } else {
                 node->right = Insert(node->right, hash, key, value, starting);
             }
        }



    private:
        std::vector<std::string> data_vec;

        // the key is an int to represent the index
        // the value is a bool to represent whether that spot in the vector is free
        std::unordered_map<int, bool> free_spots;
        int total_spots;
};

unsigned long CreateHash(std::string s) {
    unsigned long hash = 5381;

    for (int i = 0; i < (int)s.length(); i++) {
        hash = ((hash << 5) + hash) + (unsigned long)s[i]; 
    }

    return hash;
}

int main() {

    Database* db = new Database();
    struct Node* root = NULL;

    std::string data_file = "data.txt";
    std::fstream streamer(data_file, std::ios::in | std::ios::out);


    std::array<char, 32> key_arr = {0};
    std::array<char, 32> value_arr = {0};

    std::string user_input_key;
    std::string user_input_value;
    unsigned long hash;

    for (int i = 0; i < 2; i++) {
        std::cout << "input a key" << std::endl;
        std::cin >> user_input_key;

        std::cout << "input a value" << std::endl;
        std::cin >> user_input_value;

        for (int i = 0; i < (int)user_input_key.size(); i++) {
            key_arr[i] = user_input_key[i];
        }
        for (int i = 0; i < (int)user_input_value.size(); i++) {
            value_arr[i] = user_input_value[i];
        }

        hash = CreateHash(user_input_key);

        int spot_idx = db->FindFreeSpace();
        db->Insert(root, hash, key_arr, value_arr, spot_idx*72);
    }


}
// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <array>
// #include <map>

// int GetFileSize(std::string file_name) { 
//     std::ifstream in_file(file_name);
//     in_file.seekg(0, std::ios::end);
//     int file_size = in_file.tellg();
// //    std::cout<<"Size of the file is"<<" "<< file_size<<" "<<"bytes\n";
//     in_file.close();
//    return file_size;
// }

// struct Node
// {

//     Node(unsigned long hash, std::array<char, 32> key, std::array<char, 32> value, Node *left, Node *right, int starting)
//     {
//         this->hash = hash;
//         this->key = key;
//         this->value = value;
//         this->left = left;
//         this->right = right;
//         this->starting = starting;
//     }

//     // total 80
//     unsigned long hash;         // 16
//     std::array<char, 32> key;   // 32
//     std::array<char, 32> value; // 32
//     Node *left;
//     Node *right;
//     int starting;
// };

// class Database
// {
//     public:
//         Node *root;

//         Database()
//         {
//             total_spots = 20;
//             for (int i = 0; i < 20; i++)
//             {
//                 free_spots[i] = true;
//             }
//             root = NULL;
//             marker = -1;

//             CreateDataFile();
//         }

//         void CreateDataFile()
//         {
//             std::ofstream myfile("data.txt", std::ios::app);
//             myfile.close();
//         }

//         void ExpandFreeSpace()
//         {
//             for (int i = 0; i < 20; i++)
//             {
//                 free_spots.insert(std::pair<int, bool>(i, false));
//             }

//             total_spots += 20;
//         }

//         void Serialize(Node *root, FILE *fp) {
//             if (root == NULL) 
//             { 
//                 fprintf(fp, "%d ", marker); 
//                 return; 
//             } 
        
//             fprintf(fp, "%d ", root->key); 
//             Serialize(root->left, fp); 
//             Serialize(root->right, fp); 
//         }

//         void Deserialize(Node *&root, FILE *fp) {
//             std::string val;

//             std::array<char, 32> key;   // 32
//             std::array<char, 32> value; // 32

//             // if there are no more items or the next item is the marker, we return
//             if ( !fscanf(fp, "%d ", &val)) 
//                 return; 

//             unsigned long hash = 0;
//             // Else create node with this item and recur for children 
//             root = new Node(hash, key, value, NULL, NULL, 0);
//             Deserialize(root->left, fp); 
//             Deserialize(root->right, fp); 
//         }

//         void set_root(Node *node)
//         {
//             root = node;
//         }

//         Node *get_root()
//         {
//             return root;
//         }

//         // this finds an open spot starting from the beginning of the file
//         int FindFreeSpace()
//         {
//             for (auto p : free_spots)
//             {
//                 if (p.second == true)
//                 {
//                     free_spots.at(p.first) = false;
//                     return p.first;
//                 }
//             }

//             // if we get to this point, that means that we ran out of free spots
//             // and we need to expand
//             ExpandFreeSpace();
//         }

//         char* ReadAllBytes() {
//             std::ifstream infile("data.txt");
//             char buffer[GetFileSize("data.txt")];
//             //get length of file
//             infile.seekg(0, std::ios::end);
//             size_t length = infile.tellg();
//             infile.seekg(0, std::ios::beg);

//             // making sure that we don't overflow the buffer
//             // this shouldn't happen
//             if (length > sizeof (buffer))
//             {
//                 length = sizeof (buffer);
//             }

//             infile.read(buffer, length);
//             infile.close();

//             return buffer;
//         }

//         /*
//         we read all of the data from data.txt, create a new temp file that will have
//         the data from data.txt along with the changes that we want, and then we rename the temp file to data.txt

//         disclaimer: we can't simply change the specific spot in the data.txt file 

//         we need to add a boolean at the end to indicate whether we are inserting at the end of the file
//         */ 
//         void InsertDataFile(unsigned long hash, std::array<char, 32> key, std::array<char, 32> value, int starting)
//         {
//             std::ofstream myfile;
//             myfile.open("data.txt", std::ios::app);
//             myfile.seekp(starting);

//             std::string hash_str = std::to_string(hash);
//             std::array<char, 16> hash_arr;
//             for (int i = 0; i < hash_str.length(); i++) {
//                 hash_arr[i] = (char)hash_str[i];
//             }

//             for (int i = 0; i < 16; i++) {
//                 myfile << hash_arr[i];
//             }

//             for (int i = 0; i < 32; i++)
//             {
//                 myfile << key[i];
//             }

//             for (int i = 0; i < 32; i++)
//             {
//                 myfile << value[i];
//             }

//             myfile.close();
//         }

//         void DeleteDataFile(int offset) {
//             std::fstream myfile("data.txt", std::ios::in | std::ios::out);
//             myfile.seekg(offset, std::ios::beg);

//             for (int i = 0; i < 80; i++) {
//                 myfile << ' ';
//             }

//             myfile.close();
//             std::map<int, bool>::iterator it = free_spots.find(offset/80);
//             if (it != free_spots.end())
//                 it->second = true;
//         }

//         struct Node *SearchNode(struct Node *root, unsigned long hash)
//         {
//             if (root == NULL)
//             {
//                 std::cout << "Didn't find in database" << std::endl;
//                 return root;
//             }
//             if (root->hash == hash)
//             {
//                 std::cout << "Info found in database" << std::endl;
//                 return root;
//             }
//             if (root->hash < hash)
//             {
//                 return SearchNode(root->right, hash);
//             }

//             else
//             {
//                 return SearchNode(root->left, hash);
//             }
//         }

//         bool IsInsertEnd(int starting) {
//             int idx = starting/80;
//             if (idx > this->idx_end) {
//                 idx_end = idx;
//                 return true;
//             } else {
//                 return false;
//             }
//         }

//         struct Node *Insert(struct Node *node, unsigned long hash, std::array<char, 32> key, std::array<char, 32> value, int starting)
//         {
//             if (node == NULL)
//             {
//                 Node *new_root = new Node(hash, key, value, NULL, NULL, starting);
//                 bool insert_end = IsInsertEnd(starting);
//                 InsertDataFile(hash, key, value, starting);
//                 std::map<int, bool>::iterator it = free_spots.find(starting/80);
//                 if (it != free_spots.end())
//                     it->second = false;
//                 return new_root;
//             }

//             if (hash < node->hash)
//             {
//                 node->left = Insert(node->left, hash, key, value, starting);
//             }
//             else
//             {
//                 node->right = Insert(node->right, hash, key, value, starting);
//             }
//             return node;
//         }

//         struct Node* FindInOrdSucc(struct Node* curr_node) {
//             while (curr_node && curr_node->left != NULL) {
//                 curr_node = curr_node->left;
//             }

//             // by this point, we must be at the left most leaf
//             return curr_node;
//         }

//         struct Node* Delete(struct Node* root, unsigned long hash) {
//             if (!root) {
//                 return root;
//             }

//             if (hash < root->hash) {
//                 root->left = Delete(root->left, hash);
//             } else if (hash > root->hash) {
//                 root->right = Delete(root->right, hash);
//             } else {
//                 // this is the case where we found the node with the target hash

//                 // check if the left child is null
//                 if (root->left == NULL) {
//                     struct Node *tmp = root->right;
//                     unsigned long the_offset = root->starting;
//                     DeleteDataFile(the_offset);
//                     free(root);
//                     return tmp;
//                 } else if (root->right == NULL) {
//                     struct Node *tmp = root->left;
//                     unsigned long the_offset = root->starting;
//                     DeleteDataFile(the_offset);
//                     free(root);
//                     return tmp;
//                 } 

//                 // by here, it means that the node has two children
//                 struct Node* tmp = FindInOrdSucc(root->right);

//                 root->hash = tmp->hash;
//                 root->right = Delete(root->right, tmp->hash);
//             }

//             return root;
//         }

//         std::string convertToStr(Node *tempNode, int size)
//         {
//             std::string s = "";
//             for (int i = 0; i < size; i++)
//             {
//                 s += tempNode->value[i];
//             }
//             return s;
//         }

//         void Inorder(Node *root)
//         {
//             if (!root)
//             {
//                 return;
//             }
//             Inorder(root->left);
//             std::cout << root->hash << std::endl;
//             Inorder(root->right);
//         }

//         void IncrTotalSpots() {
//             total_spots += 1;
//         }

//         void DecrTotalSpots() {
//             total_spots -= 1;
//         }

//     private:
//         std::vector<std::string> data_vec;

//         // the key is an int to represent the index
//         // the value is a bool to represent whether that spot in the vector is free
//         std::map<int, bool> free_spots;
//         int total_spots;

//         unsigned long marker; // this is a marker for the serialization of the binary tree; it indicates if the node is NULL
//         int idx_end; // we need this to see the latest index entry we've inserted
// };

// unsigned long CreateHash(std::string s)
// {
//     unsigned long hash = 5381;

//     for (int i = 0; i < (int)s.length(); i++)
//     {
//         hash = ((hash << 5) + hash) + (unsigned long)s[i];
//     }

//     return hash;
// }

// int main()
// {

//     Database *db = new Database();

//     FILE *fp = fopen("storage.txt", "r");

//     Node *tmp_root = db->get_root();

//     // db->Deserialize(tmp_root, fp);
//     // db->set_root(tmp_root);

//     std::string data_file = "data.txt";
//     std::fstream streamer(data_file, std::ios::in | std::ios::out);

//     std::array<char, 32> key_arr = {0};
//     std::array<char, 32> value_arr = {0};

//     std::string user_input_key;
//     std::string user_input_value;
//     unsigned long hash;

//     while(true)
//     {

//         int option = 0;
//         std::cout << "Choose your option" << std::endl;
//         std::cout << "Option 1: Insert(1)" << std::endl;
//         std::cout << "Option 2: Search(2)" << std::endl;
//         std::cout << "Option 3: Delete(3)" << std::endl;
//         std::cout << "Option 4: Exit(4)" << std::endl;
//         std::cin >> option;

//         if (option == 1)
//         {
//             std::cout << "input a key" << std::endl;
//             std::cin >> user_input_key;

//             std::cout << "input a value" << std::endl;
//             std::cin >> user_input_value;

//             for (int i = 0; i < (int)user_input_key.size(); i++)
//             {
//                 key_arr[i] = user_input_key[i];
//             }
//             for (int i = 0; i < (int)user_input_value.size(); i++)
//             {
//                 value_arr[i] = user_input_value[i];
//             }

//             hash = CreateHash(user_input_key);
//             std::cout << hash << std::endl;

//             int spot_idx = db->FindFreeSpace();
//             db->set_root(db->Insert(db->get_root(), hash, key_arr, value_arr, spot_idx * 80));

//             GetFileSize("data.txt");
//         }

//         if (option == 2)
//         {
//             // db->Inorder(db->get_root());
//             std::cout << "input a key to search for" << std::endl;
//             std::cin >> user_input_key;
//             hash = CreateHash(user_input_key);
//             // std::cout << hash << std::endl;
//             Node *temp_root = db->get_root();
//             Node *tempNode = db->SearchNode(temp_root, hash);
//             std::string value = "";
//             db->IncrTotalSpots();

//             if (tempNode != NULL) {
//                 int size = (sizeof(tempNode->value) / sizeof(char));
//                 value = db->convertToStr(tempNode, size);
//                 std::cout << "The corresponding value is " + value << std::endl;
//             } 
//         }

//         if (option == 3) {
//             Node *temp_root = db->get_root();
//             db->DecrTotalSpots();
//             db->Inorder(db->get_root());
//             std::cout << "input a key to delete" << std::endl;
//             std::cin >> user_input_key;
//             hash = CreateHash(user_input_key);
//             db->set_root(db->Delete(temp_root, hash));
//         }

//         if (option == 4) {
//             FILE *fp = fopen("storage.txt", "w");
//             if (fp == NULL) {
//                 puts("Could not open the file");
//             }

//             db->Serialize(db->get_root(), fp);
//             fclose(fp);

//             return 0;
//         }
//     }

//     return 0;
// }
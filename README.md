# individual_project_db_3010

Creating a key-value stored based database in C++. Currently, it allows the user to put in key value pairs in a hash map.

For demonstration purposes, upon running the program, the user is asked to put in two key value pairs. Obviously, the hash map can hold significantly more key values pairs, but because we just want a short demonstration of it working, I'm only asking the user for two key value pair inputs. After putting in the two key value pairs, the program displays the contents of the database to verify that it is working.

*********************************

UPDATE: 10/23/2020
**How to run it**
- `cd updated_code` after opening individual_project_db_3010
- `make`
- `./main`

SYSTEM REQUIREMENT: It can run on linux, windows, mac. It's just a cpp file with no dependencies required to build/run. 

We are using Binary Search Tree as our data structure for inserting, searching, and deleting values. Each node will contain username and password along with hash aka unique id for secure database/ easy and accurate search. Upon running the program, the user is given 4 option. 

Further Info:
- We are using a file (called "data.txt") as a way to store and manipulate the files; we are essentially using the data file as an array to store the entries of data 
- Whenever we put in a new entry it will contain three fields in this order:
  - the hash value, which is generated from the key value and will be 16 chars long
  - the key, which will be 32 chars long
  - the value, which will be 32 chars long
- So, in total, each entry will take up a total of 80 bytes.
- Since each entry will be **consistently** 80 bytes, we use it as an offset to figure out where to place and locate specific entries.

**Option 1** is to insert a key value pair
  - It generates a hash value from the key; the hash value is used as the *"key"* when doing BST operations since it should be unique to each entry of data
  - It will determine the first open spot/index to place the new entry of data in the data file (**remember**, we are treating the data file like an array) 
  - Then it will perform the BST operation to insert it into the array and put the entry in the data file 
  
**Option 2** is to search/find the corresponding value of a key
  - It generates the hash of the given key (**note**, the generated hash value should be the same as when the same key was first generated).
  - It will recursively try to find the hash value in the BST.
  - If it does find it, it will return the corresponding value; otherwise, it will notify the user that the database doesn't have it.

**Option 3** is to delete a key value pair
  - It will recursively try to find the key .
  - Once it finds the key, it will delete it from the data file and from the BST.

**Option 4** will allow the user to exit the program and save the database in a storage file, which will allow the user to **use the saved database and its current data for future use.**  
    * This is accomplished by first serializing the data, which is essentially a clever way to sequentially store the data so that it can be used in the future to rebuild the BST; leaf nodes are represented as #, and regular nodes are represented as a 80 char containing the hash, key, and value; all of this info is stored in the storage.txt file.  
    * When the user runs the program again, it will deserialize the storage.txt file by sequentially reading the data and recursively rebuild the BST; when building the BST, it will do two things:  
      - if the next chunk of data is a # or we've reached the end of the file, then it will return NULL and do nothing.
      - else if the next chunk of data is an 80 char entry, then it will create and insert a new node to the BST.  




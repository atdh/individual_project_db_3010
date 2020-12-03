# individual_project_db_3010
We created a simple key-value store database (implemented using a Binary Search Tree) in C++. Users will be able to do the four REST operations (GET, POST, PUT, and DELETE) on this database while admin users will also be able to delete users. In order to use the database, first they need to either login or sign up using the GUI application (written with the Qt library) and from there, they have buttons to call out their respective REST operations.  

## Repo structure  
In the code folder, it consists of the main project (PPWProj.pro) and three folders (src, app, and tests) that belong to each of their respective sub projects (src.pro, app.pro, and tests.pro). The `<src>` folder contains all of the code for the database and the Qt application code. The `<app>` folder contains the main.cpp file that runs the application. The `<tests>` folder contains the catch.hpp file and the main.cpp file, which is responsible for running the unit tests.  

**SYSTEM REQUIREMENT:** It can run on linux, windows, mac  

****************************************
UPDATE: 12/02/2020

## How to run the application:  
- First, open the project (PPWProj.pro which is in the code folder) in Qt Creator, configure the project (if need be), and make sure that the PPWProj.pro file looks like this  
<img src="https://i.imgur.com/Ufz3aja.png" width=400p"/>
- Then, also check that the file menu of Qt looks like this  
<img src="https://i.imgur.com/nCHnPDK.png" width=350p"/>
- After that, press the green triangle in Qt Creator in order to run the application  
<img src="https://i.imgur.com/ju5T0Hq.png" width=300p"/>
- A window that looks like the image below should show and you may begin using the application  
<img src="https://i.imgur.com/eLdKhJz.png" width=450p"/>

## How to run the unit tests (written with the Catch2 library):  
- Make sure that the PPWProj.pro file looks like this (NOTE: that the lines to run the app are commented and the lines to run the unit tests are uncommented)  
<img src="https://i.imgur.com/wqKzt6w.png" width=350p"/>
- Then, check that the file menu of Qt looks like this  
<img src="https://i.imgur.com/qK0Ccyk.png" width=350p"/>
- Press the green triangle in Qt Creator in order to run the unit tests  
<img src="https://i.imgur.com/ju5T0Hq.png" width=350p"/>
- In the Application Output, it should show that all of the unit tests passed    
<img src="https://i.imgur.com/HWoTgKh.png" width=350p"/>
  
We are using Binary Search Tree as our data structure for inserting, searching, and deleting values. Each node will contain username and password along with hash aka unique id for secure database/ easy and accurate search. Upon running the program, the user is given 4 option. 

**Further Info:**
- We are using a data file (called "data.txt") as a way to store and manipulate the files; we are essentially using the data file as an array to store the entries of data 
- Whenever we put in a new entry it will contain three fields in this order:
  - the hash value, which is generated from the key value and will be 16 chars long
  - the key, which will be 32 chars long
  - the value, which will be 32 chars long
- So, in total, each entry will take up a total of 80 bytes.
- Since each entry will be **consistently** 80 bytes, we use it as an offset to figure out where to place and locate specific entries within the data file.

**Option 1** is to insert a key value pair
  - **Note**: the user cannot input a key or value containing "#" or "$" because they are used as markers when trying to serialize and deserialize the BST
  - It generates a hash value from the key; the hash value is used as the *"key"* when doing BST operations since it should be unique to each entry of data
  - It will determine the first open spot/index to place the new entry of data in the data file (**remember**, we are treating the data file like an array) 
  - Then it will perform the BST operation to insert it into the array and put the entry in the data file 
  
**Option 2** is to search/find the corresponding value of a key
  - It generates the hash of the given key (**note**, the generated hash value should be the same as when the same key was first generated).
  - It will recursively try to find the hash value in the BST.
  - If it does find it, it will return the corresponding value; otherwise, it will notify the user that the database doesn't have it.

**Option 3** is to delete a key value pair
  - It will recursively try to find the key.
  - Once it finds the key, it will delete it from the data file and from the BST.

**Option 4** will allow the user to exit the program and save the database in a storage file, which will allow the user to **use the saved database and its current data for future use.**  
    * This is accomplished by first serializing the data, which is essentially a clever way to sequentially store the data so that it can be used in the future to rebuild the BST; leaf nodes are represented as #, and regular nodes are represented as a 80 char containing the hash, key, and value; all of this info is stored in the storage.txt file.  
    * When the user runs the program again, it will deserialize the storage.txt file by sequentially reading the data and recursively rebuild the BST; when building the BST, it will do two things:  
      - if the next chunk of data is a # or we've reached the end of the file, then it will return NULL and do nothing.  
      - else if the next chunk of data is an 80 char entry, then it will create and insert a new node (that was built using the information within the data entry) to the BST.  




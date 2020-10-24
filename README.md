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

We are using Binary Search Tree as our data structure for inserting, searching, and deleting values. Each node will contain username and password along with hash aka unique id for secure database/ easy and accurate search. Upon runinng the program, the user is given 3 option. Option 1 is to Insert a key, Option 2 is to Search/find a value after inputting key, and Option 3 is to delete a node. Insert will put username and password to the database. Search will find the proper information. Option 3 will delete a node aka a row which contains information of username and password from the database.  




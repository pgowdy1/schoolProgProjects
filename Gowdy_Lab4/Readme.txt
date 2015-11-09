Perry Gowdy
EECS 560
Lab3
Closed Hash Table

To compile this program. Simply type make into the terminal while you are in the directory that the program files are contained in. 

To run the program with a specific file, type "./main 'filename'" i.e. ./main data.txt

The operations in this program are:

HashTable()
HashTable(istream, quadraticFlag)
insertLinear(numberToInsert, numberToInsert)
insertQuadratic(numberToInsert, numberToInsert)
removeQuadratic(numberToInsert, numberToInsert)
removeQuadratic(numberToInsert, numberToInsert)
contains(numberToFind)
isFull()
print()

You'll note that the program requires you to enter the number to insert into the table two times as a formal parameter. This is so that the hash function can be built-in to the insert function.

Another thing of note is that the constructor can take a flag to tell it whether or not to insert to the hash table quadratically. If the flag is marked "true" it will hash quadratically, if it is marked "false" it will hash linearly.  

For any questions about the program, please email pgowdy@ku.edu

Perry Gowdy

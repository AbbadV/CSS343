1. My program fully work sto my knowledge, no issues.

2.I have one hash table which is used for customer accounts. It has a max size of 10000 and the is indexed by customerID.
 I have another hash table which stores VideoStore Items that has a max size of 26 for A-Z letters. 
 I also use hash factory for VideoStoreItem, transactions, and mediatype (D for DVD). Customer hash table found in
businessmanager.h and hash factories for transaction VideoStoreItem and mediatype found in hashfactory.h.

3.Nothing really, maybe that i got the program to actually work and got past the many memory leaks I had. It was
very time consuming and many many files.

4. I use the data4movies.txt to read movie data and inside my businessmanager.cpp handles the reading of movies.
businesmanager has an array of 26 BST that use VideoStoreItem to store one movie.

5. I use data4commands.txt as file and businessmanager has the readcommands function. It create a new transaction
 and then reads all other data and then creates a temp videostoreitem object which is compared to the real movies stored
 in BST. if it is found then customer addTransaction fucntion takes transaction object as parameter and stores inside
of a vector. Transaction also hold pointer to the movie/item.
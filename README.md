# Binary_Search_Tree
 implement (in C++) a pointer-based binary search tree to store and retrieve customer data.
 
 BSTree.h and BSTree.cpp  
 ---
implement a binary search tree that has the following methods
 
Default constructor - creates an empty tree

-Copy constructor - creates a copy of the given tree

-Destructor - frees dynamic memory allocated by the tree

-bool insert(string, char, int) - creates and inserts a new customer (with the data shown in the parameters) in the tree, in a new tree node.

-bool remove(string, char) - deletes the first node with a matching name and initial from the tree. Returns true if the deletion was successful (that is, if the customer was found). Note that two customers are equal if they have the same name and initial, regardless of the account balance.

-bool search(string, char) - searches the tree for the given value, returning true if the customer is found

-vector<Customer> rangeSearch(string, char, string , char) - returns a vector of Customers where the customer names (initial and last name) are in the range specified in the parameters. For example rangeSearch("Dobbs", 'A', "Fogg", D) returns all 

-customers whose names are between Dobbs A and Fogg D.

-void inOrderPrint() - prints the contents of the tree in sorted order. The output must be one customer per line, no other information. E.g. if the tree contains two customers.
 
Node Class
---
As part of the tree implementation,Each node contain a Customer object, pointers to left and right children and (optionally) the parent.

Application
---
customer_app.cpp

I have provided an application to maintain a collection of customers. It uses your binary search tree class as the collection's container. It allows users to do the following:

-Insert new customers

-Delete customers

-Search for customer

-Print the entire customer collection

-Print a range of customers

-Read a file of customers into the tree

-Quit




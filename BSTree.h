/*
 * BSTree.h
 *
 */

#ifndef BSTREE_H_
#define BSTREE_H_

#include "Customer.h"
#include "Node.h"
#include<vector>
#include<string>
using namespace std;

class BSTree {
public:
	BSTree();
	BSTree(const BSTree & rbt); // Copy constructor
	
	virtual ~BSTree();

	// Creates and inserts a new customer (with the data shown in the parameters) in the tree, in a new tree node.
	bool insert(string, char, int);

	// Deletes the first node with a matching name and initial from the tree.
	// Returns true if the deletion was successful (that is, if the customer was found).
	// Note that two customers are equal if they have the same name and initial, regardless of the account balance.
	bool remove(string, char);

	//  Searches the tree for the given value, returning true if the customer is found
	bool search(string, char);

	// Returns a vector of Customers where the customer names (initial and last name)
	// are in the range specified in the parameters.  For example rangeSearch("Dobbs", 'A', "Fogg", D)
	// returns all customers whose names are between Dobbs A and Fogg D.
	vector<Customer> rangeSearch(string, char, string , char);

	// Prints the contents of the tree in sorted order.
	void inOrderPrint();




	

private:
	Node *root=NULL;
	//return a vector of customers using Recursion
	//to help rangeSearch function
	vector<Customer> rangeSearchHelper(Node* &Node2, Customer Lowerbound,Customer Upperbound,vector<Customer> & CustomerList);
	//delete the binary search tree using Recursion
	void deleteTree(Node *Node2);
	//print the tree inorder using recursion
	//to help inOrderPrint funciton
	void inOrderPrintHelp(Node * Node2);
	//copy the binary search tree using recursion 
	//to help the copy constructor
	void copy(Node * Node2);

	
};
#endif /* BSTREE_H_ */

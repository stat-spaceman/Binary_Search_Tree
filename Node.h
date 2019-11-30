

#ifndef NODE_H_
#define NODE_H_

#include "Customer.h"

class Node {
public:
	Node *left=nullptr;
	Node *right=nullptr;
	Customer Key;

	//constructor
	Node( Customer &Customer2, Node *leftChild,Node *rightChild);


};

#endif /* NODE_H_ */

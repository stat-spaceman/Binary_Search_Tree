

#include "Node.h"

Node::Node( Customer &Customer2, Node *leftChild,  Node *rightChild){
	Key=Customer2;
	left=leftChild;
	right=rightChild;
}

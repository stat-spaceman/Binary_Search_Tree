

#include "BSTree.h"


BSTree::BSTree() {
	root=NULL;
}

void BSTree::deleteTree(Node *Node2){
	if (Node2 == NULL){
		return;
	}
	else {
		//using recursion to delete each node of the tree
		//delete each node until the external node
		deleteTree(Node2->left);
		deleteTree(Node2->right);
		delete Node2;
	}
}

BSTree::~BSTree() {
	deleteTree(root);
}


bool BSTree::insert(string x, char y, int z) {
	//call customer constructor
	Customer newCustomer=Customer(x,y,z);
	Node *newNode =new Node(newCustomer,NULL,NULL);
	//delcare two pointer current and parent
	Node* current=root;
	Node *parent= NULL;

	while (current != NULL){
		//for each iteration current will change to their child and parent will change to current
		//which is pointer parent is parents of current
		parent = current;
		if (newNode->Key <= current -> Key){
			current = current -> left;
		}
		else if (newNode-> Key > current -> Key){
		
			current =  current -> right;
		}
	}

	if (parent == NULL ){ //the tree is empty since the loop doesn't start.
		root = newNode;
	}
	else {
		//after the loop the current point to null
		//parent is the external node then we can insert element in his child
		if (newNode->Key <= parent->Key){
			parent->left= newNode;
		}
		else{
			parent->right= newNode;
		}
	}
	//this function should always return true
	return true;
}


bool BSTree::remove(string x, char y) {
	Customer tempCustomer=Customer(x,y,0);
	//delcare two pointer current and parent
	Node *current =root;
	Node *parent= NULL;
	while (current != NULL && current ->Key != tempCustomer){  //search the target first
		//for each iteration current will change to their child and parent will change to current
		//which is pointer parent is parents of current
		parent = current;
		if (tempCustomer<= current-> Key){
			current = current->left;
		}
		else{
			current = current -> right;
		}
	}
	if (current == NULL){  // target doesn't exist
		return false;
	}
	//we need consider 4 cases in the tree
	//no child case
	if (current -> left == NULL && current -> right == NULL){ //if the node doesn't have child
		if (parent != NULL){//if the tree is not empty
			if (parent -> left == current){
				parent -> left = NULL;
			}
			else{
				parent -> right  = NULL;
			}
		}
		else{ // if the tree only have one node which is root
			delete root;
			root =NULL; 
			return true;  //TO DO : check meory 
		}
		delete current; 
	}
	//left child case
	else if (current -> left != NULL && current -> right == NULL){
		//if the tree is not empty
		if (parent != NULL){
			if (parent -> left == current){
				parent -> left = current -> left;
			}
			else{
				parent -> right  = current -> left;
			}
		}
		else{
			root = current ->left ;  // if the node is root then set root to his left child
		}
		delete current;
	}
	//right child case
	else if (current -> left == NULL && current -> right != NULL){
		//if the tree is not empty
		if (parent != NULL){
			if (parent -> left == current){
				parent -> left = current -> right;
			}
			else{
				parent -> right  = current -> right;
			}
		}
		else{
			root = current ->right ;  // if the node is root then set root to his left child
		}
		delete current;
	}

	else{ //two child case 
		Node * temp_ptr = current;
		Node * temp_parent = current;
		//if the node has two child we need to change it to the max of left child tree
		//then delete the max of left child tree
		current = current -> left;
		while (current -> right ){ //this loop for find the max of left child tree
			temp_parent = current;
			current = current ->right;
		}
		//replace the value with the max of left subtree
		temp_ptr -> Key = current ->Key; 
		//after replace we need remove the max node of left subtree
		//there would have two case
		//first if the parent is root or replace node is child of remove node
		if(temp_parent==root||temp_ptr->left==current){
			temp_parent->left =current->left;
		}
		//second case we need take the left subtree of the max value node to parent's right 
		//since the max value node shouldn't have right node anymore we only need care about left subtree.
		else{
			temp_parent->right = current ->left;
		}
		delete current; // delete the left max
	}
	return true;
}


bool BSTree::search(string x, char y) {
	if(root == NULL){ //if the tree is empty then return false
		return false;
	}
    Customer tempCustomer=Customer(x,y,0);
	Node *current =root;
	//if current is not external node and current's key is not target do the while loop
	while (current != NULL && current ->Key != tempCustomer){ 
		if (tempCustomer<= current-> Key){
			current = current->left;
		}
		else{
			current = current -> right;
		}
	}
	//after check the external node of the tree the current will point to null
	//that means if current == NULL implies did found the target
	if (current != NULL){
		return true;
	}
	return false;
}
vector<Customer> BSTree::rangeSearchHelper(Node* &Node2, Customer Lowerbound,Customer Upperbound,vector<Customer> &CustomerList){
	
	//if the node still has child
	if(Node2 != NULL){
		//if the key of node bigger than the lower bound then do the recursion
		//in each iteration the point Node2 will change to their child
		if(Lowerbound < Node2->Key){
			
			rangeSearchHelper(Node2->left,Lowerbound,Upperbound,CustomerList); 
		}
		//if their child in the range then push them in the vector
		if(Lowerbound<= Node2->Key && Upperbound>=Node2->Key){
			CustomerList.push_back(Node2->Key);
		}
		//if the key of node is less than upper bound then do the recursion and change the node to right child for next iteration
		//until the node is external node the recursion will stop
		if(Upperbound>Node2->Key){
			
			rangeSearchHelper(Node2->right,Lowerbound,Upperbound,CustomerList); 
		}
	}
	return CustomerList;

}

 vector<Customer> BSTree::rangeSearch(string x, char y, string z, char a) {
	vector<Customer> CustomerList;
	Customer CustomerLowerBound= Customer(x,y,0);
	Customer CustomerUpperBound= Customer(z,a,0);
	//if the lower bound bigger than upper bound then return empty vector
	if (root== NULL || CustomerUpperBound<CustomerLowerBound){
		return CustomerList;
	}

	CustomerList=rangeSearchHelper(root,CustomerLowerBound,CustomerUpperBound,CustomerList);
	return CustomerList;
 }
void BSTree::inOrderPrintHelp(Node * Node2){
	//if the node is external node will stop the recursion
	if (Node2 == NULL){
		return;
	}
	//do recursion on the left child
	//and the recursion will printthe external node first
	inOrderPrintHelp(Node2->left);
	//print the Key of the node
	cout<<Node2 -> Key<<"\n";
	//do recursion on right child
	inOrderPrintHelp(Node2->right);
}


void BSTree::inOrderPrint() {
	inOrderPrintHelp(root);
}


void BSTree::copy(Node * Node2){
	//if node is not external node
	if (Node2){
		//call insert function to insert each node of old tree to a new tree
		insert(Node2->Key.GetLastName(),Node2->Key.GetFirstInitial(),Node2->Key.Getbalance());
		//first recursion of left subtree
		copy(Node2->left);
		//recursion of right subtree
		copy(Node2->right);
	}
}

BSTree::BSTree(const BSTree & rbt){
	root = NULL; 
	copy(rbt.root);
}

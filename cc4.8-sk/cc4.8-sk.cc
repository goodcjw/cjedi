#include <stdlib.h>
#include <stdio.h>
#include <exception>
#include <iostream>

using namespace std;
class TNode{
public:
	int v;
	TNode* left;
	TNode* right;
	TNode(int a){v = a;left = NULL;right=NULL;}; 
	~TNode(){if(left!=NULL) delete left; if(right!=NULL) delete right;}
};

class LNode{
public:
	TNode* t_node;
	LNode* prev;
	LNode(TNode* a){t_node = a; prev = NULL;}
	LNode(LNode* a){t_node = a->t_node; prev = NULL;}
	~LNode();
};


LNode::~LNode(){
	if(this->prev!=NULL){
		printf("node %d is deleted\n",t_node->v);
		delete this->prev;
	}
}

void
find_path(TNode* n, LNode* const oldLink, int value){
	if(n == NULL)
		return;
	LNode* newLink;
	LNode* newLinkPtr = NULL;
	if(n->v == value){
		printf("%d\n",n->v);
	}
	else if(n->v < value){
		newLink = new LNode(n);
		newLinkPtr = newLink;
		LNode* oldLinkPtr = oldLink;
		int curSum = newLinkPtr->t_node->v;
		while(oldLinkPtr!=NULL){
			curSum +=  oldLinkPtr->t_node->v;
			if(curSum>=value){
				if(curSum == value){
					LNode* ptr = newLink;
					while(ptr!=NULL){
						printf("%d ",ptr->t_node->v);
						ptr = ptr->prev;
					}
					printf("%d ", oldLinkPtr->t_node->v);
					printf("\n");
				}
				break;
			}
			else{
				newLinkPtr->prev = new LNode(oldLinkPtr);
				newLinkPtr = newLink->prev;
			}
			oldLinkPtr = oldLinkPtr->prev;
		} 
	}
	find_path(n->left,newLink,value);
	find_path(n->right,newLink,value);
	//delete newLink;
};

int main(int argc, char** argv){
	TNode root(1);
	root.left = new TNode(3);
	root.right = new TNode(1);
	TNode* ptr = root.right;
	ptr->left = new TNode(5);
	ptr->right = new TNode(3);
	ptr= ptr->right;
	ptr->right = new TNode(1);
	find_path(&root,NULL,5);	
	return 0;
}

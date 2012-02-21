#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
class TNode{
public: 
	int v;
	TNode * left;
	TNode * right;
	TNode(int v){this->v = v; left = NULL; right = NULL;}	
	TNode(){this->v = 0; left = NULL; right = NULL;}
	//~TNode();
};
/*
TNode::~TNode(){
	if(left!=NULL){
		delete left;
	}
	if(right!=NULL){
		delete right;
	}
}
*/
int
log2(int n){
	int result = 0;
	while((n=n>>1)>0){
		result++;
	}
	return result;
}

TNode*
transform(TNode* root, TNode* leftN, TNode* rightN){
	TNode* result = NULL;
	if(root->left==NULL){
		root->left = leftN;
		if(leftN!=NULL){
			printf("%d's left is %d\n",root->v, leftN->v);
			leftN->right = root;
		}
		else{
			result = root;
		}
	}
	else{
		result = transform(root->left,leftN,root);
	}
	if(root->right==NULL){
		root->right = rightN;
		if(rightN!=NULL){
			printf("%d's right is %d\n",root->v, rightN->v);
			rightN->left = root;
		}
		else{
			printf("tail\n");
		}
	}
	else{
		transform(root->right,root,rightN);
	}
	return result;
}

TNode*
create_min_tree(int array[], int start, int end, int height, int remain){
	if(start == end){
		return new TNode(array[start]);
	}	
	else{
		int rootIndex = 0;
		TNode* root = new TNode(0);
		if(remain == 0){
			rootIndex = start+(end-start-1)/2+1;
			root->v = array[rootIndex];
			root->left = create_min_tree(array,start,rootIndex-1,height-1,0);
			root->right = create_min_tree(array,rootIndex+1,end,height-1,0);
		}		
		else{
			int diff = remain - pow(2,height-2);
			if(diff>0){
				assert((end-start-remain)%2 == 0);
				rootIndex = start+(end-start-remain)/2 + pow(2,height-2);
				root->v = array[rootIndex];
				root->left = create_min_tree(array,start,rootIndex-1,height-1,0);
				root->right = create_min_tree(array,rootIndex+1,end,height-1,diff);
			}
			else{
				rootIndex = start+(end-start-remain)/2+remain;
				root-> v = array[rootIndex];
				root-> left = create_min_tree(array,start,rootIndex-1,height-1,remain);
				root->right = create_min_tree(array,rootIndex+1,end,height-2,0);
			}
		}	
		return root;
	}
}

void 
print_tree(TNode * root,int size,int  height){
	TNode** array = new TNode*[size];
	int tail = 0;
	//memset(array,NULL,size);
	int i=0;
	array[0] = root;
	array[1] = NULL;
	tail = 2;
	int curHeight = 1;
	for(i=0;i<size+height;i++){
		if(array[i]!=NULL){
			int indent = 0;
			if(i==0 || array[i-1]==NULL) 
				indent = pow(2,height-curHeight)-1;
			else
				indent = pow(2,height-curHeight+1)-1;  
			
			int j = 0;
			for(j=0; j<indent; j++){
				printf(" ");
			}
			printf("%d",array[i]->v);
			if(array[i]->left!=NULL){
				array[tail] = array[i]->left;
				tail++;
			}
			if(array[i]->right!=NULL){
				array[tail] = array[i]->right;
				tail++;
			}
		}
		else
		{
			printf("\n");
			curHeight++;
			array[tail] = NULL;
			tail++;
		}
	}
}

int main(int argc, char** argv){
	int array[] = {1,2,3,4,5,6,7,8,9};
	int size  = 9;
	int height = log2(size)+1;
	int remain = size - pow(2,height-1)+1;
	TNode* tree = create_min_tree(array,0,size-1,height,remain);
	print_tree(tree, size,height);
    TNode* start = transform(tree, NULL, NULL);
	TNode* ptr = start;
	while(ptr!=NULL){
		printf("node is %d\n", ptr->v);
		ptr = ptr->right;
	}
	delete tree;
	return 0;
}

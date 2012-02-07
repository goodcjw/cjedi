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
	~TNode();
};

TNode::~TNode(){
	if(left!=NULL){
		delete left;
	}
	if(right!=NULL){
		delete right;
	}
}

int
log2(int n){
	int result = 0;
	while((n=n>>1)>0){
		result++;
	}
	return result;
}

bool
isSubTree(TNode* curT1, TNode* curT2, TNode* oriT2){
	if(curT1 == NULL){ //touch the end
		if(curT2==NULL || oriT2==NULL)
			return true;
		else
			return false;
	}
	else{
		
		bool isNewTraceOk = false;
		bool isSubTraceOk = false;
		bool isCurTraceOk = false;
		if(curT1->v == oriT2->v){	//current trace can't be subTree
			isNewTraceOk = isSubTree(curT1->left,oriT2->left,oriT2)
					&&isSubTree(curT1->right,oriT2->right,oriT2);
		}
		if(curT2!=NULL&&curT1->v==curT2->v){
			isCurTraceOk =  isSubTree(curT1->left,curT2->left,oriT2)
					&&isSubTree(curT1->right,curT2->right,oriT2);
		}
		isSubTraceOk = isSubTree(curT1->left,oriT2,oriT2) 
					||isSubTree(curT1->right,oriT2,oriT2);
		
		return (isNewTraceOk || isSubTraceOk || isCurTraceOk);
	}
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
	int array[] = {1,2,3,5,2,2,3,6,7,8,9};
	int array2[]  = {1,2,3};
	int size2= 3;
	int height2 =2;
	int remain2 = 0;
	int size  = 9;
	int height = log2(size)+1;
	int remain = size - pow(2,height-1)+1;
	TNode* tree = create_min_tree(array,0,size-1,height,remain);
	TNode* tree2 = create_min_tree(array2,0,size2-1,height2,remain2);
	print_tree(tree, size,height);
	print_tree(tree2,size2,height2);
	isSubTree(tree,tree2,tree2)?printf("yes\n"):printf("no\n");
	delete tree;
	delete tree2;
	return 0;
}

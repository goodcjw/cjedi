#include <stdlib.h>
#include <stdio.h>

void
merge(int array1[], int len1, int array2[], int len2){
	int index1 = len1-1;
	int index2 = len2-1;
	for(int i = len1+len2-1; i >=0; i--){
		if(index1 < 0){
			array1[i] = array2[index2];
			index2--;
		}
		else{
			if(array1[index1]> array2[index2]){
				array1[i] = array1[index1];
				index1--;
			}
			else{
				array1[i] = array2[index2];
				index2--;
			}
		}
	}
}

int main(int argc, char** argv){
	int array1[20] = {1,2,3,5,8};
	int array2[4] = {2,4,6,9};
	merge(array1,5,array2,4);
	for(int i =0; i < 9; i++){
		printf("%d ",array1[i]);
	}
	printf("\n");
	return 0;
}

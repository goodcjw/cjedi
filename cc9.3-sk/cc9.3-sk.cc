#include <stdlib.h>
#include <stdio.h>

int
find(int array[], int value, int start, int end){
	for(int i = start; i <= end; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	if(end-start<2){
		if(array[start]==value)
			return start;
		if(array[end]==value)
			return end;
		return -1;
	}
	int middle = start + (end-start)/2;
	if(array[start] >= array[end]){	//gap area
		if(array[middle]==value){
			return middle;
		}
		if(array[middle]<value){
			if(array[start]>array[middle]&&array[end]<value){
				return find(array,value,start,middle);
			}
			else{
				return find(array,value,middle,end);
			}
		}
		else{
			if(array[end]<array[middle]&&array[start]>value){
				return find(array,value,middle,end);
			}
			else{
				return find(array,value,start,middle);
			}
		}
	}
	else{
		if(array[middle]==value){
			return middle;
		}
		if(array[middle]<value){
			return find(array,value,start,middle);
		}
		else{
			return find(array,value,middle,end);
		}
	}
}

int main(int argc, char** argv){
	int array[] = {15,16,19,20,25,1,3,4,5,7,10,14};
	int size = sizeof(array)/sizeof(int);
	printf("the index of 5 is %d, should be 8\n",find(array,5,0,size-1));
	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

void 
swap(int* array, int i, int j){
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

int 
partition(int array[], int start, int end){
	assert(start<=end);
	int pivot = array[end];
	int bigStart = start;
	for(int i = start; i<=end;i++){
		if(array[i]<=pivot){
			if(i>bigStart){
				swap(array,bigStart,i);
			}
			bigStart++;	
		}
	}	
	assert(bigStart <= end+1);
	return (bigStart-1);
}

void
qsort(int* array, int start, int end){
	if(end - start <= 1){
		if(start<end && array[start]>array[end]){
			swap(array,start,end);
		}
		return;
	}
	srand(time(NULL));
	int pivot = start+rand()%(end-start+1);
	swap(array,pivot,end);
	int pivotIndex = partition(array,start,end);
	qsort(array,start, pivotIndex-1);
	qsort(array,pivotIndex+1,end);
}

int main(int argc, char** argv){
	int a[9] = {9,8,6,7,5,3,4,2,1};
	qsort(a,0,8);
	for(int i = 0; i < 9; i++){
		printf("%d ",a[i]);
	}	
	printf("\n");
	return 0;
}

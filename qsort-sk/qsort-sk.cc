#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>

void 
swap(int* array, int i, int j){
	if(i==j) return;
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

int 
partition(int array[], int start, int end){
	int bigStart = start;
	for(int i = start; i <= end; i++){
		if(array[i]<=array[end]){
			swap(array,bigStart, i);
			bigStart++;
		}
	}
	return bigStart-1;
}

void 
qsort(int array[], int start, int end){
	if(start >= end){
		return;
	}
	srand(time(NULL));
	int pivot = start + rand()%(end-start+1);
	swap(array,pivot,end);
	pivot = partition(array,start,end);
	qsort(array,start, pivot-1);
	qsort(array,pivot+1,end);
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

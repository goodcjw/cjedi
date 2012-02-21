#include <stdlib.h>
#include <stdio.h>

void
swap(int array[], int i1, int i2){
	int tmp = array[i1];
	array[i1] = array[i2];
	array[i2] = tmp;
}

void
max_heapify(int array[], int size, int index){
	int maxIndex = index;
	if(index*2+1>=size){ //no left
		return;
	}
	else if(array[index*2+1]>array[index]){
		maxIndex = index*2+1;
	}
	if(index*2+2 < size){
		if(array[index*2+2]>array[maxIndex]){
			maxIndex = index*2+2;	
		}
	}
	if(maxIndex != index){
		swap(array, index, maxIndex);
		max_heapify(array,size,maxIndex);
	}
}

void
create_max_heap(int array[], int size){
	if(size == 0 ) return;
	for(int i = size-1; i>=0 ; i--){
		max_heapify(array,size,i);
	}	
}

void 
h_sort(int array[], int size){
	if(size < 2)
		return;
	create_max_heap(array, size);
	for(int i = size-1; i > 0; i--){
		swap(array,0,i);
		max_heapify(array,i,0);
	}
}

int main(int argc, char** argv){
	int array[10] = {9,8,7,6,5,4,3,2,1,0};
	//h_sort(array);
	h_sort(array,10);
	for(int i = 0; i<10; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	return 0;
}

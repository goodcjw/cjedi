#include <stdlib.h>
#include <stdio.h>

void
swap(int a[],int i1, int i2){
	int tmp = a[i1];
	a[i1] = a[i2];
	a[i2] = tmp;
}

void 
sort123(int a[], int size){
	int index1 = 0;
	int index3 = size-1;
	while(a[index1]==1&&index1<size-1){
		index1++;
	}
	while(a[index3]==3&&index3>0){
		index3--;
	}	
	for(int i = index1; i <= index3;i++){
		if(a[i]==1){
			swap(a,i,index1);
			index1++;
		}
		if(a[i]==3){
			swap(a,i,index3);
			index3--;
			i--;
		}
	}
}

int main(int argc, char** argv){
	int a [10] = {3,2,1,1,2,3,1,1,1,3};
	sort123(a,10);
	for(int i = 0; i < 10; i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}

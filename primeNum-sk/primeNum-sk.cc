#include <stdlib.h>
#include <stdio.h>

int*
getPrime1(int num){
	
	int* primes = (int*) malloc(sizeof(int)*num);
	if(num<2){
		return primes;
	}
	int size;
	primes[0] = 2;
	size = 1;
	for(int i =3 ; i<= num; i++){
		int isPrime = 1;
		int a;
		for(int j = 0 ; j<size;j++){
			a = i/primes[j];
			if(a<primes[j])
				break;
			if((i-a*primes[j])==0){
				isPrime = 0;
				break;
			}	
		}	
		if(isPrime){
			primes[size] = i;
			size++;
		}
	}
	return primes;
}

int* 
getPrime2(int num){
	
}


int main(int argc, char** argv){
	int num = atoi(argv[1]);
	int* a = getPrime1(num);	
	int *ptr = a;
	while(*ptr){
		printf("%d ",*ptr);
		ptr++;
	}
	return 0;
}

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char** argv){
	FILE* file = fopen("a","r");
	
	printf("file descriptor is %d\n", *file);
	return 0;
}

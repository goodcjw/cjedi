#include <stdlib.h>
#include <stdio.h>

void
rotate(int** matrix, int N){
	if(matrix == NULL || N ==1){
		return matrix;
	}
	int mid = N>>2;
	mid += N&1;
	for(int i = 0; i< mid; i++){
		for(int j =0;j<mid;j++){
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[N-j][i];
			matrix[N-j][i] = matrix[N-i][N-j];
			matrix[N-i][N-j] = matrix[j][N-i];
			matrix[j][N-i] = tmp;
		}
	}
	
	
}


int main(int argc, char** argv){
	FILE* f = fopen(argv[1],"rt");
	int** a = malloc(100);
	char buffer[10] = "";
	int bufferptr = 0;
	int i =0;
	int j =0;
	for(char c = fgetc(f); c!=EOF; c = fgetc(f)){
		if(c == ' '){
			a[i][j]=atoi(buffer);
			bufferptr = 0;
			j++;
		}
		else if(c == '\n'){
			a[i][j]=atoi(buffer);
			bufferptr = 0;
			i++;
			j=0;
		}
		else{
			buffer[bufferptr] = a;
			bufferptr++;
		}
		
	}
	fclose(f);
	rotate(a,i);
	for(int k = 0;k<i;k++){
		for(int q = 0; q < i; q++){
			printf("%d\t",a[k][q]);
		}
		printf("\n");
	}
	return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void replace(char* string, int length){
	int curindex = length;
	for(int i =0; i < length ;i++){
		if(string[i]==' '){
			curindex+=2;
		}
	}
	string[curindex] = '\0';
	curindex--;
	for(int i = length-1; i>=0;i--){
		if(string[i]==' '){
			string[curindex-2] = '%';
			string[curindex-1] = '2';
			string[curindex] = '0';
			curindex -= 3;
		}
		else{
			string[curindex] = string[i];
			curindex--;
		}
	}
}

int main(int argc, char** argv){
	char* string = argv[1];
	replace(string,strlen(string));
	printf("the string is %s\n",string);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
int mylen(char* string){
	char* ptr = string;
	while(*ptr){
		ptr++;
	}
	return (ptr-string);
}
void reverse_string(char* string){
	int length = mylen(string);
	if(length <= 1){
		return;
	}
	for(int i =0; i < length/2;i++){
		char tmp = string[i];
		string[i] = string[length-i];
		string[length-i] = tmp;	
	}
}

int main(int argc, char** argv){
	reverse_string(argv[1]);
	printf("reversed string is %s\n",argv[1]);
	return 0;
}

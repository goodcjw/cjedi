#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
//#include <ext/hash_map>
#include <tr1/unordered_map>
using namespace std;
int main(int argc, char** argv){
	std::tr1::unordered_map<string,int> myMap2;

	//map<string, int> myMap2;
	yMap2["a"] =1;
	myMap2["b"] =2;
	myMap2.insert(std::make_pair("c",3));
	myMap2.insert(std::pair<string,int>("d",4));
	
	for(std::tr1::unordered_map<string,int>::iterator ii = myMap2.begin(); ii !=myMap2.end();++ii){
		cout << (*ii).first << " "<<(*ii).second<<endl;
	}
	return 0;
}

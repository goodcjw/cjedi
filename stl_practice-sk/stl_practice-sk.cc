#include <stdlib.h>
#include <stdio.h>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <iostream>
#include <string>

class Node{
	private: 
		int v;
	public:
		Node(int a ){this->v=a;}
};

using namespace std;
int main(int argc, char** argv){
	stack<int*> s;
	int* a = new int(1);
	int** b = new int*[10];
	int* c = (int*) operator new (10*sizeof(int));
	c[0] = 1;
	c[1] = 2;
	cout<<c[1]<<endl;
	s.push(NULL);
	s.pop();
	if(s.empty()){
		cout<<"isEmpty!!"<<endl;
	}
	delete[] b;

	map<string, int> m;
	m["hello"] = 1;
	m["world"]  = 2;

	for(map<string,int>::iterator i = m.begin(); i!= m.end(); i++){
		cout << i->first<<" "<<i->second<<endl;
	}

	int aaa = 10;
	int* bbb = &aaa;
	cout<<*bbb<<endl;
	
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	list<int>::iterator it;
	it = l.begin();
	it++;
	l.erase(it);
	l.insert(it,3);
	cout<<*(l.end())<<endl;
	//for(it = l.begin(); it!=l.end(); it++){
	//	cout<<(*it)<<endl;
	//}

	//Node x[10] = new Node[10];

	return 0;
}

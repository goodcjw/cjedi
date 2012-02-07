#include <stdlib.h>
#include <stdio.h>
class node{
public:
	int v;
	node* prev;
	node(int a){this->v = a;};
};
class Stack{
private:
	node* top;
public:
	void push(int);
	int pop(void);
	int peek(void);
	bool isEmpty(void);
	Stack(){top =NULL;};
};

void
Stack::push(int a){
	node* x = new node(a);
	x->prev = top;
	top = x;
}

int 
Stack::pop(){
	if(isEmpty())
		return -1;
	node* tmp = top;
	top = top->prev;
	int r = tmp->v;
	delete(tmp);
	return r;
}

int 
Stack::peek(){
	if(isEmpty()) return -1;
	return top->v;
}

bool
Stack::isEmpty(){
	return (top==NULL);
}

void 
sort(Stack* s){
	if(s->isEmpty()) return;
	Stack* tmp = new Stack();
	while(!s->isEmpty()){
		int v = s->pop();
		int t = tmp->peek();
		while(v<t && t!=-1){
			t = tmp->pop();
			s->push(t);
			t = tmp->peek();
		}
		tmp->push(v);
	}
	Stack *tmp2 = s;
	*s = *tmp;
}



int main(int argc, char** argv){
	Stack myS;
	myS.push(7);
	myS.push(9);
	myS.push(1);
	myS.push(4);
	sort(&myS);
	while(!myS.isEmpty()){
		printf("%d\n",myS.pop());
	}
	return 0;
}

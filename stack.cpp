#include <iostream>
#include "stacknode.h"
#include "stack.h"

using namespace std;


Stack::Stack(){
	top = nullptr;
}

Stack::~Stack(){
	while (top != nullptr){
		Pop();
	}
}

void Stack::Push(int num){
	top = new StackNode(num, top);
}

int Stack::GetTop(){
	return top->getData();
}

void Stack::Pop(){
	if (top != NULL) {

		StackNode* node = top;
		top = top->getNext();
		delete node;
	}
}



#ifndef _STACK_H
#define _STACK_H

#include <iostream>
#include "stacknode.h"

using namespace std;

class Stack {
private:
	StackNode* top;

public:
	Stack();
	virtual ~Stack();

	void Push(int num);
	int GetTop();
	void Pop();
};

#endif

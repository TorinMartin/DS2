#ifndef _STACKNODE_H
#define _STACKNODE_H

class StackNode{
private:
	int data;
	StackNode* next;

public:
	StackNode();
	StackNode(int data, StackNode* next);
	virtual ~StackNode();

	int getData();
	void setData(int data);

	StackNode* getNext();
};

#endif

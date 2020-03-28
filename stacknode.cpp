#include <iostream>
#include "stacknode.h"

using namespace std;

StackNode::StackNode(){
	data = 0;
	next = nullptr;
}

StackNode::StackNode(int data, StackNode* next){
	this->data = data;
	this->next = next;
}

StackNode::~StackNode(){
}

int StackNode::getData(){
	return data;
}

void StackNode::setData(int data){
	data = data;
}

StackNode* StackNode::getNext(){
	return next;
}

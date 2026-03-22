#pragma once
#include <iostream>

struct Node
{
	int val;
	Node* next;
};

class LinkStack
{
public:
	LinkStack();
	~LinkStack();

public:
	void PushBack(int val);
	void PopBack();

private:
	Node* head_;
};
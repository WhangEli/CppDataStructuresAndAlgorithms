#pragma once
#include <iostream>

struct Node
{
	int val;
	Node* next;
	Node* pre;
};

class LinkQueue
{
public:
	LinkQueue();
	~LinkQueue();

public:
	void Enqueue(int val);
	void Dequeue();

private:
	Node* head_;
	Node* rear_;
};
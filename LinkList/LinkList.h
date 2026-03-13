#pragma once
#include <iostream>

struct Node
{
	int mVal;
	Node* mNext;
};

class LinkList
{
public:
	LinkList();
	~LinkList();

public:
	void printLinkList();
	void insertTail(int val);
	void insertHead(int val);
	void removeNode(int val);
	void updateVal(int val, int newVal);

private:
	Node* mHead;
};
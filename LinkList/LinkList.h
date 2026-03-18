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
	void PrintLinkList();
	void InsertTail(int val);
	void InsertHead(int val);
	void RemoveNode(int val);
	void UpdateVal(int val, int newVal);
	void SortedLinkList(int num);

private:
	Node* mHead;

public:
	friend void MergeSortedLinkList(LinkList& l1, LinkList& l2);
};

void MergeSortedLinkList(LinkList& l1, LinkList& l2);
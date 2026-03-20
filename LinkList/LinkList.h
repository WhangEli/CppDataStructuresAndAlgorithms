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
	Node* IsItCircle();
	void MoveKPos(int num);

public:
	Node* mHead;
};

void MergeSortedLinkList(LinkList& l1, LinkList& l2);

void MergeTwoLinkList(LinkList& l1, LinkList& l2);

void IsItIntersect(LinkList& l1, LinkList& l2);

void Joseph(LinkList& l, int num, int index);
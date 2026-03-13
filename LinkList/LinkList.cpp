#include "LinkList.h"

LinkList::LinkList()
{
	mHead = new Node();
	mHead->mVal = 0;
	mHead->mNext = nullptr;
}

LinkList::~LinkList()
{
	delete mHead;
	mHead = nullptr;
}

void LinkList::printLinkList()
{
	Node* p = nullptr;
	p = mHead->mNext;

	while (p != nullptr)
	{
		std::cout << p->mVal << " ";
		p = p->mNext;
	}

	std::cout << std::endl;
}

void LinkList::insertTail(int val)
{
	Node* p = mHead;

	while (p->mNext != nullptr)
	{
		p = p->mNext;
	}

	p->mNext = new Node;
	p = p->mNext;
	p->mVal = val;
	p->mNext = nullptr;
}

void LinkList::insertHead(int val)
{
	Node* node = new Node;
	Node* p = mHead->mNext;

	node->mVal = val;
	node->mNext = p;
	mHead->mNext = node;
}

void LinkList::removeNode(int val)
{
	Node* p = mHead->mNext;
	Node* q = mHead;

	while (p != nullptr)
	{
		if (p->mVal == val)
		{
			q->mNext = p->mNext;
			return;
		}

		p = p->mNext;
		q = q->mNext;
	}

	std::cout << "no such val in the LinkList" << std::endl;
}

void LinkList::updateVal(int val, int newVal)
{
	Node* p = mHead->mNext;

	while (p != nullptr)
	{
		if (p->mVal == val)
		{
			p->mVal = newVal;
			return;
		}

		p = p->mNext;
	}

	std::cout << "no such val in the LinkList" << std::endl;
}
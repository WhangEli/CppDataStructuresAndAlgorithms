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

void LinkList::PrintLinkList()
{
	Node* p = mHead->mNext;

	while (p != nullptr)
	{
		std::cout << p->mVal << " ";
		p = p->mNext;
	}

	std::cout << std::endl;
}

void LinkList::InsertTail(int val)
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

void LinkList::InsertHead(int val)
{
	Node* node = new Node;
	Node* p = mHead->mNext;

	node->mVal = val;
	node->mNext = p;
	mHead->mNext = node;
}

void LinkList::RemoveNode(int val)
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

void LinkList::UpdateVal(int val, int newVal)
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

void LinkList::SortedLinkList(int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		Node* p = mHead->mNext->mNext;
		Node* q = mHead->mNext;

		for (int j = 0; j < num -1 - i; j++)
		{
			if (p->mVal < q->mVal)
			{
				int temp = p->mVal;
				p->mVal = q->mVal;
				q->mVal = temp;
			}

			p = p->mNext;
			q = q->mNext;
		}
	}
}

void MergeSortedLinkList(LinkList& l1, LinkList& l2)
{
	Node* p1 = l1.mHead->mNext;
	Node* p2 = l2.mHead->mNext;

	if (p1 == nullptr)
	{
		l1.mHead = l2.mHead;
		return;
	}

	if (p2 == nullptr)
	{
		return;
	}

	while (p2 != nullptr)
	{
		l1.InsertHead(p2->mVal);
		p2 = p2->mNext;
	}

	l1.SortedLinkList(21);
}

void MergeTwoLinkList(LinkList& l1, LinkList& l2)
{
	Node* last = l1.mHead;
	Node* p = l1.mHead->mNext;
	Node* q = l2.mHead->mNext;

	while (p != nullptr && q != nullptr)
	{
		if (p->mVal >= q->mVal)
		{
			last->mNext = q;
			last = last->mNext;
			q = q->mNext;
			last->mNext = p;
		}
		else
		{
			p = p->mNext;
			last = last->mNext;
		}
	}

	if (p == nullptr)
	{
		while (q != nullptr)
		{
			last->mNext = q;
			last = last->mNext;
			q = q->mNext;
		}
	}
}
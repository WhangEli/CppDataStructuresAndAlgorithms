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

Node* LinkList::IsItCircle()
{
	Node* slow = mHead->mNext;
	Node* fast = mHead->mNext;

	while (fast != nullptr)
	{
		slow = slow->mNext;
		fast = fast->mNext;
		if (fast == nullptr)
		{
			return nullptr;
		}
		else
		{
			fast = fast->mNext;
		}

		if (fast == slow)
		{
			fast = mHead->mNext;
			while (fast != slow)
			{
				fast = fast->mNext;
				slow = slow->mNext;
			}

			return slow;
		}
	}

	return nullptr;
}

void LinkList::MoveKPos(int num)
{
	for (int i = 0; i < num; i++)
	{
		Node* p = mHead->mNext;
		Node* q = mHead;

		if (p == nullptr)
		{
			return;
		}

		while (p->mNext != nullptr)
		{
			p = p->mNext;
			q = q->mNext;
		}

		p->mNext = mHead->mNext;
		q->mNext = nullptr;
		mHead->mNext = p;
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

void IsItIntersect(LinkList& l1, LinkList& l2)
{
	Node* temp1 = l1.mHead;
	Node* temp2 = l2.mHead;
	int num1 = 0;
	int num2 = 0;

	while (temp1 != nullptr)
	{
		temp1 = temp1->mNext;
		num1++;
	}

	while (temp2 != nullptr)
	{
		temp2 = temp2->mNext;
		num2++;
	}

	Node* p = l1.mHead;
	Node* q = l2.mHead;

	if (num1 >= num2)
	{
		while (num1 - num2 > 0)
		{
			num1--;
			p = p->mNext;
		}
	}
	else
	{
		while (num2 - num1 > 0)
		{
			num2--;
			q = q->mNext;
		}
	}

	while (p != nullptr)
	{
		if (p == q)
		{
			std::cout << "two linklists intersect , the pos is " << p << std::endl;
			return;
		}

		p = p->mNext;
		q = q->mNext;
	}

	std::cout << "the two linklists do not intersect" << std::endl;
}

void Joseph(LinkList& l, int num, int index)
{
	Node* fast = l.mHead->mNext;
	Node* slow = l.mHead;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < index - 1; j++)
		{
			fast = fast->mNext;
			slow = slow->mNext;
		}

		std::cout << fast->mVal << " ";
		slow->mNext = fast->mNext;
		delete fast;
		fast = slow->mNext;
	}

	std::cout << std::endl;
}
#include "link_list.h"

LinkList::LinkList()
{
	head_ = new Node();
	head_->val = 0;
	head_->next = nullptr;
}

LinkList::~LinkList()
{
	Node* p = head_->next;

	while (p != nullptr)
	{
		head_->next = p->next;
		delete p;
		p = head_->next;
	}
}

void LinkList::PrintLinkList()
{
	Node* p = head_->next;

	while (p != nullptr)
	{
		std::cout << p->val << " ";
		p = p->next;
	}

	std::cout << std::endl;
}

void LinkList::InsertTail(int val)
{
	Node* p = head_;

	while (p->next != nullptr)
	{
		p = p->next;
	}

	p->next = new Node;
	p = p->next;
	p->val = val;
	p->next = nullptr;
}

void LinkList::InsertHead(int val)
{
	Node* node = new Node;
	Node* p = head_->next;

	node->val = val;
	node->next = p;
	head_->next = node;
}

void LinkList::RemoveNode(int val)
{
	Node* p = head_->next;
	Node* q = head_;

	while (p != nullptr)
	{
		if (p->val == val)
		{
			q->next = p->next;
			return;
		}

		p = p->next;
		q = q->next;
	}

	std::cout << "no such val in the LinkList" << std::endl;
}

void LinkList::UpdateVal(int val, int newVal)
{
	Node* p = head_->next;

	while (p != nullptr)
	{
		if (p->val == val)
		{
			p->val = newVal;
			return;
		}

		p = p->next;
	}

	std::cout << "no such val in the LinkList" << std::endl;
}

void LinkList::SortedLinkList(int num)
{
	for (int i = 0; i < num - 1; i++)
	{
		Node* p = head_->next->next;
		Node* q = head_->next;

		for (int j = 0; j < num -1 - i; j++)
		{
			if (p->val < q->val)
			{
				int temp = p->val;
				p->val = q->val;
				q->val = temp;
			}

			p = p->next;
			q = q->next;
		}
	}
}

Node* LinkList::IsItCircle()
{
	Node* slow = head_->next;
	Node* fast = head_->next;

	while (fast != nullptr)
	{
		slow = slow->next;
		fast = fast->next;
		if (fast == nullptr)
		{
			return nullptr;
		}
		else
		{
			fast = fast->next;
		}

		if (fast == slow)
		{
			fast = head_->next;
			while (fast != slow)
			{
				fast = fast->next;
				slow = slow->next;
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
		Node* p = head_->next;
		Node* q = head_;

		if (p == nullptr)
		{
			return;
		}

		while (p->next != nullptr)
		{
			p = p->next;
			q = q->next;
		}

		p->next = head_->next;
		q->next = nullptr;
		head_->next = p;
	}
}

void MergeSortedLinkList(LinkList& l1, LinkList& l2)
{
	Node* p1 = l1.head_->next;
	Node* p2 = l2.head_->next;

	if (p1 == nullptr)
	{
		l1.head_ = l2.head_;
		return;
	}

	if (p2 == nullptr)
	{
		return;
	}

	while (p2 != nullptr)
	{
		l1.InsertHead(p2->val);
		p2 = p2->next;
	}

	l1.SortedLinkList(21);
}

void MergeTwoLinkList(LinkList& l1, LinkList& l2)
{
	Node* last = l1.head_;
	Node* p = l1.head_->next;
	Node* q = l2.head_->next;

	while (p != nullptr && q != nullptr)
	{
		if (p->val >= q->val)
		{
			last->next = q;
			last = last->next;
			q = q->next;
			last->next = p;
		}
		else
		{
			p = p->next;
			last = last->next;
		}
	}

	if (p == nullptr)
	{
		while (q != nullptr)
		{
			last->next = q;
			last = last->next;
			q = q->next;
		}
	}
}

void IsItIntersect(LinkList& l1, LinkList& l2)
{
	Node* temp1 = l1.head_;
	Node* temp2 = l2.head_;
	int num1 = 0;
	int num2 = 0;

	while (temp1 != nullptr)
	{
		temp1 = temp1->next;
		num1++;
	}

	while (temp2 != nullptr)
	{
		temp2 = temp2->next;
		num2++;
	}

	Node* p = l1.head_;
	Node* q = l2.head_;

	if (num1 >= num2)
	{
		while (num1 - num2 > 0)
		{
			num1--;
			p = p->next;
		}
	}
	else
	{
		while (num2 - num1 > 0)
		{
			num2--;
			q = q->next;
		}
	}

	while (p != nullptr)
	{
		if (p == q)
		{
			std::cout << "two linklists intersect , the pos is " << p << std::endl;
			return;
		}

		p = p->next;
		q = q->next;
	}

	std::cout << "the two linklists do not intersect" << std::endl;
}

void Joseph(LinkList& l, int num, int index)
{
	Node* fast = l.head_->next;
	Node* slow = l.head_;

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < index - 1; j++)
		{
			fast = fast->next;
			slow = slow->next;
		}

		std::cout << fast->val << " ";
		slow->next = fast->next;
		delete fast;
		fast = slow->next;
	}

	std::cout << std::endl;
}
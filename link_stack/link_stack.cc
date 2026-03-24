#include "link_stack.h"

LinkStack::LinkStack()
{
	head_ = new Node();
	head_->next = nullptr;
	head_->val = 0;
}

LinkStack::~LinkStack()
{
	Node* p = head_->next;
	while (p != nullptr)
	{
		head_->next = p->next;
		delete p;
		p = head_->next;
	}
}

void LinkStack::PushBack(int val)
{
	Node* p = new Node();
	p->val = val;
	p->next = head_->next;
	head_->next = p;
}

void LinkStack::PopBack()
{
	Node* p = head_->next;
	if (p == nullptr)
	{
		throw "link stack is empty!";
	}
	else
	{
		head_->next = p->next;
		delete p;
		p = nullptr;
	}
}
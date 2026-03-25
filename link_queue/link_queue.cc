#include "link_queue.h"

LinkQueue::LinkQueue()
{
	head_ = new Node();
	rear_ = new Node();
	head_->pre = nullptr;
	rear_->next = nullptr;
	head_->next = rear_;
	rear_->pre = head_;
}

LinkQueue::~LinkQueue()
{
	Node* p = head_->next;
	while (p != rear_)
	{
		head_->next = p->next;
		delete p;
		p = head_->next;
	}
	delete head_;
	delete rear_;
	head_= nullptr;
	rear_= nullptr;
}

void LinkQueue::Enqueue(int val)
{
	Node* p = new Node();
	p->val = val;
	p->next = head_->next;
	p->pre = head_;
	head_->next->pre = p;
	head_->next = p;
}

void LinkQueue::Dequeue()
{
	if (head_->next == rear_)
	{
		throw "LinkQueue is empty";
	}

	Node* p = rear_->pre;
	rear_->pre = p->pre;
	rear_->pre->next = rear_;
	delete p;
	p = nullptr;
}
#include "circle_queue.h"

CircleQueue::CircleQueue(int capacity = 10)
	: capacity_(capacity)
	, front_(0)
	, rear_(0)
{
	p_ = new int[capacity];
}

CircleQueue::~CircleQueue()
{
	delete[]p_;
	p_ = nullptr;
}

void CircleQueue::Expand(int capacity)
{
	int* p = new int[capacity];
	memcpy(p, p_, sizeof(int) * capacity_);
	delete[]p_;
	p_ = p;
}

void CircleQueue::Enqueue(int val)
{
	p_[rear_] = val;
	rear_ = ++rear_ % capacity_;

	if (rear_ == front_)
	{
		Expand(2 * capacity_);
	}
}

void CircleQueue::Dequeue()
{
	front_ = ++front_ % capacity_;
}
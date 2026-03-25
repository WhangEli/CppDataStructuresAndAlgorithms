#include "circle_queue.h"

CircleQueue::CircleQueue(int capacity = 10)
	: capacity_(capacity)
	, front_(0)
	, rear_(0)
{
	arr_ = new int[capacity];
}

CircleQueue::~CircleQueue()
{
	delete[]arr_;
	arr_ = nullptr;
}

void CircleQueue::Expand(int capacity)
{
	int* p = new int[capacity];
	memcpy(p, arr_, sizeof(int) * capacity_);
	delete[]arr_;
	arr_ = p;
}

void CircleQueue::Enqueue(int val)
{
	arr_[rear_] = val;
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
#include "sequence_stack.h"

SequenceStack::SequenceStack(int capacity)
	: capacity_(capacity)
	, size_(0)
{
	top_ = new int[capacity];
}

SequenceStack::~SequenceStack()
{
	delete[]top_;
	top_ = nullptr;
}

void SequenceStack::PushBack(int val)
{
	if (size_ == capacity_)
	{
		Expend(2*capacity_);
	}

	top_[size_++] = val;
}

void SequenceStack::PopBack()
{
	size_--;
}

void SequenceStack::Expend(int capacity)
{
	int* p = new int[capacity];
	memcpy(p, top_, sizeof(int) * capacity_);
	delete[]top_;
	top_ = p;
}
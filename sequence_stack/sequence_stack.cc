#include "sequence_stack.h"

SequenceStack::SequenceStack(int capacity = 10)
	: capacity_(capacity)
	, top_(0)
{
	p_ = new int[capacity];
}

SequenceStack::~SequenceStack()
{
	delete[]p_;
	p_ = nullptr;
}

void SequenceStack::PushBack(int val)
{
	if (top_ == capacity_)
	{
		Expend(2*capacity_);
	}

	p_[top_++] = val;
}

void SequenceStack::PopBack()
{
	if (IsEmpty())
	{
		throw "sequence stack is empty!";
	}
	else
	{
		top_--;
	}
}

bool SequenceStack::IsEmpty()
{
	if (top_ == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int SequenceStack::GetTop()
{
	if (IsEmpty())
	{
		throw "sequence stack is empty!";
	}
	else
	{
		return p_[top_ - 1];
	}
}

int SequenceStack::GetSize()
{
	return top_;
}

void SequenceStack::Expend(int capacity)
{
	int* p = new int[capacity];
	memcpy(p, p_, sizeof(int) * capacity_);
	delete[]p_;
	p_ = p;
	capacity_ = capacity;
}
#include "array.h"

Array::Array(int capacity) :p_(nullptr), capacity_(capacity), size_(0)
{
	p_ = new int[capacity];
}

Array::~Array()
{
	delete[] p_;
	p_ = nullptr;
}

void Array::PrintArray()
{
	for (int i = 0; i < size_; i++)
	{
		std::cout << p_[i] << " ";
	}

	std::cout << std::endl;
}

void Array::PushBack(int val)
{
	if (size_ == capacity_)
	{
		Expand(2 * capacity_);
	}
	
	p_[size_] = val;
	size_++;
}

void Array::Insert(int num, int val)
{
	if (size_ == capacity_)
	{
		Expand(2 * capacity_);
	}

	for (int i = size_; i >= num; i--)
	{
		p_[i] = p_[i - 1];
	}

	p_[num - 1] = val;
	size_++;
}

void Array::PopBack()
{
	if (size_ == 0)
	{
		std::cout << "array is null,can not pop back" << std::endl;
		return;
	}

	p_[size_ - 1] = 0;
	size_--;
}

void Array::Remove(int num)
{
	if (num < 0 || num > size_)
	{
		std::cout << "the " << num << " -th can not be removed" << std::endl;
		return;
	}

	for (int i = num; i < size_; i++)
	{
		p_[i - 1] = p_[i];
	}

	size_--;
}

int Array::FindVal(int val)
{
	for (int i = 0; i < size_; i++)
	{
		if (p_[i] == val)
		{
			return i;
		}
	}

	std::cout << "can not find the element" << val << std::endl;
	return -1;
}

void Array::UpdateVal(int val, int newVal)
{
	int i = FindVal(val);
	if (i != -1)
	{
		p_[i] = newVal;
	}
}

void Array::Expand(int capacity)
{
	int* p = new int[capacity];
	memcpy(p, p_, sizeof(int) * capacity_);
	delete[]p_;
	p_ = p;
	capacity_ = capacity;
}

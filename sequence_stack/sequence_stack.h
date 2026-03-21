#pragma once
#include <iostream>

class SequenceStack
{
public:
	SequenceStack(int capacity);
	~SequenceStack();

public:
	void PushBack(int val);
	void PopBack();

private:
	void Expend(int capacity);

private:
	int* top_;
	int capacity_;
	int size_;
};


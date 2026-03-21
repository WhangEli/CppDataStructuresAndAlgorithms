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
	bool IsEmpty();
	int GetTop();
	int GetSize();

private:
	void Expend(int capacity);

private:
	int* p_;
	int top_;
	int capacity_;
};
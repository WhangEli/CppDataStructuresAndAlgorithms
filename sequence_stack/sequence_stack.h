#pragma once
#include "sequence_stack.h"

class SeqStack
{
public:
	SeqStack();
	~SeqStack();

public:
	void PushBack();
	void PopBack();

private:
	int top_;
};


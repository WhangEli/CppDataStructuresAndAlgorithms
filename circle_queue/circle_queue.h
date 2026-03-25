#pragma once
#include <iostream>

class CircleQueue
{
public:
	CircleQueue(int capacity);
	~CircleQueue();

public:
	void Enqueue(int val);
	void Dequeue();

private:
	void Expand(int capacity);

private:
	int* arr_;
	int front_;
	int rear_;
	int capacity_;
};


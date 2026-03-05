#pragma once
class Array
{
public:
	Array(int cap) :mCapacity(cap), mSize(0)
	{
		mpArr = new int[cap]();
	}

	~Array()
	{
		delete[] mpArr;
		mpArr = nullptr;
	}

public:
	

private:
	int* mpArr;
	int mCapacity;
	int mSize;
};


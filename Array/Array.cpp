#include "Array.h"

Array::Array(int cap) :mpArr(nullptr), mCapacity(cap), mSize(0)
{
	mpArr = new int[cap];
}

Array::~Array()
{
	delete[]mpArr;
	mpArr = nullptr;
}

void Array::printArray()
{
	for (int i = 0; i < mSize; i++)
	{
		std::cout << mpArr[i] << " ";
	}

	std::cout << std::endl;
}

void Array::push_back(int val)
{
	if (mSize == mCapacity)
	{
		expand(2 * mCapacity);
	}
	
	mpArr[mSize] = val;
	mSize++;
}

void Array::insert(int num, int val)
{
	if (mSize == mCapacity)
	{
		expand(2 * mCapacity);
	}

	for (int i = mSize; i >= num; i--)
	{
		mpArr[i] = mpArr[i - 1];
	}

	mpArr[num - 1] = val;
	mSize++;
}

void Array::pop_back()
{
	if (mSize == 0)
	{
		std::cout << "array is null,can not pop back" << std::endl;
		return;
	}

	mpArr[mSize - 1] = 0;
	mSize--;
}

void Array::remove(int num)
{
	if (num < 0 || num > mSize)
	{
		std::cout << "the " << num << " -th can not be removed" << std::endl;
		return;
	}

	for (int i = num; i < mSize; i++)
	{
		mpArr[i - 1] = mpArr[i];
	}

	mSize--;
}

int Array::findVal(int val)
{
	for (int i = 0; i < mSize; i++)
	{
		if (mpArr[i] == val)
		{
			return i;
		}
	}

	std::cout << "can not find the element" << val << std::endl;
	return -1;
}

void Array::updateVal(int val, int newVal)
{
	int i = findVal(val);
	if (i != -1)
	{
		mpArr[i] = newVal;
	}
}

void Array::expand(int cap)
{
	int* p = new int[cap];
	memcpy(p, mpArr, sizeof(int) * mCapacity);
	delete[]mpArr;
	mpArr = p;
	mCapacity = cap;
}

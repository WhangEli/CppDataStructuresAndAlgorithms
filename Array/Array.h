#pragma once
#include <iostream>

class Array
{
public:
	Array(int cap);

	~Array();
public:
	void printArray();
	void push_back(int val);
	void insert(int num, int val);
	void pop_back();
	void remove(int num);
	int findVal(int val);
	void updateVal(int val, int newVal);

private:
	void expand(int newCap);

private:
	int* mpArr;
	int mCapacity;
	int mSize;
};


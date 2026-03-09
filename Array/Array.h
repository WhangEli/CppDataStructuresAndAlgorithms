#pragma once
#include <iostream>

class Array
{
public:
	Array(int cap);
	~Array();

public:
	void printArray();	//print the val of the array
	void push_back(int val);	//add a element at the end of the array
	void insert(int num, int val);	//add a element at the num-th of the array
	void pop_back();	//remove a element at the end of the array
	void remove(int num);	//remove the num-th element of the array
	int findVal(int val);	//find and return the first element which is equal to val
	void updateVal(int val, int newVal);	//trun the val of the first element which is equal to val into newVal

private:
	void expand(int cap);

private:
	int* mpArr;
	int mCapacity;
	int mSize;
};
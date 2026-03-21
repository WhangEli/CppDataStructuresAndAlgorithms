#pragma once
#include <iostream>

class Array
{
public:
	Array(int capacity);
	~Array();

public:
	void PrintArray();
	void PushBack(int val);  //add a element at the end of the array
	void Insert(int num, int val);  //add a element at the num-th of the array
	void PopBack();  //remove a element at the end of the array
	void Remove(int num);  //remove the num-th element of the array
	int FindVal(int val);  //find and return the first element which is equal to val
	void UpdateVal(int val, int newVal);  //trun the first val into newVal

private:
	void Expand(int capacity);  //expand the capacity of the array

private:
	int* p_;
	int capacity_;
	int size_;
};
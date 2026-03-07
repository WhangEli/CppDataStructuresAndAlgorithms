#include <iostream>

#include "Array/Array.h"

int main()
{
	Array arr(10);
	srand(time(0));

	for (int i = 0; i < 10; i++)
	{
		arr.push_back(rand() % 100);
	}
	arr.printArray();

	arr.insert(3, 10);
	arr.printArray();

	arr.push_back(100);
	arr.printArray();



	return 0;
}
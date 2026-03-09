#include <iostream>

#include "Array/Array.h"

int main()
{
	//init array
	Array arr(10);

	//add 10 elements
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		arr.push_back(rand() % 100);
	}
	arr.printArray();

	arr.insert(3, 10);
	arr.printArray();

	arr.push_back(100);
	arr.push_back(1);
	arr.printArray();

	arr.pop_back();
	arr.printArray();

	arr.remove(5);
	arr.printArray();

	arr.updateVal(100, 88);
	arr.updateVal(1000, 66);
	arr.printArray();

	std::cout << arr.findVal(88) << std::endl;
	std::cout << arr.findVal(1000) << std::endl;

	return 0;
}
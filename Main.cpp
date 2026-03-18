#include <iostream>

#include "Array/Array.h"
#include "LinkList/LinkList.h"

#if 0
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
#endif

int main()
{
	LinkList linkList;

	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		linkList.InsertTail(rand() % 100);
	}
	linkList.PrintLinkList();

	linkList.RemoveNode(1000);
	linkList.PrintLinkList();

	linkList.InsertHead(888);
	linkList.InsertHead(666);
	linkList.PrintLinkList();

	linkList.RemoveNode(888);
	linkList.PrintLinkList();

	linkList.UpdateVal(666, 999);
	linkList.PrintLinkList();

	linkList.SortedLinkList(11);
	linkList.PrintLinkList();

	LinkList linkList2;
	srand(time(0));
	for (int i = 0; i < 10; i++)
	{
		linkList2.InsertTail(rand() % 100);
	}
	linkList2.SortedLinkList(10);

	/*MergeSortedLinkList(linkList, linkList2);
	linkList.PrintLinkList();*/

	MergeTwoLinkList(linkList, linkList2);
	linkList.PrintLinkList();

	return 0;
}
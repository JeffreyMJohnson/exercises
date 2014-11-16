/*
Create a list that holds ints
	Populate the list with 30 random int values
	Find the smallest value, print it to the screen, and remove it.
	Repeat the second step until the list is empty.
*/
#include <iostream>
#include <list>
#include <time.h>

using namespace std;

ostream& operator<<(ostream& out, list<int>& l)
{
	out << "list [";
	for (list<int>::iterator it = l.begin(); it != l.end(); it++)
	{
		out << *it << ", ";
	}
	out << "]";
	return out;
}

void main()
{
	srand(time(nullptr));

	list<int> myList;
	for (int i = 0; i < 30; i++)
	{
		int v = rand() % 100;
		myList.push_front(v);
	}

	while (myList.size() > 0)
	{
		
		list<int>::iterator minPointer = myList.begin();
		int min = *minPointer;
		cout << "list:" << myList << endl;
		for (list<int>::iterator it = myList.begin(); it != myList.end(); it++)
		{
			if (*it < min)
			{
				min = *it;
				minPointer = it;
			}
		}

		cout << "minimum in list: " << min << endl;
		myList.erase(minPointer);
		system("pause");

	}
}
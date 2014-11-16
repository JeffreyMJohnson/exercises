/*
Create a program that allows the user to enter names into a console and store them as STL Strings within an STL List.

Give the user the options to:
Add Name to the list, sorted alphabetically, using insertion.
Display Names using an iterator
Remove Name At

Remove Specific Name
*/

#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

list<string> myList;

void UserOptionsDisplay();
int GetUserInput();
bool Update();

class NameDB
{
public:
	bool AddName(const string& a_name)
	{
		if (dBase.size() == 0)
		{
			dBase.push_front(a_name);
			return true;
		}

		list<string>::iterator insertPos = find(dBase.begin(), dBase.end(), a_name);
		if (insertPos != dBase.end())//name already there
			return false;

		insertPos = GetSortPosition(a_name);
		dBase.insert(insertPos, a_name);
		return true;

	}
private:
	list<string> dBase;

	/*
	returns iterator of position where given a_name param would be inserted to keep list sorted 
	NOTE:assumes given name is not in list and list has more than zero entries already
	*/
	list<string>::iterator GetSortPosition(const string& a_name)
	{
		for (list<string>::iterator it = dBase.begin(); it != dBase.end(); it++)
		{
			int compare = a_name.compare(*it);

			if (compare > 0)//a_name larger than data base name
			{
				if (it == dBase.begin())
					//first element so this is the spot
					return it;
				else
				{
					//at least second element so return previous
					return --it;
				}
			}
		}
		//end of list so a_name must be last
		return dBase.end();
	}
};

void main()
{
	NameDB myDB;
	cout << myDB.AddName("foo") << endl;
	cout << myDB.AddName("bar") << endl;
	cout << myDB.AddName("foo") << endl;
	

	//cout << "Name Database\n\n";
	//bool quit = false;
	//while (!quit)
	//{
	//	quit = Update();
	//}
}

void UserOptionsDisplay()
{
	cout << "options:\n";
	cout << "1. Add name to list\n";
	cout << "2. Display list\n";
	cout << "3. Remove name at\n";
	cout << "4. Remove specific name\n";
	cout << "5. Quit\n\n";
	cout << "?:\n";
}

int GetUserInput()
{
	int choice;
	while (true)
	{
		cin >> choice;
		if (choice < 1 || choice > 5)
		{
			cout << "INVALID CHOICE\n";
			return 5;
			UserOptionsDisplay();
		}
		else
		{
			return choice;
		}

	}
}

bool Update()
{
	UserOptionsDisplay();
	int choice = GetUserInput();

	switch (choice)
	{
	case 1:
		//add name
		break;
	case 2:
		//display list
		break;
	case 3:
		//remove name at
		break;
	case 4:
		//remove specific name
		break;
	case 5:
		//quit
		return true;
	}

	return false;

}
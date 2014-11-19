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
#include <map>

using namespace std;

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
		dBase.push_back(a_name);
		dBase.sort();
		return true;
	}

	friend ostream& operator<<(ostream& out, NameDB& d)
	{
		cout << "NameDB [";
		for (list<string>::iterator it = d.dBase.begin(); it != d.dBase.end(); it++)
		{
			cout << *it << ", ";
		}
		cout << "]";
		return cout;
	}

	void DisplayNames()
	{
		cout << "All names in database\n\n";
		for (list<string>::iterator it = dBase.begin(); it != dBase.end(); it++)
		{
			cout << *it << endl;
		}
		cout << "\n\n";
	}

	string RemoveName(const int position)
	{
		if (position > dBase.size() - 1)
			return string("");
		list<string>::iterator it = dBase.begin();
		for (int i = 0; i <= position; i++)
		{
			it++;
		}
		string s = *it;
		dBase.erase(it);
		return s;
	}
private:
	list<string> dBase;
};

NameDB myDB;

void Foo(){
	cout << "foo" << endl;
}

void Bar()
{
	cout << "bar" << endl;
}

typedef void (*Func)(void);


void main()
{
	map<string, Func> myMap;
	myMap["foo"] = &Foo;
	myMap["bar"] = &Bar;

	myMap["foo"]();
	myMap["bar"]();

	//
	//cout << "Name Database\n\n";
	//bool quit = false;
	//while (!quit)
	//{
	//	quit = Update();
	//}
	//cout << myDB << endl;
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
	string name = "";
	switch (choice)
	{
	case 1:
		//add name
		cout << "enter name to add: ";
		cin.ignore();
		getline(cin, name);
		if (myDB.AddName(name))
		{
			cout << "name added to database\n";
		}
		else
		{
			cout << "error, name not added to database.\n";
		}
		break;
	case 2:
		//display list
		myDB.DisplayNames();

		break;
	case 3:
		//remove name at
		cout << "what position (zero based) do you want removed?\n";
		cin.ignore();
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
// container_algorithms.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

ostream& operator<<(ostream& out, const vector<int>& vec)
{
	out << "vector [ ";
	for (int i = 0; i < vec.size(); i++)
	{
		out << vec[i];
		if (i != vec.size() - 1)
		{
			out << ", ";
		}
	}
	out << "]";
	return out;
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> v;
	for (int i = 1; i < 101; i++)
	{
		v.push_back(i);
	}
	cout << v << endl;

	random_shuffle(v.begin(), v.end());
	cout << v << endl;
	make_heap(v.begin(), v.end());
	cout << v << endl;
	system("pause");
	return 0;
}


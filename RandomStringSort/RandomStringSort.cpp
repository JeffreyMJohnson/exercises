#include <string>
#include <vector>
#include <limits>
#include <time.h>
#include <iostream>

using namespace std;

string RandomSort(const string& s)
{
	vector<char> v;
	string result;
	srand(time(nullptr));
	for (int i = 0; i < s.size(); i++)
	{
		v.push_back(s[i]);
	}
	int i = 0;
	while (v.size() > 0)
	{
		//get random index
		int index = rand() % v.size();
		//get iterator of same position
		vector<char>::iterator it = v.begin() + index;
		//set result
		result.push_back(v[index]);
		//remove value
		v.erase(it);
	}
	return result;
}

void main(){
	string s = "typewriter";
	string randS = RandomSort(s);
	float start = time(nullptr);
	while (!(randS == "eeiprttwy"))
	{
		s = RandomSort(s);
	}
	float end = time(nullptr);
	cout << "it took " << end - start << " seconds\n";
	system("pause");
}

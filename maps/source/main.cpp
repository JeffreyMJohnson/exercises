/*
Create a program that:
Loads and reads through the text file
Reads each word and
Stores in a std::map the total count of each word
Stores in a std::set a list of every word used
Stores in a :std::multimap a count of each word.
Once the file has been read and parsed
Output the data to another file

parse line
tokenize by whitespace (minus whitespace)
remove token (plus whitespace) from list
loop until line size == 0 OR whitespace search returns none (substr from 0 - size-1) last token of line
*/

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>

using namespace std;



void main()
{
	map<string, int> countTotal;
	set<string> wordList;
	multimap<string, int> wordCount;

	fstream in;
	in.open(".\\resources\\AesopsFables.txt", ios_base::in);
	cout << "open: " << in.is_open() << endl;
	if (in.is_open())
	{
		string line;
		while (!in.eof())
		{
			getline(in, line);
			cout << line;
			while (line.size() > 0)
			{
				int pos = 0;
				int wPos = 0;
				string token = "";
				wPos = line.find(' ');
				if (wPos != string::npos)
				{
					token = line.substr(0, wPos);
					line.erase(0, wPos + 1);

				}
				else
				{
					token = line.substr(0, line.size());
					line.clear();
				}
				cout << "line: " << line << endl;
				cout << "wPos: " << wPos << endl;
				cout << "token: " << token << endl;
				system("pause");
			}

		}
	}


	system("pause");
	in.close();
}
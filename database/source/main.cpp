#include "sqlite3.h"
#include <string>
#include <iostream>

using namespace std;

static int CallBack(void* notUsed, int numArgs, char** data, char** columnName)
{
	float myFloat = 4.0f;
	for (int i = 0; i < numArgs; ++i)
	{
		cout << columnName[i] << ": " << data[i] << endl;
	}
	return 0;
}

void main()
{
	sqlite3*  myDB = nullptr;

	sqlite3_open("TestDB.db", &myDB);

	char* errorMsg = nullptr;
	string sqlStatement = "CREATE TABLE TEST("\
		"NAME TEXT, "\
		"AGE INT);";

	//execute query
	sqlite3_exec(myDB, sqlStatement.c_str(), CallBack, 0, &errorMsg);

	if (errorMsg != nullptr)
	{
		cout << "Error message: " << errorMsg << endl;
	}

	errorMsg = nullptr;

	sqlStatement = "REPLACE INTO TEST(NAME, AGE)"\
		"VALUES ('JASON', 99);";

	sqlite3_exec(myDB, sqlStatement.c_str(), CallBack, 0, &errorMsg);

	if (errorMsg != nullptr)
	{
		cout << "error message: " << errorMsg << endl;
	}

	errorMsg = nullptr;
	sqlStatement = "SELECT NAME FROM TEST;";
	sqlite3_exec(myDB, sqlStatement.c_str(), CallBack, 0, &errorMsg);

	if (errorMsg != nullptr)
	{
		cout << "error message: " << errorMsg << endl;
	}

	sqlite3_close(myDB);

	system("pause");

}
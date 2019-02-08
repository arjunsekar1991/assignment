// project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"




using namespace std;

void testCopyConstructor(Sequence);

int main()
{
	try
	{
		{
			Sequence data(4);
			// remove below line
		/*	data[0] = 100;
			data[1] = 200;
			cout << "before calling testCopyConstructor: " << data << endl;
			testCopyConstructor(data);
			cout << "after calling testCopyConstructor: " << data << endl;*/
		}

		{
		/*	Sequence data(4);
			data[5] = 100;*/
		}
	}
	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
}

void testCopyConstructor(Sequence s)
{
/*	cout << "inside testCopyConstructor: " << s << endl;
	s[0] = -1;*/
}
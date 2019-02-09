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
			/* sequence copy test*/
			Sequence data(4);

			data[0] = 100;
			data[1] = 200;
			Sequence data2(data);
			data[0] = 0;
			cout << data2[0] << "  sequence copied successfully?"<<endl;
		}

		{
			/* sequence assignment operator test*/
			Sequence data(2);

			data[0] = 100;
			data[1] = 200;
			Sequence data2=data;
			data[0] = 0;
			cout << data2[0] << "  sequence assignment  worked successfully?"<<endl;
		}
		{
			Sequence data(4);
			
			data[0] = 100;
			data[1] = 200;
			
			cout << "before calling testCopyConstructor: " << data << endl;
			testCopyConstructor(data);
			cout << "after calling testCopyConstructor: " << data << endl;
		}
		//this looks like bounce check block 
		{
		/*	Sequence data(4);
			data[5] = 100;*/
		}
		//at member function test method
		{
			Sequence data(2);
			data[0] = 100;
			cout << "At method works ? "<<data.at(0);
			cout << "At method fails?" << data.at(2);
		}
		
	}
	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
}

void testCopyConstructor(Sequence s)
{
	cout << "inside testCopyConstructor: " << s << endl;
	s[0] = -1;
}
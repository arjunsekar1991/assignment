// project1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"




using namespace std;

void testCopyConstructor(Sequence);

int main()
{
	try
	{

		
			/* sequence copy test*/
			Sequence data(4);

			data[0] = 100;
			data[1] = 200;
			Sequence data2(data);
			data[0] = 0;
			cout << data2[0] << "  sequence copied successfully?"<<endl;
		
	}
	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
	try{
		
			/* sequence assignment operator test*/
			Sequence data(2);

			data[0] = 100;
			data[1] = 200;
			Sequence data2=data;
			data[0] = 0;
			cout << data2[0] << "  sequence assignment  worked successfully?"<<endl;
		
	}
	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
	try{
		
			Sequence data(4);
			
			data[0] = 100;
			data[1] = 200;
			
			cout << "before calling testCopyConstructor: " << data << endl;
			testCopyConstructor(data);
			cout << "after calling testCopyConstructor: " << data << endl;
		
	}
	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
		//this looks like bounce check block 
		{
		/*	Sequence data(4);
			data[5] = 100;*/
		}
		
		
		//push back method test method 
	try{
		
			Sequence data(1);
			data[0] = 0;
			data.push_back(100);
			cout << "is the push back method work" <<data[1]<<endl;
		
	}
	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
		//at member function test method
	try
		{
			Sequence data(2);
			data[0] = 100;
			cout << "At method works ? " << data.at(0);
			cout << "At method fails?" << data.at(2);
		
	}
	catch (exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}

	// pop back member function test method
	try {

		Sequence data(2);
		data[0] = 100;
		data[1] = 200;
		data.pop_back();
		cout << "popback function test" << endl;
		cout << "value at index 0 is" << data[0] << endl;
		cout << "end of popack test" << endl;
		cout << "after pop size reduced from 2 to" << data.size()<<endl;
		cout << "did i get invalid index " << data[1] << endl;



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
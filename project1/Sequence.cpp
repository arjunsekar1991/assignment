//#include "Sequence.h"
#include "pch.h"

//using namespace std;
Sequence::Sequence(size_type sz)
{
	numElts = sz;
	elts = new value_type[sz];
	for (size_type i = 0; i < numElts; i++)
		//need to intialize as undefined right now let it be 0
		elts[i] =0;

}

Sequence::~Sequence()
{
	delete[] elts;
}

Sequence::Sequence(const Sequence& s)
{
	numElts = s.numElts;
	elts = new value_type[numElts];
	for (size_type i = 0; i < numElts; i++)
		elts[i] = s.elts[i];
	

}

Sequence::value_type& Sequence::operator[](size_type position)
{
	return elts[position];
}

Sequence& Sequence::operator=(const Sequence& s)
{
	if (this != &s)
	{
		delete[] elts;

		numElts = s.numElts;
		elts = new value_type[numElts];
		for (int i = 0; i < numElts; i++)
		{
			elts[i] = s.elts[i];
		}
	}

	return *this;
}
/*






Sequence::value_type& Sequence::at(size_type position)
{
}

void Sequence::push_back(const value_type& value)
{
}

void Sequence::pop_back()
{
}

void Sequence::insert(size_type position, value_type value)
{
}

const Sequence::value_type& Sequence::front() const
{
}

const Sequence::value_type& Sequence::back() const
{
}

bool Sequence::empty() const
{
}

Sequence::size_type Sequence::size() const
{
}

void Sequence::clear()
{
}

void Sequence::erase(size_type position, size_type count)
{
}

ostream& Sequence::print(ostream& os)
{
}

*/
ostream& operator<<(ostream& os, Sequence& s)
{
	os << s;
	return os;
}
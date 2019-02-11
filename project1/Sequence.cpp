#include "pch.h"

Sequence::Sequence(size_type sz)
{
	numElts = sz;
	elts = new value_type[sz];
	for (size_type i = 0; i < numElts; i++)
		//need to intialize as undefined right now let it be 0
		elts[i] = 0;
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
	if (position >= numElts){
		throw exception("invalid sequence index");
	}
	return elts[position];
}

Sequence& Sequence::operator=(const Sequence& s){
	if (this != &s){
		delete[] elts;
		numElts = s.numElts;
		elts = new value_type[numElts];
		
		for (value_type i = 0; i < numElts; i++){
			elts[i] = s.elts[i];
		}
	}

	return *this;
}
Sequence::value_type& Sequence::at(size_type position){
	
	if (position >= numElts){
		throw exception("invalid sequence index");
	}
	return elts[position];
}

void Sequence::push_back(const value_type& value){
	
	value_type * tempElts = new value_type[numElts+1];
	
	for (size_type i = 0; i < numElts; i++)
		tempElts[i] = elts[i];

	tempElts[numElts] = value;
	delete[] elts;
	elts = tempElts;
	numElts++;
}

void Sequence::pop_back(){
	
	value_type * tempElts = new value_type[numElts - 1];
	
	for (size_type i = 0; i < numElts-1; i++)
		tempElts[i] = elts[i];

	delete[] elts;
	elts = tempElts;
	numElts--;
	
}

Sequence::size_type Sequence::size() const{
	return this->numElts;
}

const Sequence::value_type& Sequence::front() const{
	return this->elts[0];
}

const Sequence::value_type& Sequence::back() const{
	return this->elts[numElts-1];
}

bool Sequence::empty() const{

	if (numElts > 0){
	  return false; 
	}
	else{
		return true;
	}
}

void Sequence::clear()
{
	 elts=nullptr;
	 numElts = 0;
}

void Sequence::insert(size_type position, value_type value)
{
	if (position >= 0 && position <numElts){
		numElts++;
		value_type * tempElts = new value_type[numElts + 1];
	
		if (position > 0 && position < numElts - 1) {
			
			for (size_type i = 0; i < position; i++)
			tempElts[i] = elts[i];

			tempElts[position] = value;
			size_type j = position;

			for (size_type i = position + 1; i < numElts; i++){
			tempElts[i] = elts[j];
			j++;
			}
		}

	if (position == 0) {
	
		tempElts[0] = value;
		size_type k = 0;

		for (size_type i = 1; i < numElts; i++){
			tempElts[i] = elts[k];
			k++;
		}
	}

	if (position == numElts-1) {
		cout << "inserting tail" << endl;
		
		for (size_type i = 0; i < numElts-3; i++){
			tempElts[i] = elts[i];
			
		}
		
		tempElts[numElts-2]=elts[numElts-3];
		tempElts[numElts - 1] = value;
	}
	
	delete [] elts;
	elts = tempElts;
	}
	else{
		throw exception("invalid sequence index");
	}
	
}

void Sequence::erase(size_type position, size_type count)
{
	size_type last_index = numElts - 1;
	if (position >= 0 && position + count - 1 <= last_index) {
	value_type * tempElts = new value_type[numElts - count];

	//	size_type lastElementIndex = numElts - 1;
		for (size_type i = 0; i < position; i++) {
		tempElts[i] = elts[i];
		//cout << tempElts[i];
		}
		int j = position;
		for (size_type i = position + count; i < numElts; i++) {
			tempElts[j] = elts[i];
		j++;
		}
	delete[] elts;
	elts = tempElts;
	}
}


 ostream& operator<<(ostream& os, Sequence& s){

	for (Sequence::size_type i = 0; i < s.numElts; i++)
		//need to intialize as undefined right now let it be 0
		os<<s.elts[i];
	return os;
}
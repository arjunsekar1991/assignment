#include "pch.h"

//may be this is correct
Sequence::Sequence(size_type sz)
{
	numElts = sz;
	
	for (size_type i = 0; i < numElts; i++) {
	
	if ( i == 0) {
		SequenceNode *currentNode = new SequenceNode();
		/*sN->prev = NULL;
		sN->elt = 0;
		sN->next= new SequenceNode();*/
		
		currentNode->prev = NULL;
	//	currentNode->next = new SequenceNode(); 
		currentNode->elt = 0;
		head = currentNode;
		tail = currentNode;
		

	}
	
	if( i>0 && i<numElts){
		SequenceNode *currentNode = new SequenceNode();
		currentNode->elt = 0;
		currentNode->prev = tail;
		tail->next = currentNode;
		tail = currentNode;

	}
 }
}
Sequence::value_type& Sequence::operator[](size_type position)
{
	SequenceNode *current = head;
	for (size_type i = 0; i <= position; i++)
		current = current->next;
	return current->elt;
}
//test 2
/*
Sequence::Sequence(const Sequence& s)
{

}

Sequence::~Sequence()
{
}

Sequence& Sequence::operator=(const Sequence& s)
{
}



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


*/
 ostream& operator<<(ostream& os, Sequence& s)
{
	 for (Sequence::size_type i = 0; i < 3; i++)
		 //need to intialize as undefined right now let it be 0
	 {
		 os << s[i];
		 s.print(os);
	 }
	return os;
}

 ostream& Sequence::print(ostream& os)
 {
	 os << ",";
	 return os;
 }


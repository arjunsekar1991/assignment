#include "pch.h"

Sequence::Sequence(size_type sz)
{
	numElts = sz;
	if(numElts>0)
	{
		for (size_type i = 0; i < numElts; i++) 
		{
			if ( i == 0) {
				SequenceNode *currentNode = new SequenceNode();
				currentNode->prev = NULL;
				currentNode->elt = 0;
				head = currentNode;
				tail = currentNode;
			}
			if (i > 0 && i < numElts) {
				SequenceNode *currentNode = new SequenceNode();
				currentNode->elt = 0;
				currentNode->prev = tail;
				tail->next = currentNode;
				tail = currentNode;
			}
		}
	}
	else 
	{
				head = tail = NULL;
	}
}

Sequence::value_type& Sequence::operator[](size_type position)
{
	SequenceNode *current = head;
	for (size_type i = 0; i < position; i++)
		current = current->next;
	return current->elt;
}

Sequence::~Sequence()
{
	SequenceNode *currentNode;
	for (size_type i = 0; i < numElts; i++) 
	{
		currentNode = head;
		if (head->next != NULL)
		{
			
			head = head->next;
			delete(currentNode);
		}

	}
		
	numElts = 0;
	head = tail = NULL;
	delete head;
	delete tail;
}
void Sequence::push_back(const value_type& value)
{
	SequenceNode *currentNode = new SequenceNode();
	currentNode->elt = value;
	numElts++;
	//cout << "tail value" << tail->elt<<endl;
	if (head == NULL) 
	{
		currentNode->prev = NULL;
		head =tail= currentNode;
		return;
	}
	tail->next =currentNode;
	tail = currentNode;
	currentNode->next = NULL;
}



void Sequence::pop_back()
{
	SequenceNode *currentNode ;
	if (tail == NULL)
	{
		throw exception("sequence is empty pop_back failed :)");
	}
	currentNode = tail->prev;
	delete tail;
	tail = currentNode;
	numElts --;
	
}

const Sequence::value_type& Sequence::front() const 
{

	if (numElts==0) 
	{
		throw exception("Invalid index :)");
	}
	else
	{
		return head->elt;
	}
	
}

const Sequence::value_type& Sequence::back() const
{
	if (numElts == 0) {
		throw exception("Invalid index :)");
	}
	else
	{
		return tail->elt;
	}
}
bool Sequence::empty() const
{
	if (numElts > 0) 
	{
		return false;
	}
	else
	{
		return true;
	}
}

Sequence::size_type Sequence::size() const
{
	return numElts;
}

void Sequence::clear()
{

	cout << "clear function "<<numElts;
	SequenceNode *currentNode = head;
	for (size_type i = 0; i < numElts; i++)
	{
		cout << "clear function " << numElts<<endl;
		head = head->next;
		currentNode= nullptr ;
		currentNode=head;
	}
	numElts = 0;
	head = tail = nullptr;
}

Sequence& Sequence::operator=(const Sequence& s)
{
	if (this != &s) 
	{
		this->numElts = s.numElts;
		SequenceNode *currentNode = new SequenceNode();

		for (size_type i = 0; i < s.numElts; i++)
		{
			if (i == 0) 
			{
				SequenceNode *tempNode = new SequenceNode();
				currentNode = s.head;
				tempNode->prev = NULL;
				tempNode->elt = currentNode->elt;
				this->head = tempNode;
				this->tail = this->head;
			}

			if (i > 0 && i < numElts) 
			{
				SequenceNode *tempNode = new SequenceNode();
				currentNode = currentNode->next;
				tempNode->elt = currentNode->elt;
				tempNode->prev = this->tail;
				this->tail->next = tempNode;
				this->tail = tempNode;
			}
		}
	}

	return *this;
}

Sequence::Sequence(const Sequence& s)
{
	this->numElts = s.numElts;
	SequenceNode *currentNode = new SequenceNode();
	
	for (size_type i = 0; i < s.numElts; i++)
	{

		if (i == 0)
		{
			SequenceNode *tempNode = new SequenceNode();
			currentNode = s.head;
			tempNode->prev = NULL;
			tempNode->elt = currentNode->elt;
			this->head = tempNode;
			this->tail = this->head;
		}

		if (i > 0 && i < numElts) 
		{
			SequenceNode *tempNode = new SequenceNode();
			currentNode = currentNode->next;
			tempNode->elt = currentNode->elt;
			tempNode->prev = this->tail;
			this->tail->next = tempNode;
			this->tail = tempNode;
		}
	}
}

void Sequence::insert(size_type position, value_type value)
{
	if (position > numElts - 1) 
	{
		throw exception("Invalid Index");
	}

	if (position == 0) 
	{
		SequenceNode *tempNode = new SequenceNode();
		
		tempNode->prev = NULL;
		tempNode->elt = value;
		tempNode->next = head;
		this->head = tempNode;
		numElts++;
	}
	if (position > 0 && position < numElts - 1) 
	{
		SequenceNode *current = head;
		SequenceNode *currentPlusOne;
		SequenceNode *tempNode = new SequenceNode();
	
		for (size_type i = 0; i < position - 1; i++) 
		{
			current = current->next;
		}
		currentPlusOne = current->next;
		tempNode->elt = value;
		current->next = tempNode;

		tempNode->next = currentPlusOne;
		tempNode->prev = current;
		tempNode->prev = current->next;
		numElts++;

	}
	if (position == numElts - 1) 
	{
		this->push_back(value);
	}
	

}

void Sequence::erase(size_type position, size_type count)
{
	SequenceNode *currentFirstHalf = head;
	for (size_type i = 0; i < position; i++) 
	{
		cout << "First half" <<currentFirstHalf->elt << endl;
		currentFirstHalf = currentFirstHalf->next;

	}

	SequenceNode *deleteNodes = head;
	for (size_type i = 0; i < position + count; i++) {
		if (i > position - 1)
			cout << "Delete  nodes" << deleteNodes->elt << endl;
		deleteNodes = deleteNodes->next;


	}
	//cout << currentFirstHalf->elt;
	SequenceNode *currentSecondHalf = head;
	for (size_type i = 0; i < numElts; i++)
	{
		if (i >= position + count) {
			cout << "second half" << currentSecondHalf->elt << endl;
		}
		
		currentSecondHalf = currentSecondHalf->next;
		

	}

	//currentFirstHalf->next = currentSecondHalf;
	
	currentFirstHalf = head;
	for (size_type i = 0; i < numElts; i++)
	{
		cout << "modified First half" << currentFirstHalf->elt << endl;
		currentFirstHalf = currentFirstHalf->next;

	}
	//cout << currentSecondHalf->elt;
}
//test 2
/*

*/
ostream& operator<<(ostream& os, Sequence& s)
{
	if (s.size() > 0) 
	{
	Sequence::size_type j = s.size() - 1;
	
		for (Sequence::size_type i = 0; i < s.size(); i++)	
		{
			os << s[i];
			if (j > 0) 
			{
				s.print(os);
				j--;
			}
		}
	}
	return os;
}

 ostream& Sequence::print(ostream& os)
 {
	 os << ",";
	 return os;
 }


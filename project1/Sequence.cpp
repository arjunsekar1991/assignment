#include <iostream>
#include <iomanip>
#include "sequence.h"

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
	currentNode->next = NULL;
	numElts++;
	//cout << "tail value" << tail->elt<<endl;
	if (head == NULL) 
	{
		currentNode->prev = NULL;
		head =tail= currentNode;
		return;
	}
	currentNode->prev = tail;
	tail->next =currentNode;
	tail = currentNode;
	currentNode->next = NULL;
}



void Sequence::pop_back()
{
	SequenceNode *currentNode=tail;
	if (tail == NULL||tail->prev==NULL)
	{
		throw exception("sequence is empty pop_back failed :)");
	}
	
	if(tail->prev!=NULL){
	currentNode = tail->prev;
	//delete currentNode->next;
	delete tail;
	tail = currentNode;
	tail->next = NULL;
	tail->prev = currentNode->prev;
	numElts--;
	}
	
	//tail->next = nullptr;
	
	
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

	
	SequenceNode *currentNode = head;
	for (size_type i = 0; i < numElts; i++)
	{
		head = head->next;
		delete currentNode;
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
		head->prev = tempNode;
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
		tempNode->next = currentPlusOne;
		tempNode->prev = current;
		
		current->next = tempNode;
		currentPlusOne->prev = tempNode;
		
		//tempNode->prev = current->next;

		
		numElts++;

	}
	if (position == numElts - 1) 
	{
		SequenceNode *tempNode = tail->prev;
		SequenceNode *newNode= new SequenceNode();
		tempNode->next = newNode;
		newNode->prev = tempNode;
		newNode->elt = value;
		newNode->next = tail;
		tail->prev = newNode;
		
	//	this->head = tempNode;
		numElts++;
	}
	

}

void Sequence::erase(size_type position, size_type count)
{
	if (position > numElts - 1 || numElts < count+position) 
	{
		throw exception("Invalid index");
	}
	if(position!=0&&position+count!=numElts)
	{

		SequenceNode *deleteNodes = head;
		SequenceNode *deleteNodesbefore = head;
		SequenceNode *deleteNodesAfter = head;
		SequenceNode *stepBack = nullptr;
	
	
		for (size_type i = 0; i < numElts; i++) {
		
			if (i < position-1) 
			{
			
				deleteNodesbefore = deleteNodesbefore->next;
				//subsequence increment
				deleteNodesAfter = deleteNodesAfter->next;
				deleteNodes = deleteNodes->next;
			
			}

			if (i > position - 1 && i< position + count+1)
			{
			
				deleteNodes = deleteNodes->next;
				if (i == position) {
					stepBack = deleteNodes;
					
				
				}
				//subsequenct increment
				deleteNodesAfter = deleteNodesAfter->next;
			
			}
			if(i == position + count+1){
				for (size_type i = count; i > 0; i--)
				{
					stepBack = stepBack->next;
				
					delete stepBack->prev;
				}

			
				deleteNodesbefore->next = deleteNodesAfter;
				deleteNodesAfter->prev = deleteNodesbefore;
				//deleteNodesAfter->prev = deleteNodesbefore->next;
			}
			
		
		}
	

	
		numElts = numElts - count;
	}
	if (position + count == numElts) {
		while(count>0){
			pop_back();
			count--;
		}
	}
	if (position == 0) {
		numElts = numElts - count;
		if (numElts - count > 2) {
		SequenceNode *currentNode = head;
		while (count > 0) {

			currentNode = currentNode->next;
			delete head;
			currentNode->prev = NULL;
			head = currentNode;
			count--;
		}
		}
		else {
			SequenceNode *currentNode = head;
			while (count > 0) {
				
				currentNode = currentNode->next;
				delete head;
				currentNode->prev = NULL;
				head = currentNode;
				
				count--;
			}
			tail = currentNode->next;
			
		}
		
	}
}

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
	 os << ", ";
	 return os;
 }


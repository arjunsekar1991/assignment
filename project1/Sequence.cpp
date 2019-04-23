#include <iostream>
#include <iomanip>
#include "sequence.h"
/* sequence constructor will initialize given number of sequence nodes in sequence object to zero
input sequence size output sequence object (parameterized constructor)
*/
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
//overloaded [] operator for getting the element value like an array
Sequence::value_type& Sequence::operator[](size_type position)
{
	SequenceNode *current = head;
	for (size_type i = 0; i < position; i++)
		current = current->next;
	return current->elt;
}
//destructor will destroy all the sequence nodes and delete all pointers like head tail
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
// input is value to be added to the sequence .. This method will add the element at the last of the sequence 
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


// This method will remove the element at the last of the sequence 
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
// This method will get the value of first element from the sequence object

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
// This method will get the value of last element from the sequence object
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
// This will check whether the sequence is empty or not
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
// this method will return the number of elements in the sequence object
Sequence::size_type Sequence::size() const
{
	return numElts;
}

// This will clear all the elements in the sequence object and set number of elements to zero
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
//overloading the = operator for the sequence object will allow us the enhanced assigment like s1 = s2 where s1 and s2 are sequence object
Sequence& Sequence::operator=(const Sequence& s)
{
	if (this != &s) 
	{
		this->numElts = s.numElts;
		SequenceNode *currentNode = new SequenceNode();
		//copying all the values that is avaible in the source sequence into the target sequence 
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
// copy constructor for the sequence
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
// insert function input position or index and value to be inserted
void Sequence::insert(size_type position, value_type value)
{
	// if postion > numElts-1 then the index is invalid
	if (position > numElts - 1) 
	{
		throw exception("Invalid Index");
	}
	//code block that will allow us to insert the sequence node  at position 0 head
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
	// this code will allow us to insert the sequence in between head and tail
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
	// inserting in the tail of the sequence
	if (position == numElts - 1) 
	{
		SequenceNode *tempNode = tail->prev;
		SequenceNode *newNode= new SequenceNode();
		tempNode->next = newNode;
		newNode->prev = tempNode;
		newNode->elt = value;
		newNode->next = tail;
		tail->prev = newNode;
		numElts++;
	}
	

}
/* Erase method input position(start of the index ) from where to erase and 
count will determine the number of elements to be erased*/
void Sequence::erase(size_type position, size_type count)
{
	if (position > numElts - 1 || numElts < count+position) 
	{
		throw exception("Invalid index");
	}
	//position and cound is in valid index range and not touching the head and tail
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
	//delete range equals to numelts touching the head and tail pointers
	if (position + count == numElts) {
		while(count>0){
			pop_back();
			count--;
		}
	}
	//erasing the elements from the head and handling some exception cases as well
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
// overloaded << operator that will allow us to print the sequence like this cout<<sequence
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
//print function to join ", " between the each and every element of sequence object
 ostream& Sequence::print(ostream& os)
 {
	 os << ", ";
	 return os;
 }


// LinkedList.cpp
// Finley McIlwaine
// COSC2030 Lab2
// 10/1/2018

#include "pch.h"
#include "LinkedList.h"

#include <utility>


List::List()
	: first_(NULL), listSize(0)
{
}


List::List(const List & other)
	: first_(clone(other.first_)), listSize(other.getSize())
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}

const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);

		// Give correct size
		this->listSize = other.getSize();
	}

	return *this;
}

bool List::operator==(const List &rhs){
    /*if(size() == 0 && rhs.size() == 0){return true;}//both empty
    if(size() != rhs.size()){return false;}//sizes not the same

    Node * lptr = this->next_;
    Node * rptr = rhs->next_;
		Double lEntry = lptr->entry_;
    Double rEntry = rptr->entry_;
		while (lptr != NULL && rptr != NULL)
		{
      if(lEntry != rEntry){
        return false;
      }
      lptr = lptr->next_;
      rptr = rptr->next_;
      lEntry = lptr->entry_;
      rEntry = rptr->entry_;
		}
*/
  	return true;
}


bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);

	// Increment list size.
	listSize++;
}


double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;

	// Decrement list size
	listSize--;

	return item;
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}


// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}

/*+++++++++++++++++++++++++++++++++++++++++
My functions start here.
+++++++++++++++++++++++++++++++++++++++++*/
// returns size of list.
int List::getSize() const {
	return listSize;
}

// returns sum of elements in list
double List::sum() const {
	// current node, sum variables
	Node* current = first_;
	double sum = 0;
	
	// loop through nodes, summing
	while (current != NULL)
	{
		// add to sum
		sum += current->entry_;

		// next node
		current = current->next_;
	}

	return sum;
}

// inserts a node holding x pointing to NULL at the end of the list
void List::insertAsLast(double x) {
	
	// Make a new last node holding the argument and null next ptr.
	Node* last = new Node(x,NULL);

	// Handle empty list case.
	if (first_ == NULL) {
		first_ = last;
		this->listSize++;
		return;
	}

	// Start at beginning of list
	Node* current = first_;

	// get the last node
	while (current->next_ != NULL)
	{
		current = current->next_;
	}

	// insert the new node as last.
	current->next_ = last;

	// Increment the size of the list.
	this->listSize++;
}
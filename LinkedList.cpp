/*
	191
	LinkedList1
	LinkedList.cpp
	pjirele, dfahrney
*/
#include <iostream>
#include "LinkedList.h"

using namespace std;


// easy function to write. assigns an empty single linked list
LinkedList::LinkedList()
{
	top = bottom = nullptr;
	size = 0;
} // end LinkedList

// only to build the linked list
void LinkedList::addTop(int v)
{
	Node* temp = new Node;
	temp->data = v;
	if (size == 0)
	{
		top = bottom = temp;
		temp->next = nullptr;
		size++;
	} // end if
	else
	{
		temp->next = top;
		top = temp;
		size++;
	} // end else
} // end addTop

// only used to build the list
void LinkedList::addBottom(int n)
{
	Node* temp = new Node;
	temp->data = n;
	temp->next = nullptr;
	if (size == 0)
	{
		top = bottom = temp;
	} // end if
	else
	{
		bottom->next = temp;
		bottom = temp;
	} // end else
	size++;
} // end addBottom


void LinkedList::display()
{
	Node* ptr = top;
	while (ptr != nullptr)
	{
		cout << ptr->data << "  ";
		ptr = ptr->next;
	} // end while
} // end display


// easy function to write. counts all the target values in the linked list and returns them
int LinkedList::count(int target)
{
	int n = 0;
	Node* temp = top;
	while (temp != nullptr)
	{
		if (temp->data == target)
		{
			n++;
		} // end if
		temp = temp->next;
	} // end while
	return n;
} // end count
int LinkedList::countOdds()
{
	int n = 0;
	Node* temp = top;
	while (temp != nullptr)
	{
		if (temp->data % 2 != 0)
		{
			n++;
		} // end if
		temp = temp->next;
	} // end while
	return n;
} // end count

// esay fnuction to write. returns the largest value in the linked list
int LinkedList::max()
{
	int v = INT_MIN;
	Node* temp = top;
	while (temp != nullptr)
	{
		if (temp->data > v)
		{
			v = temp->data;
		} // end if
		temp = temp->next;
	} // end while
	return v;
}


// easy function to write. returns the lowest value in the linked list
int LinkedList::min()
{
	int v = INT_MAX;
	Node* temp = top;
	while (temp != nullptr)
	{
		if (temp->data < v)
		{
			v = temp->data;
		} // end if
		temp = temp->next;
	} // end while
	return v;
}


// easy function to write. returns the average value in the linked list. The function returns something useful if the list is empty.
double LinkedList::ave() 
{
	Node* temp = top;
	int total = 0; int count = 0;
	if (size != 0)
	{
		while (temp != nullptr)
		{
			total += temp->data;
			temp = temp->next;
			count++;
		} // end while
		return (double)total / count;
	} // end if
	else
		return -1;
} // end ave

// difficult function to write. removes the top node of the list
void LinkedList::delTop()
{
	Node* temp = top;
	if (size == 0)
	{
		cout << "ERROR" << endl;
	} // end if
	else
	{
		top->data = top->next->data;
		temp = top->next;
		top->next = top->next->next;
		size--;
	} // end else
} // end delTop


// easy to write. returns the top value does not delete it
int LinkedList::getTop()
{
	return top->data;
} // end getTop

// difficult function to write. removes the bottom node of the list
void LinkedList::delBottom()
{
	Node* temp = top;
	Node* trail = top->next->next;

	while (trail != nullptr)
	{
		trail = trail->next;
		temp = temp->next;
	}
	if (trail == nullptr)
	{
		bottom = temp;
		temp->next = nullptr;
	}
} // end delBottom
 
// easy to wtrie gets bottom value
int LinkedList::getBottom()
{
	return bottom->data;
}


// this was extreemly difficult to write and had to think about it a lot
bool LinkedList::delFirst(int target)
{
	Node* trail = top;
	Node* temp = top;

	if (top->data == target)
	{
		top->data = top->next->data;
		temp = top->next;
		top->next = top->next->next;
		return true;
	} // end if
	else
	{
		trail = top;
		temp = top->next->next;
		while (trail->next->data != target)
		{
			temp = temp->next;
			trail = trail->next;
			if (temp == nullptr)
			{
				return false;
			} // end if
		} // end while
		trail->next = temp;
		return true;
	}// end else
} // end delFirst


// very challanging had to think hard about this one
// inserts value into the linked list so that the integers in the nodes are in ascending order from the top
// node to the bottom node.  An absolutely necessary pre-condition: the list is empty or it is already in sorted order. In other words, you'll
// start using sortedInsert on a list that is empty and thus always be performing the operation on a list that is sorted.
void LinkedList::sortedInsert(int n)
{
	Node* temp = new Node;
	temp->data = n;
	if (size == 0)
	{
		top = bottom = temp;
		temp->next = nullptr;
		size++;
	} // end if
	else if (size == 1)
	{
		if (temp->data > top->data)
		{
			top->next = temp;
			temp->next = nullptr;
			size++;
		} // end if
		else if(temp->data < top->data)
		{
			temp->next = top;
			top->next = nullptr;
			top = temp;
			size++;
		} // end else if
	} // end else if
	else if (size > 1)
	{
		temp = top->next;
		Node* trail = top;
		Node* insert = new Node;
		insert->data = n;
		while (temp != nullptr && temp->data <= n) // gets the two nodes into the right position for an isert
		{
			trail = temp;
			temp = temp->next;
		/*
			if (temp->data > n)
			{
				insert->next = trail;
				top = insert;
				size++;
			} // end if
			else if (temp->data < n)
			{
				temp->next = insert;
				insert->next = nullptr;
				bottom = insert;
				size++;
			}
			else if (temp->data > n && trail->data < n)
			{
				trail->next->data = insert->data;
				insert->next = temp;
				trail = insert;
				size++;
			} // end else if
			trail = trail->next;
			temp = temp->next;

		*/
		} // end while
		trail->next = insert;
		insert->next = temp;
		size++;
	} // end else if
} // end sorted insert
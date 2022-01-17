/*
	191
	LinkedList1
	LinkedList.h
	pjirele, dfahrney
*/
#pragma once
struct Node
{
	int data;
	Node* next;
};

class LinkedList
{
	private:
		Node* top;
		int size;
	public:
		LinkedList(); 
		void addTop(int); 
		void display(); 
		int getSize();
		bool DelLast(int);
		
};


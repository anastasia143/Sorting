#pragma once
#include <iostream>
using namespace std;

struct Node
{
	int value;
	int owner;
	Node* next;
};

class PriorityQueue
{
public:
	PriorityQueue()
	{
		root = NULL;
		size = 0;
	}
	Node* root;
	int size;
	void push(int new_value, int new_owner);
	int pop();
	int top();
	int topOwner();
	void clear();
	bool isEmpty()
	{
		return (size == 0);
	}

	void print();
};



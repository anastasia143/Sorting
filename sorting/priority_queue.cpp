#include "priority_queue.h"

Node* nodeCreator(int new_value, int new_owner, Node* new_next)
{
	Node* node = new Node;
	node->value = new_value;
	node->owner = new_owner;
	node->next = new_next;
	return node;
}

void PriorityQueue::push(int new_value, int new_owner)
{
	size++;
	if(root == NULL)
	{
		root = nodeCreator(new_value, new_owner, NULL);
		return;
	}
	if(new_value < root->value)
	{
		Node* node = nodeCreator(new_value, new_owner, root);
		node->next = root;
		root = node;
		return;
	}

	Node* node = root;
	while(node->next != NULL)
	{
		//cout << endl << "try to " << new_value << " < ?" << node->value << endl;
		if(new_value < node->next->value)
		{
			Node* node2 = nodeCreator(new_value, new_owner, node->next);
			node->next = node2;
			return;
		}
		node = node->next;
	}
	node->next = nodeCreator(new_value, new_owner, NULL);
}

void PriorityQueue::print()
{
	Node* node = root;
	while(node != NULL)
	{
		cout << node->value << " ";
		node = node->next;
	}
	cout << endl;
}

int PriorityQueue::top()
{
	if(size == 0)
		return -1;
	return root->value;
}

int PriorityQueue::topOwner()
{
	if(size == 0)
		return -1;
	return root->owner;
}

int PriorityQueue::pop()
{
	if(size == 0)
		return -1;
	int result = root->value;
	root = root->next;
	size--;
	return result;
}


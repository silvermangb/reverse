/*
 * main.cpp
 *
 *  Created on: Sep 3, 2014
 *      Author: Greg Silverman
 */


using namespace std;

#include <iostream>
#include <memory>

class Node;
using NodeType = shared_ptr<Node>;

class Node
{
public:
	int Value;
	NodeType Next;
	Node(int p_value,NodeType p_next=0) : Value(p_value), Next(p_next) {}
};

void
dump
	(NodeType p_node)
{
	NodeType node = p_node;
	while(node)
	{
		cout << node->Value << endl;
		node = node->Next;
	}
	cout << "-------" << endl;
	cout.flush();
}

void
reverse
  (NodeType& root)
{
	NodeType prev(nullptr);
	NodeType curr = root;
	NodeType next;
	while(curr)
	{
		next = curr->Next;
		curr->Next = prev;
		prev = curr;
		curr = next;
	}
	root = prev;
}

int
main
	()
{
	NodeType root(new Node(0));
	NodeType node = root;
	for(int i=1;i<4;++i)
	{
		NodeType next_node(new Node(i));
		node->Next = next_node;
		node = node->Next;

	}
	dump(root);
	reverse(root);
	dump(root);
	return 0;
}

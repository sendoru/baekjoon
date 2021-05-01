#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

class Node
{
	ll data;
	Node* rightNode;
	Node* leftNode;

public:
	Node(ll data_)
	{
		data = data_;
		rightNode = nullptr;
		leftNode = nullptr;
	}
	void insertNode(Node* node);
	void postTraverse();
};

void Node::insertNode(Node* node)
{
	if (this->data < node->data)
	{
		if (this->rightNode == nullptr)
		{
			this->rightNode = node;
		}
		else
		{
			this->rightNode->insertNode(node);
		}
	}
	else
	{
		if (this->leftNode == nullptr)
		{
			this->leftNode = node;
		}
		else
		{
			this->leftNode->insertNode(node);
		}
	}
}

void Node::postTraverse()
{
	if (this->leftNode != nullptr)
	{
		this->leftNode->postTraverse();
	}
	if (this->rightNode != nullptr)
	{
		this->rightNode->postTraverse();
	}
	cout << data << '\n';
}

int main(void)
{
	vector<Node> v;
	ll input;

	cin >> input;

	Node* root = new Node(input);

	while (cin >> input)
	{
		root->insertNode(new Node(input));
	}
	root->postTraverse();
	return 0;
}
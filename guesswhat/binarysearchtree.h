#pragma once

#include <stdexcept>
#include <string>
#include <iostream>

class Node
{
public:
	Node(int value, Node* left, Node* right)
	{
		this->value = value;
		this->left = left;
		this->right = right;
	}

	int getValue() const
	{
		return value;
	}

	Node* getLeft() const
	{
		return left;
	}

	Node* getRight() const
	{
		return right;
	}

private:
	int value;
	Node* left;
	Node* right;
};

class BinarySearchTree
{
public:
	static bool contains(const Node& root, int value)
	{
		//throw std::logic_error("Waiting to be implemented");
		Node * right = root.getRight();
		if (right != nullptr)
		{
			if (value == right->getValue())
				return true;
			else
				return contains(*right, value);
		}
		Node* left = root.getLeft();
		if (left != nullptr) {
			if (value == left->getValue())
				return true;
			else
				return contains(*left, value);
		}
	};
};

//#ifndef RunTests
int binarytreesearch_main()
{
	Node n1(1, NULL, NULL);
	Node n3(3, NULL, NULL);
	Node n2(2, &n1, &n3);

	std::cout << BinarySearchTree::contains(n2, 3);
	return 0;
}
//#endif
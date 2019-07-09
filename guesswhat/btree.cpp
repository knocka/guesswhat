
#include "pch.h"
#include <iostream>

using namespace std;


struct node {
	int value{ 0 };
	node *left{ nullptr };
	node *right{ nullptr };
};

class btree {
public:
	btree();
	~btree();

	void insert(int key);
	void insertx(int key);
	node *search(int key);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();

private:
	void destroy_tree(node *leaf);
	void insert(int key, node *leaf);
	void insertx(int key, node *leaf);
	node *search(int key, node *leaf);
	void inorder_print(node *leaf);
	void postorder_print(node *leaf);
	void preorder_print(node *leaf);

	node *root{ nullptr };
};


btree::btree() {
	root = nullptr;
}

btree::~btree() {
	destroy_tree();
}

void btree::destroy_tree(node *leaf) {
	if (leaf != nullptr) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(int key, node *leaf) {

	if (key < leaf->value) {
		if (leaf->left != nullptr) {
			insert(key, leaf->left);
		}
		else {
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = nullptr;
			leaf->left->right = nullptr;
		}
	}
	else if (key >= leaf->value) {
		if (leaf->right != nullptr) {
			insert(key, leaf->right);
		}
		else {
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = nullptr;
			leaf->right->left = nullptr;
		}
	}

}

void btree::insertx(int key, node * leaf)
{
	if (leaf->value > key) {
		if (leaf->left == nullptr) {
			leaf->left = new node;
			leaf->left->value = key;
		}
		else {
			insertx(key, leaf->left);
		}
	}
	else {
		if (leaf->right == nullptr) {
			leaf->right = new node;
			leaf->right->value = key;
		}
		else {
			insertx(key, leaf->right);
		}
	}
};

void btree::insert(int key) {
	if (root != nullptr) {
		insert(key, root);
	}
	else {
		root = new node;
		root->value = key;
		root->left = nullptr;
		root->right = nullptr;
	}
}

void btree::insertx(int key)
{
	if (root == nullptr) {
		root = new node;
		root->value = key;
	}
	else {
		insertx(key, root);
	}
};

node *btree::search(int key, node *leaf) {
	if (leaf != nullptr) {
		if (key == leaf->value) {
			return leaf;
		}
		if (key < leaf->value) {
			return search(key, leaf->left);
		}
		else {
			return search(key, leaf->right);
		}
	}
	else {
		return nullptr;
	}
}

node *btree::search(int key) {
	return search(key, root);
}

void btree::destroy_tree() {
	destroy_tree(root);
}

void btree::inorder_print() {
	inorder_print(root);
	cout << "\n";
}

void btree::inorder_print(node *leaf) {
	if (leaf != nullptr) {
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}

void btree::postorder_print() {
	postorder_print(root);
	cout << "\n";
}

void btree::postorder_print(node *leaf) {
	if (leaf != nullptr) {
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}

void btree::preorder_print() {
	preorder_print(root);
	cout << "\n";
}

void btree::preorder_print(node *leaf) {
	if (leaf != nullptr) {
		cout << leaf->value << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}

int btree_main() {

	//btree tree;
	btree *tree{ nullptr };
	cout << '\n' << "---" << endl;
	tree = new btree();

	tree->insert(10);
	tree->insert(6);
	tree->insert(14);
	tree->insert(5);
	tree->insert(8);
	tree->insert(11);
	tree->insert(18);

	tree->preorder_print();
	tree->inorder_print();
	tree->postorder_print();

	delete tree;
	
	cout << "---" << endl;
	tree = new btree();

	tree->insertx(10);
	tree->insertx(6);
	tree->insertx(14);
	tree->insertx(5);
	tree->insertx(8);
	tree->insertx(11);
	tree->insertx(18);

	tree->preorder_print();
	tree->inorder_print();
	tree->postorder_print();

	delete tree;
	return 0;
}
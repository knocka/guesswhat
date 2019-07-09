#pragma once
#include <iostream>


template <class T>
class List {

	struct Node {
		Node* Next{};
		Node* Prev{};
		T Data{};
		Node() = default;
		explicit Node(const T& data) : Data{ data } {}
		Node(const T& data, Node * next) : Data{ data }, Next{ next } {}
	};

	Node * m_head{ nullptr };
	int m_count{ 0 };
public:
	typedef Node* Position;
	List() = default;
	~List() {
		Clear();
	}

	int Count() const {
		return m_count;
	}

	bool IsEmpty() const {
		return (m_count == 0);
	}

	void Clear() {
		while (!IsEmpty()) {
			RemoveHead();
		}
	}


	void InsertHead(const T& data) {
		Node * node = new Node(data);
		node->Next = m_head;
		if (m_head != nullptr)
			m_head->Prev = node;
		m_head = node;
		++m_count;
	};

	void RemoveHead() {
		Node * newHead = m_head->Next;
		delete m_head;
		m_head = newHead;
		--m_count;
	};

	Node * Find(const T& value) {
		Node * node = m_head;
		while (node != nullptr) {
			if (node->Data == value)
				return node;
			node = node->Next;
		}
		return nullptr;
	};

	void InsertAfter(Node* node, const T& data) {
		Node* next = node->Next;
		Node * new_node = new Node(data, next);
		new_node->Prev = node;
		node->Next = new_node;
		++m_count;
	};

	void RemoveAfter(Node * node) {
		Node* obsoleteNode = node->Next;
		node->Next = obsoleteNode->Next;
		delete obsoleteNode;
		--m_count;
	};


	void printList() {
		Node * node = m_head;
		while (node != nullptr) {
			std::cout << node->Data << " ";
			node = node->Next;
		}
		std::cout << std::endl;
	};

	 friend std::ostream& operator<<(std::ostream& os, const List<T>& list) {
		if (list.IsEmpty()) {
			os << "[ Empty List ]";
			return os;
		}

		os << "[ ";

		// For each node:
		Node* node = list.m_head;
		while (node != nullptr) {
			// Print data stored in current node
			os << node->Data << ' ';

			// Move forward to the next node
			node = node->Next;
		}

		os << ']';
		return os;
	}

};
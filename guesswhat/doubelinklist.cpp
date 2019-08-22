using namespace std;

class Node {
public:
	int value;
	Node* prev;
	Node* next;

	Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
public:
	Node* head;
	Node* tail;

	DoublyLinkedList() {
		head = nullptr;
		tail = nullptr;
	}

	void setHead(Node* node) {
		// Write your code here.
		if (head == nullptr)
			head = node;
		else
		{
			node->next = head;
			head = node;
		}
	}

	void setTail(Node* node) {
		// Write your code here.
		if (tail == nullptr)
			tail = node;
		else
		{
			node->next = tail;
			tail = node;
		}
	}

	void insertBefore(Node* node, Node* nodeToInsert) {
		// Write your code here.
		if (nodeToInsert == head || nodeToInsert == tail) return;
		remove(nodeToInsert);
		nodeToInsert->prev = node->prev;
		nodeToInsert->next = node;
		if (node->prev == nullptr) {
			head = nodeToInsert;
		}
		else {
			node->prev->next = nodeToInsert;
		}
		node->prev = nodeToInsert;
	}

	void insertAfter(Node* node, Node* nodeToInsert) {
		// Write your code here.
		if (nodeToInsert == head || nodeToInsert == tail) return;
		remove(nodeToInsert);
		nodeToInsert->prev = node;
		nodeToInsert->next = node->next;
		if (node->next == nullptr) {
			tail = nodeToInsert;
		}
		else {
			node->next->prev = nodeToInsert;
		}
		node->next = nodeToInsert;
	}

	void insertAtPosition(int position, Node* nodeToInsert) {
		// Write your code here.
		if (position == 1) {
			setHead(nodeToInsert);
			return;
		}
		Node* node = head;
		int currentPosition = 1;
		while (node != nullptr && position != currentPosition++) { node = node->next; }
		if (node != nullptr)
			insertBefore(node, nodeToInsert);
		else
			setTail(nodeToInsert);
	}

	void removeNodesWithValue(int value) {
		// Write your code here.
	}

	void remove(Node* node) {
		// Write your code here.
		Node* ptr = node;
		if (ptr == head) {
			head = ptr->next;
			head->prev = nullptr;
		}
		else if (ptr == tail) {
			tail = ptr->prev;
			tail->next = nullptr;
		}
		else {
			ptr->next->prev = ptr->prev;
			ptr->prev->next = ptr->next;
		}
	}

	bool containsNodeWithValue(int value) {
		// Write your code here.
	}
};
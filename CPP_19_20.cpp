#include <iostream>

using namespace std;

struct forvardlist {
	int data;
	forvardlist *next;
};

struct list {
	int data;
	list *prev;
	list *next;
};

template <typename T>
T *newList() {
	return new T;
}

// add sorted
template <typename T>
void addNode(T *head, int value) {
	if (head->data > value) {
		head->next = new T {head->data, head->next};
		head->data = value;
		return;
	}

	T *node = head;

	while (node->next) {
		if (node->next->data > value) {
			node->next = new T {value, node->next};
			return;
		}
		node = node->next;
	}

	node->next = new T {value};
}

// insert from cin
template <typename T>
void insertNodes(T *head) {
	int repeat;
	int item;

	cin >> repeat;
	cin >> head->data;

	for (int i = 1; i < repeat; ++i) {
		cin >> item;
		addNode<T>(head, item);
	}
}

// find node in forvardlist
void findNode(forvardlist *head) {
	forvardlist *node = head;
	int value;
	cin >> value;

	if (!node) {
		cout << "The list is empty" << endl;
		return;
	}

	while (node) {
		if (node->data == value) {
			cout << "List item found" << endl;
			return;
		}
		node = node->next;
	}

	cout << "List item not found" << endl;
}

// find node and delete them
template <typename T>
void findAndDeleteNode(T *head) {
	T *node = head;
	int value;
	cin >> value;

	if (!node) {
		cout << "The list is empty" << endl;
		return;
	}

	while (node && node->next) {
		if (node->next->data == value) {
			node->next = node->next->next;
			cout << "List item deleted" << endl;
			return;
		}
		node = node->next;
	}

	cout << "List item not found" << endl;
}

template <typename T>
void bubbleSort(T *head) {
	bool swapped = true;
	int length = 0;
	T *node = head;

	while (node) {
		++length;
		node = node->next;
	}

	while (swapped) {
		swapped = false;
		T *node = head;
		for (int i = 0; i < length - 1; ++i) {
			if (node->data > node->next->data) {
				node->data += node->next->data;
				node->next->data = node->data - node->next->data;
				node->data -= node->next->data;
				swapped = true;
			}
			node = node->next;
		}
	}
}

template <typename T>
void printList(forvardlist *head) {
	T *node = head;
	while (node) {
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}

void cpp_19_1(forvardlist *head) {
	insertNodes<forvardlist>(head);
}

void cpp_19_2(forvardlist *head) {
	findNode(head);
}

void cpp_19_3(forvardlist *head) {
	findAndDeleteNode<forvardlist>(head);
}

void cpp_19_4(forvardlist *head) {
	bubbleSort(head);
}

void cpp_19_5(list *head) {
	insertNodes(head);
}

void cpp_19_6(list *tail) {
	int repeat;
	int item;

	cin >> repeat;
	cin >> tail->data;

	for (int i = 1; i < repeat; ++i) {
		cin >> item;
		tail->next = new list {item, tail};
		tail = tail->next;
	}

	while (tail) {
		cout << tail->data << ' ';
		tail = tail->prev;
	}

	cout << endl;
}

void cpp_19_7(list *head) {
	findAndDeleteNode<list>(head);
}

void cpp_19_8(list *head) {
}

int main() {
}

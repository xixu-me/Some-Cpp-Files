#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

Node *creat_front(int num[], int lenth) {
	Node *head = NULL;
	for (int i = 0; i < lenth; i++) {
		Node *new_node = (Node *)malloc(sizeof(Node));
		if (new_node == NULL) {
			printf("Failed to allocate\n");
			exit(1);
		}
		new_node->data = num[i];
		new_node->next = head;
		head = new_node;
	}
	return head;
}

Node *creat_back(int num[], int lenth) {
	Node *head = NULL;
	Node *back = NULL;
	for (int i = 0; i < lenth; i++) {
		Node *new_node = (Node *)malloc(sizeof(Node));
		if (new_node == NULL) {
			printf("Failed to allocate\n");
			exit(1);
		}
		new_node->data = num[i];
		new_node->next = NULL;
		if (head == NULL) {
			head = new_node;
			back = new_node;
		}
		else {
			back->next = new_node;
			back = new_node;
		}
	}
	return head;
}

int get_list(Node *head, int position) {
	Node *q = head;
	int i = 0;
	while (q != NULL) {
		if (i == position) {
			return q->data;
		}
		else {
			q = q->next;
			i++;
		}
	}
	if (q == NULL)
		printf("position is out of range and fail to get data!\n");
	free(q);
	return -1;
}

Node *insert(Node *head, int position, int data) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("fail to allocate!\n");
		exit(1);
	}
	newNode->data = data;
	if (position == 0) {
		newNode->next = head;
		head = newNode;
	}
	else {
		Node *current = head;
		int index = 0;

		while (current != NULL && index < position - 1) {
			current = current->next;
			index++;
		}

		if (current != NULL) {
			newNode->next = current->next;
			current->next = newNode;
		}
		else {
			printf("插入位置不合法\n");
			free(newNode);
		}
	}

	return head;
}

int findElement(Node *head, int value) {
	Node *current = head;
	int i = 0;

	while (current != NULL) {
		if (current->data == value) {
			return i;
		}

		current = current->next;
		i++;
	}

	exit(i);
}
Node *deleteElement(Node *head, int position) {
	if (head == NULL) {
		printf("链表为空\n");
		return NULL;
	}

	Node *temp;
	if (position == 0) {
		temp = head;
		head = head->next;
	}
	else {
		Node *current = head;
		int index = 0;

		while (current != NULL && index < position - 1) {
			current = current->next;
			index++;
		}

		if (current != NULL && current->next != NULL) {
			temp = current->next;
			current->next = current->next->next;
		}
		else {
			printf("删除位置不合法\n");
			return head;
		}
	}

	free(temp);
	return head;
}
void printList(Node *head) {
	Node *current = head;

	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}

	printf("\n");
}

int main() {
	int a[] = { 5, 6, 8, 9, 1 };
	Node *myList = creat_front(a, 5);
	printf("List after front insertion: ");
	printList(myList);
	free(myList);

	myList = creat_back(a, 5);
	printf("List after end insertion: ");
	printList(myList);

	int valueAtIndex2 = get_list(myList, 2);
	printf("Value at index 2: %d\n", valueAtIndex2);

	int searchResult = findElement(myList, 8);
	printf("Index of value 8: %d\n", searchResult);

	myList = insert(myList, 2, 10);
	printf("List after insertion at index 2: ");
	printList(myList);

	myList = deleteElement(myList, 3);
	printf("List after deletion at index 3: ");
	printList(myList);

	free(myList);

	return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
	int value;
	struct _node *next;
} Node;

typedef struct _list {
	Node *head;
} List;

Node *creat_node(int value) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->value = value;
	new_node->next = NULL;
	return new_node;
}

void head_insert(List *list, int value) {
	Node *new_node = creat_node(value);
	new_node->next = list->head;
	list->head = new_node;
}

void tail_insert(List *list, int value) {
	Node *new_node = creat_node(value);
	if (!list->head) {
		list->head = new_node;
	}
	else {
		Node *current = list->head;
		for (; current->next; current = current->next)
			;
		current->next = new_node;
	}
}

Node *search_node(List *list, int value) {
	Node *current = list->head;
	for (; current != NULL && current->value != value; current = current->next)
		;
	return current;
}

void delete_node(List *list, int value) {
	for (Node *current = list->head, *prev = NULL; current; prev = current, current = current->next) {
		if (current->value == value) {
			if (prev) {
				prev->next = current->next;
			}
			else {
				list->head = current->next;
			}
			free(current);
			break;
		}
	}
}

void print_list(List *list) {
	for (Node *current = list->head; current; current = current->next) {
		printf("%d ", current->value);
	}
	printf("\n");
}

void clear_list(List *list) {
	for (Node *current = list->head, *subs; current; current = subs) {
		subs = current->next;
		free(current);
	}
}
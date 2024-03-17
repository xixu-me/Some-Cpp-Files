#include <stdio.h>

#define MAXSIZE 50

typedef struct
{
	int data[MAXSIZE];
	int size;
} seqlist;

void seqlist_init(seqlist *list) {
	list->size = 0;
}

void insert(seqlist *list, int position, int data) {
	if (list->size == MAXSIZE) {
		printf("seqlist is full\n");
		return;
	}
	if (position < 0 || position > list->size) {
		printf("position is out of range\n");
		return;
	}
	for (int i = list->size - 1; i >= position; i--) {
		list->data[i + 1] = list->data[i];
	}
	list->data[position] = data;
	list->size++;
}

void delete(seqlist *list, int position) {
	if (list->size == MAXSIZE) {
		printf("seqlist is full\n");
		return;
	}
	if (position < 0 || position >= list->size) {
		printf("position is out of range\n");
		return;
	}
	for (int i = position; i <= list->size - 1; i++) {
		list->data[i] = list->data[i + 1];
	}
	list->size--;
}

int get(seqlist *list, int position) {
	if (position < 0 || position >= list->size) {
		printf("获取位置不合法\n");
		return -1; // 返回一个特殊值表示错误
	}

	return list->data[position];
}

int search(seqlist *list, int data) {
	for (int i = 0; i < list->size; i++) {
		if (list->data[i] == data)
			return i;
	}
	return -1;
}
void printSeqList(seqlist *list) {
	printf("顺序表元素: ");
	for (int i = 0; i < list->size; i++) {
		printf("%d ", list->data[i]);
	}
	printf("\n");
}
int main() {

	seqlist myList;
	seqlist_init(&myList);

	insert(&myList, 0, 1);
	insert(&myList, 1, 2);
	insert(&myList, 2, 3);

	printSeqList(&myList);

	delete (&myList, 1);

	printSeqList(&myList);

	int value = get(&myList, 1);
	if (value != -1) {
		printf("位置1的元素为: %d\n", value);
	}

	int position = search(&myList, 3);
	if (position != -1) {
		printf("元素3的位置为: %d\n", position);
	}

	return 0;
}
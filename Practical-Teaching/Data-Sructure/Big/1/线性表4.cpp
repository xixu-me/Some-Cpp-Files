#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 学生结构体
typedef struct
{
	int id;
	char name[5];
} Student;

// 链表节点结构体
typedef struct Node {
	Student student;
	struct Node *next;
} Node;

// 链表结构体
typedef struct
{
	Node *head;
} LinkedList;

// 函数声明
void initList(LinkedList *list);
void insertStudent(LinkedList *list, Student student);
void printList(LinkedList list);
Node *findStudentById(LinkedList list, int id);
void deleteStudentById(LinkedList *list, int id);
void clearList(LinkedList *list);

int main() {
	LinkedList studentList;
	initList(&studentList);

	int choice;
	do {
		// 用户菜单
		printf("\n学生管理系统菜单：\n");
		printf("1. 添加学生\n");
		printf("2. 删除学生\n");
		printf("3. 查找学生\n");
		printf("4. 打印学生列表\n");
		printf("5. 清空学生列表\n");
		printf("6. 退出\n");
		printf("请选择操作（1-6）： ");
		scanf("%d", &choice);

		switch (choice) {
		case 1: {
			// 添加学生
			Student newStudent;
			printf("请输入学号（1-100）： ");
			scanf("%d", &newStudent.id);
			printf("请输入姓名（不超过4个字符）： ");
			scanf("%s", newStudent.name);

			insertStudent(&studentList, newStudent);
			break;
		}
		case 2: {
			// 删除学生
			int id;
			printf("请输入要删除学生的学号： ");
			scanf("%d", &id);

			deleteStudentById(&studentList, id);
			break;
		}
		case 3: {
			// 查找学生
			int id;
			printf("请输入要查找学生的学号： ");
			scanf("%d", &id);

			Node *foundStudent = findStudentById(studentList, id);
			if (foundStudent != NULL) {
				printf("找到学生：学号 %d，姓名 %s\n", foundStudent->student.id, foundStudent->student.name);
			}
			else {
				printf("未找到学生。\n");
			}
			break;
		}
		case 4:
			// 打印学生列表
			printList(studentList);
			break;
		case 5:
			// 清空学生列表
			clearList(&studentList);
			printf("学生列表已清空。\n");
			break;
		case 6:
			// 退出程序
			printf("程序已退出。\n");
			break;
		default:
			printf("无效的选择，请重新输入。\n");
		}
	} while (choice != 6);

	return 0;
}

// 初始化链表
void initList(LinkedList *list) {
	list->head = NULL;
}

// 在有序链表中插入学生
void insertStudent(LinkedList *list, Student student) {
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->student = student;
	newNode->next = NULL;

	if (list->head == NULL || student.id < list->head->student.id) {
		// 插入头部
		newNode->next = list->head;
		list->head = newNode;
	}
	else {
		// 插入中间或尾部
		Node *current = list->head;
		while (current->next != NULL && student.id > current->next->student.id) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}

	printf("学生已添加：学号 %d，姓名 %s\n", student.id, student.name);
}

// 打印学生列表
void printList(LinkedList list) {
	Node *current = list.head;
	printf("\n学生列表：\n");
	while (current != NULL) {
		printf("学号 %d，姓名 %s\n", current->student.id, current->student.name);
		current = current->next;
	}
}

// 根据学号查找学生
Node *findStudentById(LinkedList list, int id) {
	Node *current = list.head;
	while (current != NULL) {
		if (current->student.id == id) {
			return current;
		}
		current = current->next;
	}
	return NULL;
}

// 根据学号删除学生
void deleteStudentById(LinkedList *list, int id) {
	Node *current = list->head;
	Node *prev = NULL;

	while (current != NULL && current->student.id != id) {
		prev = current;
		current = current->next;
	}

	if (current != NULL) {
		// 找到学生，进行删除操作
		if (prev == NULL) {
			// 删除头节点
			list->head = current->next;
		}
		else {
			prev->next = current->next;
		}
		free(current);
		printf("学生已删除：学号 %d\n", id);
	}
	else {
		printf("未找到学生。\n");
	}
}

// 清空学生列表
void clearList(LinkedList *list) {
	Node *current = list->head;
	while (current != NULL) {
		Node *next = current->next;
		free(current);
		current = next;
	}
	list->head = NULL;
}

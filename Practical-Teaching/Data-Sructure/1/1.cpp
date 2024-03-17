// 预编译命令
#include <stdio.h>
#include <stdlib.h>

// 数据结构定义
typedef struct
{
	int num;
	char name[20];
	int score[3];
	int ave;
} Student; // 结构体类型定义

// 函数声明
int menu_select();
void input(Student s[5]);
void output(Student s[5], int n);
void average(Student s[5]);
void sort(Student s[5]);

// 主函数
int main() {
	Student stu[5]; // 准备实参
	for (;;) {
		switch (menu_select()) {
		case 1:
			printf("请输入5位同学的信息\n");
			input(stu); // 函数调用
			break;
		case 2:
			printf("输出5位同学的信息\n");
			output(stu, 5);
			break;
		case 3:
			average(stu);
			printf("平均分已经求过\n");
			break;
		case 4:
			sort(stu);
			printf("按照平均分由高到低排序已经完成\n");
			break;
		case 5:
			printf("输出前3名同学的信息\n");
			sort(stu); // 输出前3名之前先排序
			output(stu, 3);
			break;
		case 0:
			printf("谢谢使用本软件\n");
			exit(0);
		}
	}
	return 0;
}

// 菜单函数
int menu_select() {
	int sn;
	printf("\n1.输入5位同学的信息\n");
	printf("2.输出5位同学的信息\n");
	printf("3.求平均分\n");
	printf("4.排序\n");
	printf("5.输出前三名\n");
	printf("0.结束\n");
	printf("Input 0～5:");
	for (;;) {
		scanf("%d", &sn);
		if (sn < 0 || sn > 5)
			printf("\n输入错误，重选0～5：");
		else
			break;
	}
	return sn;
}

// 输入函数
void input(Student s[5]) {
	int i, j;
	for (i = 0; i < 5; i++) {
		scanf("%d", &s[i].num);
		scanf("%s", s[i].name);
		for (j = 0; j < 3; j++) {
			scanf("%d", &s[i].score[j]);
		}
	}
}

// 输出函数
void output(Student s[5], int n) // 增加一个参数n，为输出元素的个数
{
	int i, j;
	for (i = 0; i < n; i++) {
		printf("%d\t", s[i].num);
		printf("%s\t", s[i].name);
		for (j = 0; j < 3; j++) {
			printf("%d\t", s[i].score[j]);
		}
		printf("%d\t", s[i].ave);
		printf("\n");
	}
}

// 求平均分
void average(Student s[5]) {
	int i, j, sum;
	for (i = 0; i < 5; i++) {
		sum = 0;
		for (j = 0; j < 3; j++) {
			sum += s[i].score[j];
		}
		s[i].ave = sum / 3;
	}
}

// 冒泡排序
void sort(Student s[5]) {
	average(s); // 排序之前应该先求过平均分
	int i, j;
	Student t;
	for (i = 4; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (s[j].ave < s[j + 1].ave) {
				t = s[j];
				s[j] = s[j + 1];
				s[j + 1] = t;
			}
		}
	}
}
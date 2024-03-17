// 预编译命令
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define STACK_INIT_SIZE 10 // 顺序栈存储空间的初始分配量
#define STACKINCREMENT 2   // 顺序栈存储空间的分配增量

// 输出顺序栈的元素
void PrintStack(SqStack S) {
	SElemType *p;
	for (p = S.base; p < S.top; p++) {
		printf("%d\t", *p);
	}
}

// 输入n个元素入栈
Status CreateStack(SqStack &S, int n) {
	int i;
	if (n > S.stacksize)
		return (ERROR);
	printf("输入%d个整型数:", n);
	for (i = 1; i <= n; i++) {
		scanf("%d", S.top++);
	}
	return OK;
}

// 菜单函数
int menu_select() {
	int sn;
	printf("\n显示菜单\n");
	printf("1.初始化栈\n");
	printf("2.创建栈\n");
	printf("3.显示栈\n");
	printf("4.取栈顶元素\n");
	printf("5.入栈\n");
	printf("6.出栈\n");
	printf("7.判断栈空否\n");
	printf("8.销毁栈\n");
	printf("9.数制转换\n");
	// printf("10.括号匹配\n");
	printf("0.退出\n");
	printf("输入 0-8:");
	for (;;) {
		scanf("%d", &sn);
		if (sn < 0 || sn > 9)
			printf("\n输入错误，重选0－8：");
		else
			break;
	}
	return sn;
}

void Conversion() {
	SqStack S;
	InitStack(S);
	int N;
	printf("输入要转换的十进制数:");
	scanf("%d", &N);
	while (N) {
		Push(S, N % 8);
		N /= 8;
	}
	printf("转换后的八进制数为:");
	while (!StackEmpty(S)) {
		int e;
		Pop(S, e);
		printf("%d", e);
	}
	printf("\n");
}

// void BracketMatch() {
// 	SqStack S;
// 	InitStack(S);
// 	char c;
// 	printf("输入括号序列:");
// 	while ((c = getchar()) != '\n') {
// 		if (c == '(')
// 			Push(S, c);
// 		else if (c == ')') {
// 			if (StackEmpty(S)) {
// 				printf("括号不匹配\n");
// 				return;
// 			}
// 			Pop(S, c);
// 		}
// 	}
// 	if (StackEmpty(S))
// 		printf("括号匹配\n");
// 	else
// 		printf("括号不匹配\n");
// }

// 主函数
int main() {
	SqStack S;
	Status s;
	int n;
	SElemType e;
	for (;;) {
		switch (menu_select()) {
		case 1:
			s = InitStack(S);
			if (s)
				printf("初始化成功\n");
			else
				printf("初始化失败\n");
			break;
		case 2:
			printf("输入栈的长度:");
			scanf("%d", &n);
			s = CreateStack(S, n);
			if (s)
				printf("创建成功\n");
			else
				printf("创建失败\n");
			break;
		case 3:
			PrintStack(S);
			break;
		case 4:
			s = GetTop(S, e);
			if (s)
				printf("栈顶元素为%d\n", e);
			else
				printf("栈为空，取栈顶元素失败\n");
			break;
		case 5:
			printf("输入入栈的元素值:");
			scanf("%d", &e);
			s = Push(S, e);
			if (s)
				printf("%d入栈成功\n", e);
			else
				printf("入栈失败\n");
			break;
		case 6:
			s = Pop(S, e);
			if (s)
				printf("%d出栈成功\n", e);
			else
				printf("栈为空，出栈失败\n");
			break;
		case 7:
			s = StackEmpty(S);
			if (s)
				printf("栈为空\n");
			else
				printf("栈不为空\n");
			break;
		case 8:
			s = DestroyStack(S);
			if (s)
				printf("销毁栈成功\n");
			else
				printf("销毁栈失败\n");
			break;
		case 9:
			Conversion();
			break;
		// case 10:
		// 	BracketMatch();
		// 	break;
		case 0:
			printf("程序结束，谢谢使用\n\n");
			exit(0);
		}
	}
	return 0;
}

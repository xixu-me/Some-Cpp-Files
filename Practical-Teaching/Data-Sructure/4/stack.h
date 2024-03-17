// 预编译命令
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define STACK_INIT_SIZE 10 // 顺序栈存储空间的初始分配量
#define STACKINCREMENT 2   // 顺序栈存储空间的分配增量

// 数据结构
typedef int Status;
typedef int SElemType; // 完成数制转换
// typedef char SElemType;	//完成括号匹配
typedef struct {
	SElemType *base; // 存储空间基址
	SElemType *top;	 // 存储空间基址
	int stacksize;	 // 当前分配的存储容量(以sizeof(ElemType)为单位)
} SqStack;

// 构造一个最大空间为 STACK_INIT_SIZE的空顺序栈S
Status InitStack(SqStack &S) {

	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!S.base)
		exit(OVERFLOW); // 存储分配失败
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

// 栈不空，则用e返回栈顶元素
Status GetTop(SqStack S, SElemType &e) {
	if (S.top == S.base)
		return ERROR;
	e = *(S.top - 1);
	return OK;
}

// 给定值e入栈
Status Push(SqStack &S, SElemType e) {
	if (S.top - S.base >= S.stacksize) {
		S.base = (SElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

// 若栈不空，则删除S的栈顶元素，
// 用 e 返回其值，并返回OK；
// 否则返回ERROR
Status Pop(SqStack &S, SElemType &e) {
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}

// 判断栈空否
Status StackEmpty(SqStack S) {
	if (S.top == S.base)
		return OK;
	else
		return ERROR;
}

// 销毁栈
Status DestroyStack(SqStack &S) {
	if (!S.base)
		return ERROR;
	free(S.base);
	return OK;
}

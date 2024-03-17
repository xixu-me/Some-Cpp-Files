// 预编译命令
#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define LIST_INIT_SIZE 10 // 表存储空间的初始分配量
#define LISTINCREMENT 2	  // 线性表存储空间的分配增量

// 数据结构
typedef int Status;
typedef int ElemType;
typedef struct
{
	ElemType *elem; // 存储空间基址
	int length;		// 当前长度
	int listsize;	// 当前分配的存储容量(以sizeof(ElemType)为单位)
} SqList;

// 函数声明
int menu_select();
Status InitList_Sq(SqList &L);
Status CreatList_Sq(SqList &L, int n);
void PrintList_Sq(SqList L);
Status ListInsert_Sq(SqList &L, int i, ElemType e);
Status ListDelete_Sq(SqList &L, int i, ElemType &e);
int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));
Status equal(ElemType x, ElemType y);

// 主函数
int main() {
	SqList L;
	Status s;
	int n, i, e;
	for (;;) {
		switch (menu_select()) {
		case 1:
			s = InitList_Sq(L);
			if (s)
				printf("初始化成功\n");
			else
				printf("初始化失败\n");
			break;
		case 2:
			printf("输入线性表的长度:");
			scanf("%d", &n);
			s = CreatList_Sq(L, n);
			if (s)
				printf("创建成功\n");
			else
				printf("创建失败\n");
			break;
		case 3:
			PrintList_Sq(L);
			break;
		case 4:
			printf("请输入插入的位序:");
			scanf("%d", &i);
			printf("请输入插入的新元素的值:");
			scanf("%d", &e);
			s = ListInsert_Sq(L, i, e);
			if (s)
				printf("插入成功!\n");
			else
				printf("插入失败!\n");
			break;
		case 5:
			printf("输入删除的位序：");
			scanf("%d", &i);
			s = ListDelete_Sq(L, i, e);
			if (s)
				printf("删除了元素%d成功\n", e);
			else
				printf("删除失败\n");
			break;
			break;
		case 6:
			printf("请输入查找的元素的值:");
			scanf("%d", &e);
			i = LocateElem_Sq(L, e, equal); // 指向函数类型的指针作形参，实参用同类型的函数名equal
			if (i)
				printf("%d的逻辑位序是%d\n", e, i);
			else
				printf("查找失败!\n");
			break;
		case 0:
			printf("程序结束，谢谢使用！\n\n");
			exit(0);
		}
	}
	return 0;
}

// 菜单函数
int menu_select() {
	int sn;
	printf("\n显示菜单\n");
	printf("1.初始化\n");
	printf("2.创建\n");
	printf("3.显示\n");
	printf("4.插入\n");
	printf("5.删除\n");
	printf("6.查找\n");
	printf("0.退出\n");
	printf("输入 0-6:");
	for (;;) {
		scanf("%d", &sn);
		if (sn < 0 || sn > 6)
			printf("\n输入错误，重选0－6：");
		else
			break;
	}
	return sn;
}

// 初始化空的动态顺序表函数
Status InitList_Sq(SqList &L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem)
		return (OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

// 创建动态顺序表（输入n个元素）
Status CreatList_Sq(SqList &L, int n) {
	int i;
	if (n > L.listsize)
		return (ERROR);
	printf("输入%d个整型数:", n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &L.elem[i - 1]); // 类C代码中无格式输入字符串，需要补充
	}
	L.length = n;
	return OK;
}

// 输出顺序表元素
void PrintList_Sq(SqList L) {
	int i;
	for (i = 1; i <= L.length; i++) {
		printf("%d\t", L.elem[i - 1]);
	}
	printf("\n");
}

// 插入新元素e到第i个位序
Status ListInsert_Sq(SqList &L, int i, ElemType e) {
	ElemType *newbase, *q, *p;	   // 类C代码中不含变量定义，需要补充
	if (i < 1 || i > L.length + 1) // 插入位置不合法
		return ERROR;
	if (L.length >= L.listsize) // 当前储存空间不足
	{
		newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(ElemType));
		if (!newbase)
			exit(OVERFLOW);			 // 存储位置失败
		L.elem = newbase;			 // 新基址
		L.listsize += LISTINCREMENT; // 增加存储位置
	}
	q = &(L.elem[i - 1]); // 要插入的位置
	for (p = &(L.elem[L.length - 1]); p >= q; --p)
		*(p + 1) = *p; // 插入位置之后的元素右移
	*q = e;			   // 插入e
	++L.length;
	return OK; // 表长增加1
} // ListInsert_Sq

// 删除第i个元素
Status ListDelete_Sq(SqList &L, int i, ElemType &e) {
	ElemType *p, *q; // 补出变量定义
	if ((i < 1) || (i > L.length))
		return ERROR;
	p = &(L.elem[i - 1]);
	e = *p;
	q = L.elem + L.length - 1;
	e = *p;
	q = L.elem + L.length - 1;
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	--L.length;
	return OK;
}

// 查找给定值的位序
int LocateElem_Sq(SqList L, ElemType e, Status (*compare)(ElemType, ElemType) /*指向函数类型的指针作形参*/) {
	ElemType *p;
	int i;		// 补出变量定义
	i = 1;		// 当前元素的逻辑位序
	p = L.elem; // 当前元素的物理地址
	while (i <= L.length && !(*compare)(*(p++), e))
		++i;
	if (i <= L.length)
		return i;
	else
		return 0;
} // LocateElem_Sq

// 判断两个数据元素是否相等的函数
Status equal(ElemType x, ElemType y) // 为LocateElem_Sq函数准备第三个实参
{
	if (x == y)
		return OK;
	else
		return ERROR;
}
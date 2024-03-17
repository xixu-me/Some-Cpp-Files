// 预编译命令
#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

// 数据结构
typedef int Status;
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

// 函数声明
int menu_select();
int menu_select();
void CreateList_L(LinkList &L, int n);
void PrintList_L(LinkList L);
Status GetElem_L(LinkList &L, int i, ElemType &e);
Status ListInsert_L(LinkList &L, int i, ElemType e);
Status ListDelete_L(LinkList &L, int i, ElemType &e);
int LocateElem_L(LinkList L, ElemType e);

// 主函数
int main()
{
	LinkList L;
	int n, i, e, k;
	for (;;)
	{
		switch (menu_select())
		{
		case 1:
			printf("请输入元素的个数:");
			scanf("%d", &n);
			CreateList_L(L, n);
			printf("创建完成\n");
			break;
		case 2:
			PrintList_L(L);
			break;
		case 3:
			printf("请输入要查找的元素的位序:");
			scanf("%d", &i);
			if (GetElem_L(L, i, e) == OK) // 调用取元素函数，如果成功，返回元素值给 e
			{
				printf("第%d个元素的值是%d\n", i, e);
			}
			else // 如果失败，输出错误信息
			{
				printf("查找失败，不存在第%d个元素\n", i);
			}
			break;
		case 4:
			printf("请输入要插入的元素的位序和值，用空格隔开:");
			scanf("%d %d", &i, &e);
			if (ListInsert_L(L, i, e) == OK) // 调用插入函数，如果成功，输出插入成功信息
			{
				printf("插入成功\n");
			}
			else // 如果失败，输出错误信息
			{
				printf("插入失败，插入位置不合法\n");
			}
			break;
		case 5:
			printf("请输入要删除的元素的位序:");
			scanf("%d", &i);
			if (ListDelete_L(L, i, e) == OK) // 调用删除函数，如果成功，返回删除的元素值给 e，并输出删除成功信息
			{
				printf("删除成功，删除的元素值是%d\n", e);
			}
			else // 如果失败，输出错误信息
			{
				printf("删除失败，删除位置不合法\n");
			}
			break;
		case 6:
			printf("请输入要查找的元素的值:");
			scanf("%d", &e);
			k = LocateElem_L(L, e); // 调用查找函数（已知元素找位序），返回位序给 k
			if (k != 0)				// 如果 k 不为 0，说明找到了元素 e，并输出其位序
			{
				printf("找到了元素%d，它的位序是%d\n", e, k);
			}
			else // 如果 k 为 0，说明没有找到元素 e，并输出查找失败信息
			{
				printf("查找失败，不存在元素%d\n", e);
			}

			break;
		case 0:
			printf("程序结束，谢谢使用！\n\n");
			exit(0);
		}
	}
	return 0;
}

int menu_select()
{
	int sn;
	printf("\n显示菜单\n");
	printf("1.创建\n");
	printf("2.显示\n");
	printf("3.取元素\n");
	printf("4.插入\n");
	printf("5.删除\n");
	printf("6.查找\n");
	printf("0.退出\n");
	printf("输入 0-6:");
	for (;;)
	{
		scanf("%d", &sn);
		if (sn < 0 || sn > 6)
			printf("\n输入错误，重选0－6：");
		else
			break;
	}
	return sn;
}

// 创建单链表，头插法，已知线性表的长度
void CreateList_L(LinkList &L, int n)
{
	LinkList p;
	int i;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	printf("请逆序输入%d个元素:\n", n);
	for (i = n; i >= 1; i--)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data); // 格式输入字符串补出来
		p->next = L->next;
		L->next = p;
	}
}

// 输出单链表
void PrintList_L(LinkList L)
{
	LinkList p;
	p = L->next;
	printf("输出链表中的元素:\n");
	while (p)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}

// 取元素函数
Status GetElem_L(LinkList &L, int i, ElemType &e)
{
	// 在单链表 L 中查找第 i 个元素，并将其值赋给 e
	LinkList p;		   // 定义一个指针 p
	int j;			   // 定义一个计数器 j
	p = L->next;	   // 让 p 指向链表 L 的第一个结点
	j = 1;			   // 初始化 j 为 1
	while (p && j < i) // p 不为空且计数器 j 还没有等于 i 时，循环继续
	{
		p = p->next; // 让 p 指向下一个结点
		j++;		 // 让 j 增加 1
	}
	if (!p || j > i) // 如果 p 为空或者 j 大于 i，说明第 i 个元素不存在
	{
		return ERROR; // 返回错误标志
	}
	e = p->data; // 取出第 i 个元素的数据，赋给 e
	return OK;	 // 返回成功标志
}

// 插入函数
Status ListInsert_L(LinkList &L, int i, ElemType e)
{
	// 在单链表 L 中的第 i 个位置插入新的元素 e
	LinkList p, s;		   // 定义两个指针 p 和 s
	int j;				   // 定义一个计数器 j
	p = L;				   // 让 p 指向链表 L 的头结点
	j = 0;				   // 初始化 j 为 0
	while (p && j < i - 1) // 寻找第 i-1 个结点，p 指向该结点
	{
		p = p->next;
		j++;
	}
	if (!p || j > i - 1) // 如果 p 为空或者 j 大于 i-1，说明插入位置不合法
	{
		return ERROR; // 返回错误标志
	}
	s = (LinkList)malloc(sizeof(LNode)); // 分配一个新的结点 s
	s->data = e;						 // 将新元素 e 赋给 s 的数据域
	s->next = p->next;					 // 将 s 的指针域指向 p 的后继结点
	p->next = s;						 // 将 p 的指针域指向 s 结点
	return OK;							 // 返回成功标志
}

// 删除函数
Status ListDelete_L(LinkList &L, int i, ElemType &e)
{
	// 在单链表 L 中删除第 i 个元素，并用 e 返回其值
	LinkList p, q;				 // 定义两个指针 p 和 q
	int j;						 // 定义一个计数器 j
	p = L;						 // 让 p 指向链表 L 的头结点
	j = 0;						 // 初始化 j 为 0
	while (p->next && j < i - 1) // 寻找第 i-1 个结点，p 指向该结点，且保证 p 的后继不为空（即第 i 个结点存在）
	{
		p = p->next;
		j++;
	}
	if (!(p->next) || j > i - 1) // 如果 p 的后继为空或者 j 大于 i-1，说明删除位置不合法
	{
		return ERROR; // 返回错误标志
	}
	q = p->next;	   // 让 q 指向要删除的结点（即第 i 个结点）
	p->next = q->next; // 将 q 的后继赋给 p 的后继（即相当于断开了 q 结点）
	e = q->data;	   // 将 q 结点的数据赋给 e（用于返回）
	free(q);		   // 释放 q 结点的空间
	return OK;		   // 返回成功标志
}

// 查找函数（已知元素找位序）
int LocateElem_L(LinkList L, ElemType e)
{
	LinkList p;
	int i;
	p = L->next;
	i = 1;
	while (p && p->data != e) // 从第一个结点开始，遍历链表，直到找到元素 e 或者链表结束
	{
		p = p->next;
		i++;
	}
	if (p) // 如果找到了元素 e，返回其位序 i
	{
		return i;
	}
	else // 如果没有找到元素 e，返回 0
	{
		return 0;
	}
}

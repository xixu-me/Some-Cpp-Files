#include <iostream>

using namespace std;

// 定义线索二叉树节点
struct Node {
	int data;
	Node *left, *right;
	int ltag, rtag; // 左右标志位，0表示指向子节点，1表示指向前驱或后继
};

Node *pre = NULL; // 全局变量，记录上一个访问的节点

// 创建线索二叉树
Node *createTree(int data) {
	Node *node = new Node();
	node->data = data;
	node->left = node->right = NULL;
	node->ltag = node->rtag = 0;
	return node;
}

// 中序遍历线索化
void inThreading(Node *node) {
	if (node) {
		inThreading(node->left); // 递归左子树
		if (!node->left) {		 // 如果该节点没有左孩子，设置ltag为1，并让left指向上一个节点
			node->ltag = 1;
			node->left = pre;
		}
		if (pre && !pre->right) { // 如果上一个节点没有右孩子，设置rtag为1，并让right指向当前节点
			pre->rtag = 1;
			pre->right = node;
		}
		pre = node;
		inThreading(node->right); // 递归右子树
	}
}

// 中序遍历线索二叉树
void inOrder(Node *node) {
	while (node) {
		while (!node->ltag) // 如果ltag为0，一直找到最左下节点
			node = node->left;
		cout << node->data << " ";
		while (node->rtag) { // 如果rtag为1，一直找到最右下节点
			node = node->right;
			cout << node->data << " ";
		}
		node = node->right; // 转向右子树
	}
}

// 查找节点的前驱
Node *findPredecessor(Node *node) {
	if (node->ltag) // 如果ltag为1，left指向的就是前驱
		return node->left;
	else
		return NULL;
}

// 查找节点的后继
Node *findSuccessor(Node *node) {
	if (node->rtag) // 如果rtag为1，right指向的就是后继
		return node->right;
	else
		return NULL;
}

// 主函数
int main() {
	Node *root = createTree(1);
	root->left = createTree(2);
	root->right = createTree(3);
	root->left->left = createTree(4);
	root->left->right = createTree(5);
	inThreading(root);
	inOrder(root);
	return 0;
}
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	char data;
	TreeNode *left;
	TreeNode *right;
};

// 创建二叉树
TreeNode *create() {
	char ch;
	cin >> ch;
	if (ch == '#')
		return nullptr;
	TreeNode *node = new TreeNode();
	node->data = ch;
	node->left = create();
	node->right = create();
	return node;
}

// 销毁二叉树
void destroy(TreeNode *root) {
	if (root == nullptr)
		return;
	destroy(root->left);
	destroy(root->right);
	delete root;
}

// 先序遍历
void preOrder(TreeNode *root) {
	if (root == nullptr)
		return;
	cout << root->data << ' ';
	preOrder(root->left);
	preOrder(root->right);
}

// 中序遍历
void inOrder(TreeNode *root) {
	if (root == nullptr)
		return;
	inOrder(root->left);
	cout << root->data << ' ';
	inOrder(root->right);
}

// 后序遍历
void postOrder(TreeNode *root) {
	if (root == nullptr)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << ' ';
}

// 层次遍历
void levelOrder(TreeNode *root) {
	if (root == nullptr)
		return;
	queue<TreeNode *> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode *node = q.front();
		q.pop();
		cout << node->data << ' ';
		if (node->left)
			q.push(node->left);
		if (node->right)
			q.push(node->right);
	}
}

// 用括号表示法输出二叉树
void printWithBrackets(TreeNode *root) {
	if (root == nullptr)
		return;
	cout << root->data;
	if (root->left || root->right) {
		cout << '(';
		printWithBrackets(root->left);
		cout << ',';
		printWithBrackets(root->right);
		cout << ')';
	}
}

int main() {
	TreeNode *root = create();
	preOrder(root);
	cout << endl;
	inOrder(root);
	cout << endl;
	postOrder(root);
	cout << endl;
	levelOrder(root);
	cout << endl;
	printWithBrackets(root);
	cout << endl;
	destroy(root);
	return 0;
}
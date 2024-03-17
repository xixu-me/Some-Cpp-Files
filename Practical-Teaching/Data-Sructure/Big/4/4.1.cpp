#include <iostream>
#include <limits>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 插入节点
TreeNode *insertNode(TreeNode *root, int val) {
	if (root == NULL) {
		return new TreeNode(val);
	}
	if (val < root->val) {
		root->left = insertNode(root->left, val);
	}
	else if (val > root->val) {
		root->right = insertNode(root->right, val);
	}
	return root;
}

// 删除节点
TreeNode *deleteNode(TreeNode *root, int key) {
	if (root == NULL)
		return root;
	if (key < root->val) {
		root->left = deleteNode(root->left, key);
	}
	else if (key > root->val) {
		root->right = deleteNode(root->right, key);
	}
	else {
		if (root->left == NULL) {
			TreeNode *temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode *temp = root->left;
			delete root;
			return temp;
		}
		TreeNode *temp = root->right;
		while (temp && temp->left != NULL)
			temp = temp->left;
		root->val = temp->val;
		root->right = deleteNode(root->right, temp->val);
	}
	return root;
}

// 判断是否为二叉搜索树
bool isValidBST(TreeNode *root, TreeNode *minNode = NULL, TreeNode *maxNode = NULL) {
	if (root == NULL)
		return true;
	if (minNode != NULL && root->val <= minNode->val || maxNode != NULL && root->val >= maxNode->val) {
		return false;
	}
	return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
}

// 查找最大值和第二大值
pair<int, int> findMaxAndSecondMax(TreeNode *root) {
	int maxVal = numeric_limits<int>::min();
	int secondMaxVal = numeric_limits<int>::min();
	TreeNode *curr = root;
	while (curr) {
		if (curr->val > maxVal) {
			secondMaxVal = maxVal;
			maxVal = curr->val;
		}
		else if (curr->val > secondMaxVal && curr->val < maxVal) {
			secondMaxVal = curr->val;
		}
		curr = curr->right;
	}
	return { maxVal, secondMaxVal };
}

// 主函数，用于测试以上所有功能
int main() {
	int n;
	TreeNode *root = NULL;
	cout << "Enter a number to insert: ";
	while (true) {
		int val;
		cin >> val;
		if (val == -1)
			break;
		root = insertNode(root, val);
	}

	cout << "Is valid BST: " << (isValidBST(root) ? "Yes" : "No") << endl;

	auto maxAndSecondMax = findMaxAndSecondMax(root);
	cout << "Max: " << maxAndSecondMax.first << ", Second Max: " << maxAndSecondMax.second << endl;

	cout << "Enter a number to delete: ";
	cin >> n;
	root = deleteNode(root, n);
	cout << "After deleting " << n << ", is valid BST: " << (isValidBST(root) ? "Yes" : "No") << endl;

	return 0;
}
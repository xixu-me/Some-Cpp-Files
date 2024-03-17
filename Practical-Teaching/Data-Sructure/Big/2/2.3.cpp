#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Node {
	int weight;
	string code;
	Node *left, *right;
	Node(int w) : weight(w), left(NULL), right(NULL) {}
};

struct cmp {
	bool operator()(Node *a, Node *b) {
		return a->weight > b->weight;
	}
};

void generateHuffmanCode(Node *root, string str) {
	if (!root)
		return;
	if (!root->left && !root->right) {
		root->code = str;
	}
	generateHuffmanCode(root->left, str + "0");
	generateHuffmanCode(root->right, str + "1");
}

int main() {
	int n;
	cin >> n;
	priority_queue<Node *, vector<Node *>, cmp> pq;
	for (int i = 0; i < n; ++i) {
		int w;
		cin >> w;
		pq.push(new Node(w));
	}
	while (pq.size() != 1) {
		Node *left = pq.top();
		pq.pop();
		Node *right = pq.top();
		pq.pop();
		Node *parent = new Node(left->weight + right->weight);
		parent->left = left;
		parent->right = right;
		pq.push(parent);
	}
	generateHuffmanCode(pq.top(), "");
	vector<Node *> nodes;
	nodes.push_back(pq.top());
	while (!nodes.empty()) {
		Node *node = nodes.back();
		nodes.pop_back();
		if (node->left)
			nodes.push_back(node->left);
		if (node->right)
			nodes.push_back(node->right);
		if (!node->left && !node->right) {
			cout << node->code << " ";
		}
	}
	return 0;
}
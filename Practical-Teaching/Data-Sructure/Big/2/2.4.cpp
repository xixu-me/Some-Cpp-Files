#include <iostream>
#include <map>

using namespace std;

class Node {
public:
	string name;
	map<string, Node *> children;

	Node(string name) : name(name) {}

	Node *find(string path) {
		if (path.empty())
			return this;
		int pos = path.find('/');
		string first = pos == string::npos ? path : path.substr(0, pos);
		string rest = pos == string::npos ? "" : path.substr(pos + 1);
		if (children.count(first) == 0)
			return nullptr;
		return children[first]->find(rest);
	}

	void add(string path) {
		int pos = path.find('/');
		string first = pos == string::npos ? path : path.substr(0, pos);
		string rest = pos == string::npos ? "" : path.substr(pos + 1);
		if (children.count(first) == 0)
			children[first] = new Node(first);
		if (!rest.empty())
			children[first]->add(rest);
	}

	bool remove(string path) {
		int pos = path.find('/');
		string first = pos == string::npos ? path : path.substr(0, pos);
		string rest = pos == string::npos ? "" : path.substr(pos + 1);
		if (children.count(first) == 0)
			return false;
		if (rest.empty()) {
			delete children[first];
			children.erase(first);
			return true;
		}
		return children[first]->remove(rest);
	}
};

int main() {
	Node root("/");
	root.add("dir1/dir2/file");
	cout << (root.find("dir1/dir2/file") != nullptr) << endl;
	cout << (root.find("dir1/dir2") != nullptr) << endl;
	cout << (root.find("dir1") != nullptr) << endl;
	cout << (root.find("dir1/dir3") == nullptr) << endl;
	root.remove("dir1/dir2/file");
	cout << (root.find("dir1/dir2/file") == nullptr) << endl;
	return 0;
}
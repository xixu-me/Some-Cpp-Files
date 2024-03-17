#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cmath>

using namespace std;

const int Base = 31;
const int TableSize = 1000;

struct Node {
	string key;
	int value;
	Node(string key, int value) : key(key), value(value) {}
};

class HashTable {
private:
	vector<list<Node>> table;
	int hashFunc(string key) {
		int hashVal = 0;
		for (int i = 0; i < key.length(); i++) {
			hashVal = (hashVal + key[i] * static_cast<long long>(pow(Base, i))) % TableSize;
		}
		return hashVal;
	}

public:
	HashTable() {
		table.resize(TableSize);
	}
	void insert(string key, int value) {
		int hashVal = hashFunc(key);
		for (auto &node : table[hashVal]) {
			if (node.key == key) {
				node.value = value;
				return;
			}
		}
		table[hashVal].push_back(Node(key, value));
	}
	int search(string key) {
		int hashVal = hashFunc(key);
		for (auto &node : table[hashVal]) {
			if (node.key == key) {
				return node.value;
			}
		}
		return -1;
	}
	void destroy() {
		for (auto &bucket : table) {
			bucket.clear();
		}
	}
};

int main() {
	HashTable ht;
	ht.insert("Alice", 1);
	ht.insert("Bob", 2);
	cout << "Alice: " << ht.search("Alice") << endl;
	cout << "Bob: " << ht.search("Bob") << endl;
	cout << "Charlie: " << ht.search("Charlie") << endl;
	ht.destroy();
	return 0;
}

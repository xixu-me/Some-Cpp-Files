// 输入10个人的名字，按从大到小排序输出。

#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<string> names;
	string input;

	cout << "请输入若干姓名，以空格分隔，按回车结束：" << endl;

	getline(cin, input);

	stringstream ss(input);
	string name;
	while (ss >> name)
		names.push_back(name);

	sort(names.begin(), names.end());

	cout << "排序后的姓名为：" << endl;

	for (int i = 0; i < names.size(); i++)
		cout << names[i] << " ";
	cout << endl;

	return 0;
}
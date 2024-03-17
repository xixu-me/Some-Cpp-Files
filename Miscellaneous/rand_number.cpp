#include <bits/stdc++.h>

using namespace std;

double average(const vector<int> &v) {
	if (v.empty()) {
		return 0;
	}

	double sum = 0;
	for (auto &&i : v) {
		sum += i;
	}

	return sum / v.size();
}

int main() {
	int cnt = 1;
	vector<int> v;
	while (true) {
		srand(time(nullptr));
		int rand_num = rand() % 100 + 1;
		cout << "Random number" << ' ' << cnt << ": " << rand_num << endl;
		v.push_back(rand_num);
		cout << "Average: " << average(v) << endl;
		cnt++;
		this_thread::sleep_for(chrono::seconds(1));
	}

	return 0;
}
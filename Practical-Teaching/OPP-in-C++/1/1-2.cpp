#include <bits/stdc++.h>

using namespace std;

int main() {
	ifstream in("input.txt");
	if (!in) {
		cout << "Error opening file";
		exit(1);
	}
	ofstream out("output.txt");

	double max;
	in >> max;

	double i;
	while (in >> i)
		if (i > max)
			max = i;

	out << max << endl;

	in.close();
	out.close();

	return 0;
}

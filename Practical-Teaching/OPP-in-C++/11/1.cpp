// 实现电话簿管理程序， Mytel类描述单个电话号码，TelManager类负责管理电话号码。把增、删、改、查功能封装到该类中。要求电话号码能从磁盘读写。

#include <bits/stdc++.h>

using namespace std;

class Mytel {
public:
	void getdata() { cin >> name >> telno; }
	void setname(char a[]) { strcpy(name, a); }
	void settelno(char a[]) { strcpy(telno, a); }
	void putdata() { cout << name << setw(12) << telno << endl; }
	string getname() { return name; }
	string gettelno() { return telno; }

private:
	char name[12];
	char telno[12];
};

class TelManager {
private:
	vector<Mytel> a;

public:
	void loadfile() {
		ifstream input("phone.txt");
		if (!input) {
			cout << "File cannot be opened." << endl;
			return;
		}
		Mytel s;
		char name[12], telno[12];
		input >> name >> telno;
		s.setname(name);
		s.settelno(telno);
		while (input) {
			a.push_back(s);
			input >> name >> telno;
			s.setname(name);
			s.settelno(telno);
		};
		input.close();
	}
	void display() {
		cout << "姓名" << setw(8) << "电话" << endl;
		for (int i = 0; i < a.size(); i++)
			cout << a[i].getname() << setw(12) << a[i].gettelno() << endl;
	}
	void search() {
		string sname;
		cout << "输入要查询的姓名（可只输入姓氏）:";
		cin >> sname;
		cout << "输出查询结果:" << endl;
		cout << "姓名" << setw(8) << "电话" << endl;
		for (int i = 0; i < a.size(); i++)
			if (a[i].getname() == sname)
				a[i].putdata();
	}
	void add() {
		Mytel one;
		cout << "姓名" << setw(8) << "电话" << endl;
		one.getdata();
		a.push_back(one);
	}
	void del() {
		string dname;
		cout << "输入要删除的姓名（可只输入姓氏）:";
		cin >> dname;
		for (int i = 0; i < a.size(); i++)
			if (a[i].getname() == dname)
				a.erase(a.begin() + i);
	}
	void modify() {
		string mname;
		char mtelno[12];
		cout << "输入要修改的姓名（可只输入姓氏）:";
		cin >> mname;
		for (int i = 0; i < a.size(); i++)
			if (a[i].getname() == mname) {
				cout << "电话：";
				cin >> mtelno;
				a[i].settelno(mtelno);
			}
	}
	void writefile() {
		ofstream file("phone.txt");
		for (int i = 0; i < a.size(); i++)
			file << a[i].getname() << "\t" << a[i].gettelno() << endl;
		file.close();
	}
};

int main() {
	int sel;
	TelManager m;
	while (1) {
		cout << "***********************电话薄管理系统***********************";
		cout << endl
			 << endl;
		cout << "1:加载数据      2:输出数据      3:按姓名查询      4:添加数据" << endl
			 << "5:删除数据      6:修改数据      7.保存数据        0:退出" << endl;
		cout << "************************************************************";
		cout << "\n请选择 (0 - 7): ";
		cin >> sel;
		switch (sel) {
		case 1:
			m.loadfile();
			break;
		case 2:
			m.display();
			break;
		case 3:
			m.search();
			break;
		case 4:
			m.add();
			break;
		case 5:
			m.del();
			break;
		case 6:
			m.modify();
			break;
		case 7:
			m.writefile();
			break;
		case 0:
			exit(1);
		}
	}
	return 0;
}

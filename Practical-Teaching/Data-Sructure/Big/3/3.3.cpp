#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 定义课程结构体，包含课程号，学分，入度，邻接表
struct Course {
	string id;												   // 课程号
	int credit;												   // 学分
	int indegree;											   // 入度
	vector<int> adj;										   // 邻接表
	Course(string i, int c) : id(i), credit(c), indegree(0) {} // 构造函数
};

// 定义拓扑排序函数，参数为课程数组，学期总数，每学期学分上限，课程总数
void topologicalSort(vector<Course> &courses, int term, int limit, int num) {
	queue<int> q;		// 定义一个队列，用于存放入度为0的课程
	vector<int> result; // 定义一个数组，用于存放拓扑排序的结果
	int count = 0;		// 定义一个计数器，用于记录已经安排的课程数
	// 遍历课程数组，将入度为0的课程入队，并输出
	for (int i = 0; i < num; i++) {
		if (courses[i].indegree == 0)
			q.push(i);
	}
	// 当队列不为空时，循环执行以下操作
	while (!q.empty()) {
		int u = q.front();	 // 取出队首元素
		q.pop();			 // 出队
		result.push_back(u); // 将队首元素加入结果数组
		count++;			 // 计数器加一
		// 遍历队首元素的邻接表，将其邻接课程的入度减一，如果入度变为0，则入队
		for (int v : courses[u].adj) {
			courses[v].indegree--;
			if (courses[v].indegree == 0) {
				q.push(v);
			}
		}
	}
	// 如果计数器等于课程总数，说明拓扑排序成功，否则说明有环，无法完成所有课程
	if (count == num) {
		cout << "拓扑排序成功，结果为：" << endl;
		// 输出拓扑排序结果
		for (int i = 0; i < num; i++) {
			cout << courses[result[i]].id << " ";
		}
		cout << endl;
		// 定义一个二维数组，用于存放每个学期的课程安排
		vector<vector<int>> plan(term);
		// 定义一个变量，用于记录当前安排到哪个学期
		int current = 0;
		// 定义一个变量，用于记录当前学期的已安排学分
		int credit = 0;
		// 遍历拓扑排序结果，按照策略安排课程
		for (int i = 0; i < num; i++) {
			// 如果当前课程的学分加上已安排学分超过学分上限，或者当前学期已满，则安排到下一个学期
			if (credit + courses[result[i]].credit > limit || plan[current].size() == term) {
				current++;
				credit = 0;
			}
			// 如果当前学期还有空余，且没有超过学分上限，则安排当前课程到当前学期
			if (current < term && credit + courses[result[i]].credit <= limit) {
				plan[current].push_back(result[i]);
				credit += courses[result[i]].credit;
			}
		}
		// 输出每个学期的课程安排
		cout << "按照给定的条件，最少需要" << current + 1 << "个学期完成所有课程，具体安排如下：" << endl;
		for (int i = 0; i <= current; i++) {
			cout << "第" << i + 1 << "个学期的课程有：";
			for (int j = 0; j < plan[i].size(); j++) {
				cout << courses[plan[i][j]].id << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "拓扑排序失败，无法完成所有课程的学习" << endl;
	}
}

// 定义主函数，用于测试代码的功能
int main() {
	// 定义课程总数，学期总数，每学期学分上限
	int num, term, limit;
	// 从标准输入读取这些参数
	cout << "请输入学期总数，每学期学分上限，课程总数，用空格隔开：" << endl;
	cin >> term >> limit >> num;
	// 定义一个课程数组，用于存放课程信息
	vector<Course> courses;
	// 初始化课程信息，根据题目给定的数据
	courses.push_back(Course("C1", 2));
	courses.push_back(Course("C2", 3));
	courses.push_back(Course("C3", 4));
	courses.push_back(Course("C4", 3));
	courses.push_back(Course("C5", 2));
	courses.push_back(Course("C6", 3));
	courses.push_back(Course("C7", 4));
	courses.push_back(Course("C8", 4));
	courses.push_back(Course("C9", 5));
	courses.push_back(Course("C10", 3));
	courses.push_back(Course("C11", 2));
	courses.push_back(Course("C12", 5));
	courses.push_back(Course("C13", 3));
	courses.push_back(Course("C14", 3));
	// 初始化课程之间的先修关系，根据题目给定的数据
	courses[0].adj.push_back(1);   // C1 -> C2
	courses[0].adj.push_back(2);   // C1 -> C3
	courses[0].adj.push_back(3);   // C1 -> C4
	courses[0].adj.push_back(11);  // C1 -> C12
	courses[0].adj.push_back(13);  // C1 -> C14
	courses[1].adj.push_back(2);   // C2 -> C3
	courses[2].adj.push_back(4);   // C3 -> C5
	courses[2].adj.push_back(6);   // C3 -> C7
	courses[2].adj.push_back(7);   // C3 -> C8
	courses[3].adj.push_back(4);   // C4 -> C5
	courses[3].adj.push_back(12);  // C4 -> C13
	courses[4].adj.push_back(6);   // C5 -> C7
	courses[5].adj.push_back(7);   // C6 -> C8
	courses[5].adj.push_back(12);  // C6 -> C13
	courses[5].adj.push_back(13);  // C6 -> C14
	courses[8].adj.push_back(5);   // C9 -> C6
	courses[8].adj.push_back(9);   // C9 -> C10
	courses[8].adj.push_back(10);  // C9 -> C11
	courses[8].adj.push_back(11);  // C9 -> C12
	courses[9].adj.push_back(11);  // C10 -> C12
	courses[10].adj.push_back(5);  // C11 -> C6
	courses[10].adj.push_back(13); // C11 -> C14
	courses[12].adj.push_back(13); // C13 -> C14
	// 更新每个课程的入度
	for (int i = 0; i < num; i++) {
		for (int j : courses[i].adj) {
			courses[j].indegree++;
		}
	}
	// 调用拓扑排序函数，输出结果
	topologicalSort(courses, term, limit, num);
	return 0;
}

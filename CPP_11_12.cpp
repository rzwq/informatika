#include <algorithm>
#include <array>
#include <cctype>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <list>
#include <numeric>
#include <string>
#include <unordered_set>
#include <utility>

using namespace std;

void cpp_11_1() {
	array<int, 10> a;
	int num = 1;

	for (auto it = a.begin(); it != a.end(); ++it) {
		*it = num;
		++num;
	}

	cout << fixed << setprecision(2);
	cout << accumulate(a.begin(), a.end(), 0) << endl;
	cout << accumulate(a.begin(), a.end(), 0) * 1.0 / 10 << endl;
}

void cpp_11_2() {
	deque<pair<unsigned int, string>> reserve;
	size_t amount;

	cout << "Enter orders amount: ";
	cin >> amount;
	cout << "Enter orders (`order` `priority`)" << endl;

	for (int i = 0; i < amount; ++i) {
		unsigned int priority;
		string order;
		cin >> order >> priority;

		size_t index = reserve.size();
		reserve.push_back({priority, order});

		while (index and reserve[index - 1].first < reserve[index].first) {
			swap(reserve[index - 1], reserve[index]);
			--index;
		}
	}

	while (!reserve.empty()) {
		cout << reserve[0].second << "(" << reserve[0].first << ")" << " ready!"
			 << endl;
		reserve.pop_front();
	}
}

void cpp_11_3() {
	list<string> students = {"Иванов", "Петров", "Сидоров", "Aлексеев",
							 "Борисов"};
	// sort students
	students.sort();
	// remove student which name starts with `A`.
	students.remove_if([](string student) { return student[0] == 'A'; });

	for (auto student : students) {
		cout << student << endl;
	}
}

void cpp_11_4() {
	forward_list<int> list;

	for (int i = 5; i; --i) {
		list.insert_after(list.before_begin(), i);
	}

	for (auto num : list) {
		cout << num << endl;
	}
}

void cpp_11_5() {
	list<int> a = {1, 3, 5, 7};
	list<int> b = {2, 3, 6, 7, 8};

	a.merge(b);
	a.unique();
	a.remove_if([](int num) { return num > 6; });

	for (auto it = a.begin(); it != a.end(); ++it) {
		cout << *it << endl;
	}
}

void cpp_12_1() {
	ifstream ifs("input.txt");
	ofstream ofs("output.txt");

	string ignore, input, output;
	cout << "Enter characters to remove: ";  // useragreement
	cin >> ignore;

	unordered_set<char> ignore_set;

	for (char s : ignore) {
		ignore_set.insert(tolower(s));
	}

	output.reserve(input.size());
	getline(ifs, input);

	for (auto s : input) {
		if (ignore_set.count(tolower(s))) continue;
		output.push_back(s);
	}

	ofs << output << endl;
	ofs.close();
	ifs.close();
}

void cpp_12_2() {
	ifstream ifs1("input1.txt");
	ifstream ifs2("input2.txt");
	string joke1, joke2;

	ifs1 >> joke1;
	ifs2 >> joke2;

	cout << ((joke2.find(joke1) != string::npos) ? "yes" : "no") << endl;
	ifs1.close();
	ifs2.close();
}

void cpp_12_3() {
}

int main() {
	// cpp_11_1();
	// cpp_11_2();
	// cpp_11_3();
	// cpp_11_4();
	// cpp_11_5();
	// cpp_12_1();
	// cpp_12_2();
	// cpp_12_3();
}

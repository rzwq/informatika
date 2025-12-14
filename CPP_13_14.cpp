#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

void commonLeters() {
	string word1, word2;
	set<char> letters1, letters2;

	cin >> word1;
	cin >> word2;

	for (char ch : word1) {
		letters1.insert(ch);
	}

	for (char ch : word2) {
		letters2.insert(ch);
	}

	for (auto ch : "abcdefghijklmnopqrstuvwxy") {
		if (letters1.count(ch) && letters2.count(ch)) cout << ch;
	}

	cout << endl;
}

void bookPointer() {
	map<int, set<string>> books;
	int words;
	cin >> words;

	for (int i = 0; i < words; ++i) {
		string word;
		int page;
		cin >> word >> page;
		books[page].insert(word);
	}

	for (auto page : books) {
		vector<string> words;
		for (auto word : page.second) {
			words.push_back(word);
		}
		sort(words.begin(), words.end());
		if (page.second.size() == 0) continue;

		cout << page.first;
		for (auto word : words) {
			cout << " " << word;
		}
		cout << endl;
	};
}

template <typename T> void Duplicate(std::vector<T> &v) {
	int size = v.size();

	for (size_t i = 0; i < size; ++i) {
		v.push_back(v[i]);
	}
}

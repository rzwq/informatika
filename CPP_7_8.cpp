#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

void cpp_7_1() {
	int n;
	cout << "Enter friends amount: ";
	cin >> n;

	vector<float> score(3, 0);
	int a, b, c;
	string fname, lname;

	for (int i = 0; i < n; ++i) {
		cin >> fname >> lname >> a >> b >> c;
		score[0] += a;
		score[1] += b;
		score[2] += c;
	}

	cout << fixed << setprecision(1);
	cout << score[0] / n << endl;
	cout << score[1] / n << endl;
	cout << score[2] / n << endl;
}

void cpp_8_1() {
}

void cpp_8_2() {
	size_t n;
	cout << "Enter array size: ";
	cin >> n;

	// Инициаллизация массива и вектора для случайных значений
	double *ptr = new double[n];
	vector<int> numbers(n, 0);
	int fill = 1;

	for (auto &num : numbers) {
		num = fill;
		++fill;
	}

	shuffle(numbers.begin(), numbers.end(), mt19937(random_device()()));

	for (size_t i = 0; i < n; ++i) {
		ptr[i] = numbers[i];
		cout << *(ptr + i) << " ";
	}

	delete[] ptr;

	cout << endl << "Array sum: " << ((1 + n) * n / 2) << endl;
}

int main() {
	// cpp_7_1();
	// cpp_8_1();
	// cpp_8_2();
}

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const string spell[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main() {
	int carry = 0;
	char digit;
	vector<int> sum(105, 0);
	while (cin >> digit) {
		carry = digit - '0';
		for (int i = 0; 0 < carry; ++i) {
			int tmp = sum[i] + carry;
			sum[i] = tmp % 10;
			carry = tmp / 10;
		}
	}

	int size = sum.size()-1;
	while (sum[size] == 0)
		--size;

	for (int i = size; 0 < i; --i)
		cout << spell[sum[i]] << " ";
	cout << spell[sum[0]] << endl;

	return 0;
}
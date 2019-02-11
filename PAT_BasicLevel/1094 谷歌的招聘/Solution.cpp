#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num) {
	if (num == 1) {
		return false;
	}

	for (int i = 2; i*i <= num; i += 1) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int N, K, mo = 1, tmp = 0;
	string num;
	bool flag = false;
	cin >> N >> K;
	getline(cin, num);
	getline(cin, num);
	vector<int> digits(N);
	for (int i = 0; i < N; ++i) {
		digits[i] = num[i] - '0';
	}

	for (int i = 0; i < K - 1; ++i)
		mo *= 10;

	int k = 0, L = 0;
	for (int i = 0, j; i + K <= N; ++i) {
		tmp = 0;
		for (int j = i; j < i + K; ++j)
			tmp = tmp * 10 + digits[j];
		if (isPrime(tmp)) {
			for (j = i; j < i + K; ++j)
				cout << num[j];
			cout << '\n';
			return 0;
		}
	}

	cout << "404" << '\n';

	return 0;
}
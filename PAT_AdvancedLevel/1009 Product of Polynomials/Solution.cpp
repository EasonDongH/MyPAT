#include <bits/stdc++.h>
using namespace std;

#define MAXN 1005

double p1[MAXN] = { 0 }, p2[MAXN] = { 0 }, res[2 * MAXN] = { 0 };

void polyMulti() {
	int exp;

	for (int i = 0; i < MAXN; ++i) {
		for (int j = 0; j < MAXN; ++j) {
			exp = i + j;
			res[exp] += p1[i] * p2[j];
		}
	}
}

int main() {
	int K, exp;

	cin >> K;
	while (K--) {
		cin >> exp;
		cin >> p1[exp];
	}

	cin >> K;
	while (K--) {
		cin >> exp;
		cin >> p2[exp];
	}

	polyMulti();

	K = 0;
	int index[2 * MAXN];
	for (int i = 2 * MAXN - 1; 0 <= i; --i) {
		if (fabs(res[i]) > 0.00000001) {
			index[K++] = i;
		}
	}

	cout << K;
	for (int i = 0; i < K; ++i) {
		printf(" %d %.1f", index[i], res[index[i]]);
	}
	cout << endl;

	return 0;
}
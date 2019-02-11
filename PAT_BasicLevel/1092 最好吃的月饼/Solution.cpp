#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, tmp;
	cin >> N >> M;
	vector<int> count(N);
	vector<int> index;

	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> tmp;
			count[j] += tmp;
		}
	}

	int maxSales = 0;
	for (int i = 0; i < N; ++i) {
		if (maxSales < count[i]) {
			index.clear();
			index.push_back(i);
			maxSales = count[i];
		}
		else if (maxSales == count[i])
			index.push_back(i);
	}

	cout << maxSales << '\n';
	for (int i = 0, size = index.size(); i<size; ++i) {
		if (i != 0)
			cout << " ";
	    cout << index[i] + 1;
	}

	return 0;
}
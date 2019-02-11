#include <bits/stdc++.h>
using namespace std;

int main() {
	string A, B, ans;
	vector<bool> mark(128, false);

	getline(cin, A);
	getline(cin, B);

	for (auto c : A) {
		if (mark[c] == false) {
			mark[c] = true;
			ans += c;
		}
	}

	for (auto c : B) {
		if (mark[c] == false) {
			mark[c] = true;
			ans += c;
		}
	}

	cout << ans << '\n';

	return 0;
}
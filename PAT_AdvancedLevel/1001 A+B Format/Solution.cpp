#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, res;
	bool negative = false;
	string ans;

	cin >> a >> b;

	res = a + b;
	if (res < 0) {
		res = -res;
		negative = true;
	}
	else if (res == 0) {
		cout << "0\n";
		return 0;
	}

	int cnt = 0;
	while (res > 0) {
		if (cnt++ == 3) {
			cnt =1;
			ans = ',' + ans;
		}
		ans = to_string(res % 10) + ans;
		res /= 10;
	}

	if (negative)
		ans = '-' + ans;
	cout << ans << '\n';

	return 0;
}
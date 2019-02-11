#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	int n1, n2, n3, size;
	string str;
	cin >> str;
	size = str.size();
	n1 = n3 = (int)ceil(size / 3.0);
	n2 = size + 2 - n1 - n3;

	for (int i = 0, j = size - 1; i < n1 - 1; ++i, --j)
	{
		cout << str[i];
		for (int k = 0, n = n2 - 2; k < n; ++k)
			cout << " ";
		cout << str[j] << endl;
	}
	for (int i = n1 - 1, n = n1 + n2 - 1; i < n; ++i)
		cout << str[i];
	cout << endl;

	return 0;
}
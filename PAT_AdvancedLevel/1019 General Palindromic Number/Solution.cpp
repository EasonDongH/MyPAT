#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> inBase;

void DecToAnyBase(int dec, int b)
{
	while (0 < dec)
	{
		int digit = dec % b;
		dec /= b;
		inBase.push_back(digit);
	}
	reverse(inBase.begin(), inBase.end());
}

bool isPalindromic()
{
	for (int i = 0, j = inBase.size() - 1; i < j; ++i, --j)
	{
		if (inBase[i] != inBase[j])
			return false;
	}
	return true;
}

int main()
{
	int dec, b;
	cin >> dec >> b;

	DecToAnyBase(dec, b);
	bool flag = isPalindromic();
	printf("%s\n", flag ? "Yes" : "No");

	cout << inBase[0];
	for (int i = 1, size = inBase.size(); i < size; ++i)
	{
		cout << " " << inBase[i];
	}
	cout << endl;

	return 0;
}
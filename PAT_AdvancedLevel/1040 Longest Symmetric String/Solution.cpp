#include <iostream>
#include <string>
using namespace std;

int longestSymmetricLength(const string& s, int index)
{
	int j = 1;
	for (int i = index, size = s.size(); i + j < size && 0 <= i - j; ++j)
	{
		if (s[i - j] != s[i + j])
			break;
	}
	return 2 * (j - 1) + 1;
}

int main()
{
	string str;
	getline(cin, str);
	int maxLen = 1;
	for (int i = 1, size = str.size(); i < size; ++i)
	{
		int len = longestSymmetricLength(str, i);
		if (maxLen < len)
			maxLen = len;
	}
	printf("%d\n", maxLen);

	return 0;
}
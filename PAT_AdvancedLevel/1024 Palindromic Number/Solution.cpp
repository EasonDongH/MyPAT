#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isPalindromic(const string& str)
{
	for (int i = 0, j = str.size() - 1; i < j; ++i, --j)
	{
		if (str[i] != str[j])
			return false;
	}
	return true;
}

string Add(const string& num)
{
	int carry = 0;
	string ans;
	for (int i = 0, size = num.size(), j = num.size() - 1; i < size && 0 <= j; ++i, --j)
	{
		int tmp = (num[i] - '0') + (num[j] - '0') + carry;
		ans += (tmp % 10) + '0';
		carry = tmp / 10;
	}
	while (carry > 0)
	{
		ans += (carry % 10) + '0';
		carry /= 10;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}

int main()
{
	int k;
	string num;
	cin >> num >> k;
	int i;
	for (i = 0; i < k; ++i)
	{
		if (isPalindromic(num))
			break;
		num = Add(num);
	}
	printf("%s\n%d\n", num.c_str(), i);

	return 0;
}
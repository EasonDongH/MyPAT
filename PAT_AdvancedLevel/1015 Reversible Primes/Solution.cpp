#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int anyRadixToDec(const string& num, int D)
{
	int ans = 0, digit;
	for (int i = 0, size = num.size(); i < size; ++i)
	{
		digit = num[i] - '0';
		ans = ans * D + digit;
	}
	return ans;
}

string DecToAnyRadix(int num, int D)
{
	string ans;
	while (0 < num)
	{
		char digit = num % D + '0';
		num /= D;
		ans += digit;
	}
	return ans;
}

bool isPrime(int num)
{
	if (num == 1)
		return false;
	if (num == 2 || num == 3)
		return true;
	for (int i = 2; i*i <= num; ++i)
	{
		if (num % 2 == 0)
			return false;
	}
	return true;
}

int main()
{
	int num, D;
	string N;
	while (true)
	{
		cin >> num;
		if (num < 0)
			break;
		cin >> D;
		bool flag = isPrime(num);
		if (flag)
		{
			N = DecToAnyRadix(num, D);
			num = anyRadixToDec(N, D);
			flag = isPrime(num);
		}
		printf("%s\n", flag ? "Yes" : "No");
	}

	return 0;
}
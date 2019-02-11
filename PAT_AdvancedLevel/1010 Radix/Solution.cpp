#include <iostream>
#include <string>
using namespace std;

long long anyRadixToDec(const string& num, int radix)
{
	int size = num.size(), digit;
	long long ans = 0;
	for (int i = 0; i < size; ++i)
	{
		if (isdigit(num[i]))
		{
			digit = num[i] - '0';
		}
		else
		{
			digit = num[i] - 'a' + 10;
		}

		ans = ans * radix + digit;
	}

	return ans;
}

int findMaxDigit(const string& num)
{
	//assert(num.size() > 0);
	int ans = num[0], size = num.size();
	for (int i = 1; i < size; ++i)
	{
		if (ans < num[i])
			ans = num[i];
	}
	if (isdigit(ans))
		ans -= '0';
	else if (isalpha(ans))
		ans = ans - 'a' + 10;
	return ans;
}

int main()
{
	int tag, radix;
	long long n;
	string N1, N2, N;
	cin >> N1 >> N2 >> tag >> radix;

	if (N1 == N2)
	{
		cout << radix << endl;
		return 0;
	}

	if (tag == 1)
	{
		n = anyRadixToDec(N1, radix);
		N = N2;
	}
	else if (tag == 2)
	{
		n = anyRadixToDec(N2, radix);
		N = N1;
	}

	radix = findMaxDigit(N);
	while (++radix <= 35)
	{
		long long tmp = anyRadixToDec(N, radix);
		if (tmp == n)
		{
			break;
		}
	}

	if (1 <= radix && radix <= 35)
	{
		cout << radix << endl;
	}
	else
	{
		cout << "Impossible\n";
	}

	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct BigUInt
{
	vector<int> num;
	string ToString()
	{
		string ans;
		for (auto n : num)
			ans += to_string(n);
		return ans;
	}
	string Double()
	{
		int carry = 0;
		reverse(num.begin(), num.end());
		for (auto& n : num)
		{
			int tmp = n * 2 + carry;
			n = tmp % 10;
			carry = tmp / 10;
		}
		while (carry > 0)
		{
			num.push_back(carry % 10);
			carry = carry / 10;
		}

		reverse(num.begin(), num.end());

		return ToString();
	}
};

istream& operator >> (istream& in, BigUInt& bu)
{
	char digit;
	while ((in >> digit) && isdigit(digit))
	{
		digit -= '0';
		bu.num.push_back(digit);
	}
	return in;
}

struct BigUInt2
{
	int digit = 9;//int型最大11位数，选择9位保证2倍后还在范围内
	int mo = 1000000000;
	vector<int> num;
	string ToString()
	{
		string ans;
		for (auto n : num)
			ans += to_string(n);
		return ans;
	}
	string Double()
	{
		int carry = 0;
		reverse(num.begin(), num.end());
		for (auto& n : num)
		{
			int tmp = n * 2 + carry;
			n = tmp % mo;
			carry = tmp / mo;
		}
		while (carry > 0)
		{
			num.push_back(carry%mo);
			carry /= mo;
		}
		reverse(num.begin(), num.end());

		return ToString();
	}
};

istream& operator >> (istream& in, BigUInt2& bu)
{
	int N = 0;
	string num;
	getline(cin, num);

	int i;
	for (i = num.size(); 0 <= i - bu.digit; i -= bu.digit)
	{
		string tmp = num.substr(i - bu.digit, bu.digit);
		bu.num.push_back(stoi(tmp));
	}
	string tmp = num.substr(0, i);
	if(tmp.size() > 0)
	  bu.num.push_back(stoi(tmp));

	reverse(bu.num.begin(), bu.num.end());

	return in;
}

int main()
{
	int mark[10] = { 0 };
	BigUInt2 bu;
	cin >> bu;
	string original = bu.ToString();

	for (auto ch : original)
		++mark[ch - '0'];

	string out = bu.Double();
	bool flag = true;
	if (out.size() != original.size())
	{
		flag = false;
	}
	else
	{
		for (auto ch : out)
		{
			if (mark[ch - '0'] == 0)
			{
				flag = false;
				break;
			}
			--mark[ch - '0'];
		}
	}

	printf("%s\n", flag ? "Yes" : "No");
	printf("%s\n", out.c_str());

	return 0;
}
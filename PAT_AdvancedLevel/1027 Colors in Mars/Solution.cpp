#include <iostream>
#include <string>
using namespace std;

char Base[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C' };

string dec2AnyRadix(int dec, int base)
{
	int digit;
	string ans;
	while (dec > 0)
	{
		digit = dec % base;
		dec /= base;
		ans = Base[digit] + ans;
	}
	while (ans.size() < 2)
		ans = '0' + ans;
	return ans;
}

int main()
{
	int d1, d2, d3;
	cin >> d1 >> d2 >> d3;
	cout << '#' << dec2AnyRadix(d1, 13) << dec2AnyRadix(d2, 13) << dec2AnyRadix(d3, 13) << endl;

	return 0;
}
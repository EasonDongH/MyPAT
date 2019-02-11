#include <iostream>
#include <string>
using namespace std;

int main()
{
	double W, T, L, product = 1;
	string str("");

	for (int i = 0; i < 3; ++i)
	{
		cin >> W >> T >> L;
		if (W > T && W > L)
		{
			str += 'W';
			product *= W;
		}
		else if (T > W && T > L)
		{
			str += "T";
			product *= T;
		}
		else if (L > W && L > T)
		{
			str += "L";
			product *= L;
		}
		str += " ";
	}

	product = (product*0.65 - 1) * 2;

	cout << str;
	printf("%.2f\n", product);

	return 0;
}
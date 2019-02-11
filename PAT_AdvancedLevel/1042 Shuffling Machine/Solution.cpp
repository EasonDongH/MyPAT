#include <iostream>
#include <string>
using namespace std;

int main()
{
	int cards[2][55], repeatTimes, given_order[55], card_Index = 0;
	char t[5] = { 'S', 'H', 'C', 'D', 'J' };
	string mark[55];
	for (int i = 1, tt = 0, index = 1; i <= 54; ++i)
	{
		cards[card_Index][i] = i;
		mark[i] = t[tt] + to_string(index++);
		if (index > 13)
		{
			index = 1;
			++tt;
		}
	}

	scanf("%d", &repeatTimes);
	for (int i = 1; i <= 54; ++i)
	{
		scanf("%d", &given_order[i]);
	}

	while (repeatTimes--)
	{
		card_Index = (card_Index + 1) % 2;
		int tmp_Index = card_Index == 0 ? 1 : 0;
		for (int i = 1; i <= 54; ++i)
		{
			cards[card_Index][given_order[i]] = cards[tmp_Index][i];
		}
	}

	printf("%s", mark[cards[card_Index][1]].c_str());
	for (int i = 2; i <= 54; ++i)
	{
		printf(" %s", mark[cards[card_Index][i]].c_str());
	}
	printf("\n");

	return 0;
}

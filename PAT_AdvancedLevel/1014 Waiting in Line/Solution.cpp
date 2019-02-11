#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAXK 1005

int ProcessTime[MAXK] = { 0 };
int StartTime[MAXK];
int FinishTime[MAXK];

int addTime(int current, int min)
{
	int h1 = current / 100, h2 = min / 60;
	int m1 = current % 100, m2 = min % 60;
	int h = h1 + h2;
	int m = m1 + m2;
	if (60 <= m)
	{
		m %= 60;
		++h;
	}
	return h * 100 + m;
}

int findNextFinish(vector<queue<int>>& winInfo)
{
	int index = -1;
	for (int i = 0, size = winInfo.size(); i < size; ++i)
	{
		if (winInfo[i].size() == 0)
			continue;
		if (index == -1 || FinishTime[winInfo[i].front()] < FinishTime[winInfo[index].front()])
			index = i;
	}
	return index;
}

int main()
{
	int N, M, K, Q;
	scanf("%d%d%d%d", &N, &M, &K, &Q);

	vector<queue<int>> winInfo(N);
	vector<int> winPopTime(N, 800);

	for (int i = 0; i < K; ++i)
	{
		scanf("%d", &ProcessTime[i]);
		StartTime[i] = 99999;
		FinishTime[i] = 99999;
	}

	int currentIndex = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			StartTime[currentIndex] = winPopTime[j];
			FinishTime[currentIndex] = addTime(StartTime[currentIndex], ProcessTime[currentIndex]);

			winInfo[j].push(currentIndex);
			winPopTime[j] = FinishTime[currentIndex];

			++currentIndex;
		}
	}

	while (currentIndex <= K)
	{
		int winIndex = findNextFinish(winInfo);//获取当前哪个窗口有完成
		if (winIndex == -1)
			break;

		StartTime[currentIndex] = winPopTime[winIndex];
		FinishTime[currentIndex] = addTime(StartTime[currentIndex], ProcessTime[currentIndex]);

		winInfo[winIndex].pop();
		winInfo[winIndex].push(currentIndex);
		winPopTime[winIndex] = FinishTime[currentIndex];

		++currentIndex;
	}

	int q;
	for (int i = 0; i < Q; ++i)
	{
		scanf("%d", &q);
		--q;
		if (StartTime[q] < 1700)
		{
			printf("%02d:%02d\n", FinishTime[q] / 100, FinishTime[q] % 100);
		}
		else
		{
			printf("Sorry\n");
		}
	}

	return 0;
}
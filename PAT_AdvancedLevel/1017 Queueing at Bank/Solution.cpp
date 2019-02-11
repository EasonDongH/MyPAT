#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXK 105
#define OpenTime 28800 //08:00:00 in second
#define CloseTime 61200 //17:00:00

int winEndTime[MAXK] = { 0 };

struct Customer
{
	int ArriveTime, Cost;
};

bool operator <(const Customer& c1, const Customer& c2)
{
	return c1.ArriveTime < c2.ArriveTime;
}

int findNextAvailableWin(int k)
{
	int ans = 0;
	for (int i = 1; i < k; ++i)
	{
		if (winEndTime[i] < winEndTime[ans])
			ans = i;
	}
	return ans;
}

int main()
{
	int N, K, waitInSecond = 0;
	int time, hh, mm, ss, cost;

	cin >> N >> K;
	fill(winEndTime, winEndTime + K, OpenTime);
	vector<Customer> customers(N);
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d:%d:%d %d", &hh, &mm, &ss, &cost);
		time = hh * 3600 + mm * 60 + ss;
		customers[i].ArriveTime = time;
		customers[i].Cost = cost*60;
	}

	sort(customers.begin(), customers.end());

	int cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		int availableWin = findNextAvailableWin(K);
		if (customers[i].ArriveTime > CloseTime || winEndTime[availableWin] > CloseTime)
			break;
		++cnt;
		if(customers[i].ArriveTime < winEndTime[availableWin])
		waitInSecond += winEndTime[availableWin] - customers[i].ArriveTime;
		winEndTime[availableWin] += customers[i].Cost;
	}

	printf("%.1f\n", waitInSecond / (double)cnt / 60.0);

	return 0;
}
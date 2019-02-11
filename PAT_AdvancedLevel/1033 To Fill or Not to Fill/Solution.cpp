#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Gas
{
	int ID = 0, Store = 0, Dist = 0;
	double Price = 0.0;
	Gas(int dist, double price) :Dist(dist), Price(price) {}
};

bool cmp1(const Gas& g1, const Gas& g2)
{
	return g1.Dist < g2.Dist;
}

bool cmp2(const Gas& g1, const Gas& g2)
{
	return g1.Price < g2.Price;
}

int main()
{
	int C, Dist, dist, distPerUint, N, maxDistPerC;
	double price;
	vector<Gas> gass, sortedGas;

	cin >> C >> Dist >> distPerUint >> N;
	vector<bool> select(N, false);
	maxDistPerC = C * distPerUint;
	for (int i = 0; i < N; ++i)
	{
		cin >> price >> dist;
		gass.push_back(Gas(dist, price));
	}

	sort(gass.begin(),gass.end(),cmp1);
	for (int i = 0; i < N; ++i)
	{
		gass[i].ID = i;
		sortedGas.push_back(gass[i]);
	}
	sort(sortedGas.begin(), sortedGas.end(), cmp2);

	int currentD = 0, pre, next;
	double money = 0;
	for (int i = 0; i < N && currentD < Dist; ++i)
	{
		pre = sortedGas[i].ID - 1, next = sortedGas[i].ID + 1;
		while (0 < pre && select[pre] == false)
			--pre;
		while (next < N && select[next] == false)
			++next;
		int rest = pre == 0 ? 0 : gass[pre].Store-(sortedGas[i].Dist - gass[pre].Dist);
		int D = next == N ? Dist : gass[next].Dist;//下一个点
		int needRun = min(D - sortedGas[i].Dist, maxDistPerC);//需要跑的距离
		currentD += needRun;//距离前进needRun
		int needOil = needRun - rest;//要加needOil汽油
		money = needOil * sortedGas[i].Price;

		gass[sortedGas[i].ID].Store = needRun;//此时油量需要满足跑到下个点
		select[sortedGas[i].ID] = true;
	}
	if (currentD >= Dist)
		printf("%.2f\n", money / distPerUint);
	else
		printf("The maximum travel distance = %.2f\n", currentD);

	return 0;
}
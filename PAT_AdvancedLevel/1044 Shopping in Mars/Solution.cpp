#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> sum;
vector<pair<int, int>> resultArr;

void func(int i, int& j, int& tmpSum)
{
	int left = i, right = N, mid;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (sum[mid] - sum[i - 1] >= M)
			right = mid;
		else
			left = mid + 1;
	}
	j = right;
	tmpSum = sum[j] - sum[i - 1];
}

int main()
{
	scanf("%d %d", &N, &M);
	sum.resize(N + 1);
	for (int i = 1; i <= N; ++i)
	{
		scanf("%d", &sum[i]);
		sum[i] += sum[i - 1];
	}

	for (int i = 1, j, tmp, minD = sum[N]; i <= N; ++i)
	{
		func(i, j, tmp);
		if (tmp > minD)
			continue;
		if (tmp >= M)
		{
			if (tmp < minD)
			{
				resultArr.clear();
				minD = tmp;
			}
			resultArr.push_back({ i, j });
		}
	}

	for (int i = 0, size = resultArr.size(); i < size; ++i)
		printf("%d-%d\n", resultArr[i].first, resultArr[i].second);

	return 0;
}
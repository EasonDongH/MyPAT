#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int N1, N2, s;
	priority_queue<int, vector<int>, less<int>> pq;

	scanf("%d", &N1);
	for (int i = 0; i < N1; ++i)
	{
		scanf("%d", &s);
		pq.push(s);
	}

	scanf("%d", &N2);
	size_t mid = (N1 + N2 - 1) / 2;
	while (pq.size() > mid)
	{
		pq.pop();
	}
	for (int i = 0; i < N2; ++i)
	{
		scanf("%d", &s);
		if (pq.size() <= mid)
		{
			pq.push(s);
		}
		else
		{
			if (s < pq.top())
			{
				pq.pop();
				pq.push(s);
			}
		}
	}

	printf("%d\n", pq.top());

	return 0;
}
#include <iostream>
#include <stack>
using namespace std;

#define MAXN 505
#define INF 999999999

int G[MAXN][MAXN], C[MAXN][MAXN];
int Path[MAXN], Cost[MAXN], Dist[MAXN], visited[MAXN];

void Dijsktra(int S, int N)
{
	fill(Path, Path + N, -1);

	for (int i = 0; i < N; ++i)
	{
		Dist[i] = G[S][i];
		Cost[i] = C[S][i];
		if (Dist[i] < INF)
			Path[i] = S;
	}

	visited[S] = true;
	Dist[S] = Cost[S] = 0;
	while (true)
	{
		int minV = -1, minD = INF;
		for (int i = 0; i < N; ++i)
		{
			if (visited[i] == false && (minV == -1 || G[S][i] < minD))
			{
				minV = i;
				minD = G[S][i];
			}
		}

		if (minD >= INF)
			break;

		visited[minV] = true;
		for (int W = 0; W < N; ++W)
		{
			if (visited[W] == false && G[minV][W] < INF)
			{
				int tmpDist = Dist[minV] + G[minV][W];
				int tmpCost = Cost[minV] + C[minV][W];
				if (tmpDist < Dist[W])
				{
					Dist[W] = tmpDist;
					Cost[W] = tmpCost;
					Path[W] = minV;
				}
				else if (tmpDist == Dist[W] && tmpCost < Cost[W])
				{
					Cost[W] = tmpCost;
					Path[W] = minV;
				}
			}
		}
	}
}

int main()
{
	int N, M, S, D, c1, c2, dist, cost;
	fill(G[0], G[0] + MAXN * MAXN, INF);
	fill(C[0], C[0] + MAXN * MAXN, INF);

	scanf("%d %d %d %d", &N, &M, &S, &D);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d %d %d", &c1, &c2, &dist, &cost);
		G[c1][c2] = G[c2][c1] = dist;
		C[c1][c2] = C[c2][c1] = cost;
	}

	Dijsktra(S, N);

	stack<int> s;
	int d = D;
	while (Path[d] != -1)
	{
		s.push(d);
		d = Path[d];
	}

	printf("%d", S);
	while (!s.empty())
	{
		printf(" %d", s.top());
		s.pop();
	}
	printf(" %d %d\n", Dist[D], Cost[D]);

	return 0;
}
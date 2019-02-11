#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * ע�⣺����ѡ���·�������ѡ���ȥ���ٵ�·�����ٴ�ѡ��������ٵ�·��
 * Dijkstra�㷨���ܼ������·�������޷�ѡ������������������Ϊ�������������Ҫ��������·��֮����ܼ���
 * �����dijkstra�㷨ʱ�������������·�������ʹ��dfs���������������
 */

#define MAXN 505
#define Inf 999999

int minNeed = Inf, minBack = Inf, c = 0;
int G[MAXN][MAXN];
int Sc[MAXN] = { 0 }, Path[MAXN] = { 0 }, dist[MAXN] = { 0 }, visited[MAXN] = { 0 };
vector<int> pre[MAXN];
vector<int> path, tmpPath;

int findMinDist(int N)
{
	int minV = -1, minDist = Inf;
	for (int i = 0; i <= N; ++i)
	{
		if (visited[i] == 0 && dist[i] < minDist)
		{
			minV = i;
			minDist = dist[i];
		}
	}
	return minV;
}

void Dijkstra(int S, int N)
{
	for (int i = 0; i <= N; ++i)
	{
		dist[i] = G[S][i];
		Path[i] = dist[i] < Inf ? S : -1;
	}

	dist[S] = 0;
	while (true)
	{
		int V = findMinDist(N);
		if (V == -1)
			break;
		visited[V] = 1;
		for (int W = 0; W <= N; ++W)
		{
			if (visited[W] == 0 && G[V][W] < Inf)
			{
				int tmpDist = dist[V] + G[V][W];
				if (tmpDist < dist[W])
				{
					dist[W] = tmpDist;
					Path[W] = V;
					pre[W].clear();
					pre[W].push_back(V);
				}
				else if (tmpDist == dist[W])
				{
					pre[W].push_back(V);//����������·��
					Path[W] = V;
				}
			}
		}
	}
}

void dfs(int v)
{
	tmpPath.push_back(v);
	if (v == 0)//��ȡһ�����������·��
	{
		int need = 0, back = 0;
		for (int i = tmpPath.size() - 2; 0 <= i; --i)//������Ҫ��ȥ�����ص�������ע�����һ���㱣�������ʼ�ڵ㣬���������
		{
			int diff = c - Sc[tmpPath[i]];
			if (diff > 0 && back <= diff)
			{
				need += diff - back;
				back = 0;
			}
			else
			{
				back -= diff;
			}
		}

		if (need < minNeed)
		{
			minNeed = need;
			minBack = back;
			path = tmpPath;
		}
		else if (need == minNeed && back < minBack)
		{
			minBack = back;
			path = tmpPath;
		}
		tmpPath.pop_back();
		return;
	}
	for (int i = 0; i < pre[v].size(); ++i)
	{
		dfs(pre[v][i]);//���֧����
	}
	tmpPath.pop_back();//����
}

int main()
{
	int C, N, Sp, M, v1, v2, t;
	cin >> C >> N >> Sp >> M;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Sc[i];
	}

	fill(G[0], G[0] + MAXN * MAXN, Inf);

	for (int i = 0; i < M; ++i)
	{
		cin >> v1 >> v2 >> t;
		G[v1][v2] = G[v2][v1] = t;
	}

	Dijkstra(0, N);
	c = C / 2;
	dfs(Sp);

	printf("%d 0", minNeed);
	for (int i = path.size() - 2; 0 <= i; --i)
	{
		printf("->%d", path[i]);
	}
	printf(" %d\n", minBack);

	return 0;
}
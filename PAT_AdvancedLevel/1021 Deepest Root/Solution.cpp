#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

/*
 * 思路：先dfs求连通分量，同时保存下从该点出发的最远的叶节点
 * 在求第一次从A点出发求连通分量的时候，任意保存下一个从A出发的最远叶节点B，并同时保存下所有叶节点
 * 在连通分量等于1时，从B点出发，再求一次连通分量，同样保存下所有最远节点
 * 注意：在保存最远节点时，要注意去重，因此从不同节点出发，可能会拥有同一个最远节点
 * 去重之后的序列，即所求序列
 */

#define MAXN 10010

map<int, vector<int>> G;
int Visited[MAXN] = { 0 };
int maxDeep = 0;
vector<int> deepRoot;

void dfs(int v, int deep)
{
	Visited[v] = 1;
	if (deep > maxDeep)
	{
		maxDeep = deep;
		deepRoot.clear();
		deepRoot.push_back(v);
	}
	else if (deep == maxDeep)
	{
		deepRoot.push_back(v);
	}

	auto vec = G[v];
	for (auto t : vec)
	{
		if (Visited[t] == 0)
			dfs(t, deep + 1);
	}
}

int main()
{
	int N, v1, v2;

	cin >> N;
	for (int i = 1; i < N; ++i)
	{
		scanf("%d %d", &v1, &v2);
		G[v1].push_back(v2);
		G[v2].push_back(v1);
	}

	int cnt = 0, oneLeaf = -1;
	set<int> s_i;
	for (int i = 1; i <= N; ++i)
	{
		if (Visited[i] == 0)
		{
			++cnt;
			dfs(i, 0);
			if (i == 1)
			{
				for (auto root : deepRoot)
				{
					if (oneLeaf == -1)
						oneLeaf = root;
					s_i.insert(root);
				}
			}
		}
	}

	if (1 < cnt)
	{
		printf("Error: %d components\n", cnt);
	}
	else
	{
		fill(Visited, Visited + MAXN, 0);

		deepRoot.clear();
		dfs(oneLeaf, 0);

		for (auto root : deepRoot)
		{
			s_i.insert(root);
		}

		for (auto it = s_i.cbegin(); it != s_i.cend(); ++it)
			printf("%d\n", *it);
	}

	return 0;
}
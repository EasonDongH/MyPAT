#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> gang;
map<string, vector<string>> G;
map<string, bool> visited;

void dfs(string V)
{
	gang.push_back(V);
	visited[V] = true;
	auto vec = G[V];
	for (auto v : vec)
		if (visited[v] == false)
			dfs(v);
}

int main()
{
	int N, K, time;
	string n1, n2;
	n1.resize(5); n2.resize(5);
	map<string, int> m;

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		scanf(" %s %s %d", &n1[0], &n2[0], &time);
		m[n1] += time;
		m[n2] += time;
		G[n1].push_back(n2);
		visited[n1] = false;
		visited[n2] = false;
	}

	vector<vector<string>> gangs;
	for (auto v : G)
	{
		if (visited[v.first] == false)
		{
			gang.clear();
			dfs(v.first);
			if (gang.size() > 2)
			{
				gangs.push_back(gang);
			}
		}
	}

	map<string, int> ans;
	for (auto g : gangs)
	{
		int gangSize = g.size();
		int head = 0, threthold = m[g[0]];
		for (int j = 1; j < gangSize; ++j)
		{
			threthold += m[g[j]];
			if (m[g[j]] > m[g[head]])
				head = j;
		}
		if (threthold > 2 * K)
			ans[g[head]] = gangSize;
	}

	int size = ans.size();
	printf("%d\n", size);
	for (auto a : ans)
	{
		printf("%s %d\n", a.first.c_str(), a.second);
	}

	return 0;
}
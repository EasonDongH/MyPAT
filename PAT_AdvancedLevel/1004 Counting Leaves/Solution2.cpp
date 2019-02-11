#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> v[100];
int NoChild[100] = { 0 };
int maxDepth = -1;

void dfs(int index, int depth) {
	if (v[index].size() == 0) {
		NoChild[depth]++;
		maxDepth = max(maxDepth, depth);
	}
	else {
		for (int i = 0; i < v[index].size(); ++i) {
			dfs(v[index][i], depth + 1);
		}
	}
}

void bfs() {
	int  depth[100] = { 0 };
	queue<int> q_i;
	q_i.push(1);
	depth[1] = 0;
	while (!q_i.empty()) {
		int index = q_i.front();
		q_i.pop();
		maxDepth = max(maxDepth, depth[index]);
		if (v[index].size() == 0)
			NoChild[depth[index]]++;
		for (int i = 0; i<int(v[index].size()); ++i) {
			q_i.push(v[index][i]);
			depth[v[index][i]] = depth[index] + 1;
		}
	}
}

int main(){
	int N, M, K, node,child;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> node >> K;
		for (int j = 0; j < K; ++j) {
			cin >> child;
			v[node].push_back(child);
		}
	}

	//dfs(1,0);
	bfs();

	cout << NoChild[0];
	for (int i = 1; i <=maxDepth; ++i)
		cout << " " << NoChild[i];
	cout << endl;

	return 0;
}
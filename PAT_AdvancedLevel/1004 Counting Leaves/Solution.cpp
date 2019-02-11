//#include <bits/stdc++.h>
//using namespace std;
//
////测试点1、3过不去，可能是该算法对输入的先后顺序敏感，而测试点1、3是乱序输入的
//int main() {
//	int N, M, K, Id, child, p;
//	vector<int> parent(105, -1);
//	map<int, pair<int, int>> m_ip;
//	parent[1] = 0;
//	m_ip[1] = make_pair(1, 0);
//
//	cin >> N >> M;
//	for (int i = 0; i < M; ++i) {
//		cin >> Id >> K;
//		p = parent[Id];
//		auto id = m_ip.find(p + 1);
//		++id->second.second;
//		auto level = m_ip.find(p + 2);
//		if (level == m_ip.end())
//			m_ip[p + 2] = make_pair(K, 0);
//		else
//			level->second.first += K;
//		for (int j = 0; j < K; ++j) {
//			cin >> child;
//			parent[child] = p + 1;
//		}
//	}
//
//	bool flag = false;
//	for (auto it = m_ip.cbegin(); it != m_ip.cend(); ++it) {
//		if (flag)
//			cout << " ";
//		else
//			flag = true;
//
//		cout << (it->second.first - it->second.second);
//	}
//	cout << endl;
//
//	return 0;
//}
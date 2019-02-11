#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

struct Grade
{
	int BestRank;
	char RankName;
	int ID, G[4];
	Grade(int id, int c, int m, int e) :ID(id)
	{
		G[1] = c; G[2] = m; G[3] = e;
		G[0] = (G[1] + G[2] + G[3]) / 3;
		BestRank = 100000000;
		RankName = '*';
	}
};

bool cmp(int gIndex, const Grade& g1, const Grade& g2)
{
	if (g1.G[gIndex] != g2.G[gIndex])
		return g1.G[gIndex] > g2.G[gIndex];
	return g1.ID < g2.ID;
}

void updateRank(int gIndex, vector<Grade>& grades, char rankName)
{
	sort(grades.begin(), grades.end(), bind(cmp, gIndex, placeholders::_1, placeholders::_2));
	for (int i = 0, rank = 0, size = grades.size(); i < size; ++i)
	{
		if (0 < i && grades[i - 1].G[gIndex] != grades[i].G[gIndex])
		{
			rank = i;
		}

		if (rank < grades[i].BestRank)
		{
			grades[i].BestRank = rank;
			grades[i].RankName = rankName;
		}
	}
}

int main()
{
	int N, M, id, c, m, e;
	cin >> N >> M;

	vector<Grade> grades;
	for (int i = 0; i < N; ++i)
	{
		cin >> id >> c >> m >> e;
		grades.push_back(Grade(id, c, m, e));
	}

	//A > C > M > E
	updateRank(0, grades, 'A');
	updateRank(1, grades, 'C');
	updateRank(2, grades, 'M');
	updateRank(3, grades, 'E');

	unordered_map<int, int> um_ii;
	for (int i = 0, size = grades.size(); i < size; ++i)
	{
		um_ii[grades[i].ID] = i;
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> id;
		if (um_ii.count(id) == 0)
		{
			cout << "N/A\n";
		}
		else
		{
			int index = um_ii[id];
			cout << grades[index].BestRank + 1 << " " << grades[index].RankName << endl;
		}
	}

	return 0;
}
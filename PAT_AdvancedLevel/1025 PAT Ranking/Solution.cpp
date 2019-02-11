#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Testee
{
	string ID;
	int Score;
	int Location;
	int Rank[2];
	Testee() {}
	Testee(int location)
	{
		ID = Score = 0;
		Location = location;
		Rank[0] = Rank[1] = 0;
	}
};

bool operator <(const Testee& t1, const Testee& t2)
{
	if (t1.Score != t2.Score)
		return t1.Score > t2.Score;
	return t1.ID < t2.ID;
}

ostream& operator <<(ostream& out, const Testee& t)
{
	out << t.ID << " " << t.Rank[1] << " " << t.Location << " " << t.Rank[0] << endl;
	return out;
}

void Rank(int index, int L, int R, vector<Testee>& testees)
{
	sort(testees.begin() + L, testees.begin() + R);
	testees[L].Rank[index] = 1;
	for (int i = L + 1; i < R; ++i)
	{
		if (testees[i - 1].Score == testees[i].Score)
			testees[i].Rank[index] = testees[i - 1].Rank[index];
		else
			testees[i].Rank[index] = i + 1 - L;
	}
}

int main()
{
	int N, K, total = 0;
	vector<Testee> allTestees;

	cin >> N;
	for (int n = 0; n < N; ++n)
	{
		cin >> K;
		total += K;
		Testee tmp(n + 1);
		for (int i = 0; i < K; ++i)
		{
			cin >> tmp.ID >> tmp.Score;
			allTestees.push_back(tmp);
		}
		Rank(0, total - K, total, allTestees);
	}
	Rank(1, 0, total, allTestees);

	cout << total << endl;
	for (int i = 0, size = allTestees.size(); i < size; ++i)
	{
		cout << allTestees[i];
	}

	return 0;
}
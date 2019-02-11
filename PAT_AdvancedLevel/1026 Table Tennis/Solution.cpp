#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXK 105

int OpenTime = 28800; //08:00:00
int CloseTime = 75600; //21:00:00
int Table[MAXK];
int IsVIP[MAXK], TableCnt[MAXK] = { 0 };

struct Player
{
	int ArriveTime, WaitTime, ServeTime, PlayTime;
	bool operator <(const Player& p) const
	{
		return ArriveTime < p.ArriveTime;
	}
};

vector<Player> players, VIP;

int findNextTable(int N)
{
	int index = -1;
	for (int i = 1; i <= N; ++i)
	{
		if (Table[i] < CloseTime)
		{
			if (index == -1 || Table[i] < Table[index])
				index = i;
		}
	}
	return index;
}

int main()
{
	int N, hh, mm, ss, PlayTime, isVIP, K, M;
	Player player;
	fill(Table, Table + MAXK, OpenTime);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		scanf_s("%d:%d:%d %d %d", &hh, &mm, &ss, &PlayTime, &isVIP);
		player.ArriveTime = hh * 3600 + mm * 60 + ss;
		if (player.ArriveTime > CloseTime)
			continue;
		PlayTime *= 60;
		player.PlayTime = 7200 < PlayTime ? 7200 : PlayTime;
		if (isVIP)
			VIP.push_back(player);
		else
			players.push_back(player);
	}

	cin >> K >> M;
	for (int i = 0, tmp; i < M; ++i)
	{
		cin >> tmp;
		IsVIP[tmp] = 1;
	}

	sort(players.begin(), players.end());
	sort(VIP.begin(), VIP.end());

	int index, i = 0, j = 0, iSize = players.size(), jSize = VIP.size();
	while (i < iSize || j < jSize)
	{
		index = findNextTable(K);
		if (index == -1)
			break;
		++TableCnt[index];

		isVIP = 0;
		if (i<iSize &&(j >= jSize || players[i].ArriveTime < VIP[j].ArriveTime))
		{
			isVIP = 0;
		}
		else
		{
			isVIP = 1;
		}
        
		if (isVIP==0 && j<jSize && IsVIP[index] && VIP[j].ArriveTime <= Table[index])
		{
			isVIP = 1;
		}
		if (isVIP == 1)
		{
			Table[index] = max(Table[index], VIP[j].ArriveTime);
			VIP[j].ServeTime = Table[index];
			VIP[j].WaitTime = VIP[j].ServeTime - VIP[j].ArriveTime;
			Table[index] += VIP[j].PlayTime;
			++j;
		}
		else 
		{
			Table[index] = max(Table[index], players[i].ArriveTime);
			players[i].ServeTime = Table[index];
			players[i].WaitTime = players[i].ServeTime - players[i].ArriveTime;
			Table[index] += players[i].PlayTime;
			++i;
		}
	}

	Player p;
	for (int k1 = 0, k2 = 0; k1 < i || k2 < j; )
	{
		if (k1<i && ( k2>=j || players[k1].ServeTime < VIP[k2].ServeTime))
		{
			p = players[k1];
			++k1;
		}
		else
		{
			p = VIP[k2];
			++k2;
		}

		int time = p.ArriveTime;
		int h1 = time / 3600, m1 = (time % 3600) / 60, s1 = (time % 3600) % 60;
		time = p.ServeTime;
		int h2 = time / 3600, m2 = (time % 3600) / 60, s2 = (time % 3600) % 60;
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", h1, m1, s1, h2, m2, s2, (int)ceil(p.WaitTime / 60.0));
	}

	cout << TableCnt[1];
	for (int i = 2; i <= K; ++i)
		cout << " " << TableCnt[i];
	cout << endl;

	return 0;
}
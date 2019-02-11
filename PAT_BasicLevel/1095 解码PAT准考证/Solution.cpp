#include <bits/stdc++.h>
using namespace std;

struct Info {
	string Id;
	int Score, Room, Date;
	Info(string id, int score) :Id(id), Score(score) {
		Room = Date = 0;
		for (int i = 0; i < 3; ++i)
			Room = Room * 10 + (Id[i + 1] - '0');
		for (int i = 0; i < 6; ++i)
			Date = Date * 10 + (Id[i + 4] - '0');
	}
	bool operator < (const Info& info) {
		if (this->Score != info.Score)
			return info.Score< this->Score;
		return this->Id< info.Id;
	}
};

struct CntInfo {
	int Room, PeopleCnt;
	CntInfo(int room, int cnt) :Room(room), PeopleCnt(cnt) {}
	bool operator < (const CntInfo& info) {
		if(info.PeopleCnt != this->PeopleCnt)
		  return info.PeopleCnt< this->PeopleCnt;
		return this->Room < info.Room;
	}
};

void func1(vector<Info>& stus, char level) {
	vector<Info> tmp;
	for (int i = 0, size = stus.size(); i < size; ++i) {
		if (stus[i].Id[0] == level) {
			tmp.push_back(stus[i]);
		}
	}

	if (tmp.size() == 0)
		cout << "NA\n";
	else {
		sort(tmp.begin(), tmp.end());
		for (auto stu : tmp)
			cout << stu.Id << " " << stu.Score << '\n';
	}
}

void func2(vector<Info>& stus, int room) {
	int cnt = 0, scoreCnt = 0;
	for (auto stu : stus)
		if (stu.Room == room) {
			++cnt;
			scoreCnt += stu.Score;
		}

	if (cnt == 0)
		cout << "NA\n";
	else
		cout << cnt << " " << scoreCnt << '\n';
}

void func3(vector<Info>& stus, int date) {
	map<int, int> m_ii;
	vector<CntInfo> tmp;
	for (auto stu : stus)
		if (stu.Date == date)
			++m_ii[stu.Room];
	for (auto it = m_ii.begin(); it != m_ii.end(); ++it)
		tmp.push_back(CntInfo(it->first, it->second));
	if (tmp.size() == 0)
		cout << "NA\n";
	else {
		sort(tmp.begin(), tmp.end());
		for (auto t : tmp)
			printf("%03d %d\n", t.Room, t.PeopleCnt);
	}
}

int main() {
	int N, M, cmd, score;
	string id;
	cin >> N >> M;
	cin.get();
	vector<Info> stus;
	for (int i = 0; i < N; ++i) {
		cin >> id >> score;
		cin.get();
		stus.push_back(Info(id, score));
	}

	char level;
	int room, date;
	for (int i = 0; i < M; ++i) {
		cin >> cmd;
		switch (cmd) {
		case 1:
			cin.get();//' '
			level = cin.get();
			cin.get();//'\n'
			cout << "Case "  << i+1 << ": 1 "<< level << '\n';
			func1(stus, level);
			break;
		case 2:
			cin >> room;
			cin.get();
			printf("Case %d: 2 %03d\n", i + 1, room);
			//cout << "Case " << i + 1 << ": 2 " << room << '\n';
			func2(stus, room);
			break;
		case 3:
			cin >> date;
			cin.get();
			printf("Case %d: 3 %06d\n", i + 1, date);
			//cout << "Case " << i + 1 << ": 3 "<< date << '\n';
			func3(stus, date);
			break;
		}
	}

	return 0;
}
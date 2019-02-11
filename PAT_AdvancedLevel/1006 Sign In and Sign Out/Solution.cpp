#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Time {
	int H, M, S;
};

istream& operator >> (istream& cin, Time& t) {
	cin >> t.H; cin.get();
	cin >> t.M; cin.get();
	cin >> t.S;
	return cin;
}

struct Record {
	string ID;
	Time SignIn, SignOut;
	Record() {}
};

istream& operator >> (istream& cin, Record& r) {
	cin >> r.ID;
	cin >> r.SignIn >> r.SignOut;
	return cin;
}

bool operator <(const Time& t1, const Time& t2) {
	if (t1.H != t2.H)
		return t1.H < t2.H;
	if (t1.M != t2.M)
		return t1.M < t2.M;
	return t1.S < t2.S;
}

bool cmpBySignIn(const Record& r1, const Record& r2) {
	return r1.SignIn < r2.SignIn;
}

bool cmpBySignOut(const Record& r1, const Record& r2) {
	return r1.SignOut < r2.SignOut;
}

int main() {
	int N;
	string id;

	cin >> N;
	cin.get();
	vector<Record> record;

	while (N--) {
		Record r;
		cin >> r;
		cin.get();
		record.push_back(r);
	}

	sort(record.begin(), record.end(), cmpBySignIn);
	cout << record[0].ID;
	sort(record.begin(), record.end(), cmpBySignOut);
	cout << " " << record[record.size() - 1].ID << endl;

	return 0;
}
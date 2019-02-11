#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct BookInfo
{
	string ID, Title, Author, KeyWords, Publisher, PublishYear;
};

bool operator < (const BookInfo& b1, const BookInfo& b2)
{
	return b1.ID < b2.ID;
}

vector<string> split(const string& str, char ch)
{
	size_t pre = 0;
	vector<string> ans;
	while (true)
	{
		size_t found = str.find(ch, pre);
		if (found == string::npos)
			break;
		string word = str.substr(pre, found - pre);
		if(word.size() > 0)
		ans.push_back(word);
		pre = found + 1;
	}
	string word = str.substr(pre, str.size() - pre);
	if (word.size() > 0)
		ans.push_back(word);
	return ans;
}

int main()
{
	int N;
	string ID, Title, Author, KeyWords, Publisher, PublishYear;
	vector<BookInfo> books;
	map<string, vector<int>> m[5];

	cin >> N; cin.get();
	for (int i = 0; i < N; ++i)
	{
		getline(cin, ID);
		getline(cin, Title);
		getline(cin, Author);
		getline(cin, KeyWords);
		getline(cin, Publisher);
		getline(cin, PublishYear);

		books.push_back({ ID, Title, Author, KeyWords, Publisher, PublishYear });
	}

	sort(books.begin(), books.end());

	for (int i = 0; i < N; ++i)
	{
		m[0][books[i].Title].push_back(i);
		m[1][books[i].Author].push_back(i);
		auto keywords = split(books[i].KeyWords, ' ');
		for(auto k : keywords)
		  m[2][k].push_back(i);
		m[3][books[i].Publisher].push_back(i);
		m[4][books[i].PublishYear].push_back(i);
	}

	int M, op;
	string query;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> op;
		cin.get(); cin.get();//: space
		getline(cin, query);
		cout << op << ": " << query << endl;

		auto& tmp = m[op - 1];
		if (tmp.count(query) == 0)
			printf("Not Found\n");
		else
		{
			auto& vec = tmp[query];
			for (auto v : vec)
				cout << books[v].ID << endl;
		}
	}

	return 0;
}
#include <iostream>
#include <unordered_map>
#include <set>
#include <string>
using namespace std;

int main()
{
	int n, N, K, courseId;
	string name;
	name.resize(10);
	unordered_map<string, set<int>> umss;

	cin >> N >> K;
	for (int i = 0; i < K; ++i)
	{
		cin >> courseId >> n;
		cin.get();
		for (int j = 0; j < n; ++j)
		{
			scanf("%s", &name[0]);
			umss[name].insert(courseId);
		}
	}

	cin.get();
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", &name[0]);
		auto& s = umss[name];
		printf("%s %d", name.c_str(), s.size());
		for (auto it = s.cbegin(); it != s.cend(); ++it)
			cout << " " << *it;
		cout << endl;
	}

	return 0;
}
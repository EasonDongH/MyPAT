#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool cmp(const string& s1, const string& s2)
{
	int longSize = s1.size(), shortSize = s2.size();
	bool hasSwap = false;
	string longer = s1, shorter = s2;
	if (longSize < shortSize)
	{
		hasSwap = true;
		swap(longSize, shortSize);
		swap(longer, shorter);
	}
	for (int i = 0, j = 0; i < longSize; ++i)
	{
		if (longer[i] != shorter[j])
		{
			bool tmp = longer[i] < shorter[j];
			return hasSwap ? !tmp : tmp;
		}
		j = (j + 1) % shortSize;
	}
	return true;
}

int main()
{
	int N;
	vector<string> segments;

	scanf("%d", &N);
	segments.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> segments[i];

	sort(segments.begin(), segments.end(), cmp);

	string ans;
	ans = accumulate(segments.begin(), segments.end(), ans);

	int i = 0, size = ans.size();
	for (; i < size&&ans[i] == '0'; ++i);
	if (i == size)
		printf("0\n");
	else
		printf("%s\n", ans.c_str() + i);

	return 0;
}
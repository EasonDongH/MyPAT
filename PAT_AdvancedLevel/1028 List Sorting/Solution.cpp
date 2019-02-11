#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Student
{
	string ID, Name;
	int Grade;
};

bool cmp1(const Student& s1, const Student& s2)
{
	return s1.ID < s2.ID;
}

bool cmp2(const Student& s1, const Student& s2)
{
	if (s1.Name != s2.Name)
		return s1.Name < s2.Name;
	return s1.ID < s2.ID;
}

bool cmp3(const Student& s1, const Student& s2)
{
	if (s1.Grade != s2.Grade)
		return s1.Grade < s2.Grade;
	return s1.ID < s2.ID;
}

int main()
{
	int N, C, grade;
	string id, name;
	id.resize(10); name.resize(15);
	bool(*cmp[])(const Student&, const Student&) = { cmp1,cmp2,cmp3 };

	cin >> N >> C;
	cin.get();

	vector<Student> stus;
	while (N--)
	{
		scanf(" %s %s %d", &id[0], &name[0], &grade);
		//cin >> id >> name >> grade;
		//cin.get();
		stus.push_back({ id, name, grade });
	}

	sort(stus.begin(), stus.end(), cmp[C - 1]);

	for (int i = 0, size = stus.size(); i < size; ++i)
	{
		printf("%s %s %d\n", stus[i].ID.c_str(), stus[i].Name.c_str(), stus[i].Grade);
	}

	return 0;
}
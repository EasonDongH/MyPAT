#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct User
{
	string Name, Password;
};

int main()
{
	int N;
	int mask[128] = { 0 };
	bool flag;
	string name, password;
	name.resize(15); password.resize(15);
	vector<User> ans;

	mask[1 + '0'] = '@';
	mask[0 + '0'] = '%';
	mask['l'] = 'L';
	mask['O'] = 'o';

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		//scanf(" %s %s", &name[0], &password[0]);
		flag = false;
		for (int j = 0, size = strlen(password.c_str());j < size; ++j)
		{
			if (mask[password[j]] != 0)
			{
				flag = true;
				password[j] = mask[password[j]];
			}
		}
		if (flag)
			ans.push_back({ name,password });
	}

	int size = ans.size();
	if (size == 0)
	{
		if (N <= 1)
			printf("There are %d account and no account is modified\n", N);
		else
			printf("There are %d accounts and no account is modified\n", N);
	}
	else
	{
		printf("%d\n", size);
		for (auto a : ans)
			printf("%s %s\n", a.Name.c_str(), a.Password.c_str());
	}

	return 0;
}
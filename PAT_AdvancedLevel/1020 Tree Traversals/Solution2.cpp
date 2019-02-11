#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
	int index, val;
};

bool operator <(const Node& n1, const Node& n2)
{
	return n1.index < n2.index;
}

vector<int> post, in;
vector<Node> level;

void pre(int root, int L, int R, int index)
{
	if (L > R)
		return;
	int i;
	for (i = L; i < R && post[root] != in[i]; ++i);
	level.push_back({ index,post[root]});
	int LNum = R - i;
	pre(root-LNum-1,L,i-1,2*index+1);
	pre(root - 1, i + 1, R, 2 * index + 2);
}

int main()
{
	int N;
	cin >> N;
	post.resize(N); in.resize(N);
	for (int i = 0; i < N; ++i)
		cin >> post[i];
	for (int i = 0; i < N; ++i)
		cin >> in[i];

	pre(N-1,0,N-1,0);
	sort(level.begin(), level.end());

	cout << level[0].val;
	for (int i = 1; i < N; ++i)
		cout << " "<<level[i].val;
	cout << endl;

	return 0;
}
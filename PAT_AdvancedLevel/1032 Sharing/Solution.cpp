#include <iostream>
using namespace std;

struct Node
{
	int Address = 0, Next = -1, Cnt = 0;
	char Letter;
};

typedef Node List[100000];
List list;
#define Null -1

int findCommonNode(int n1, int n2)
{
	if (n1 == n2)
		return n1;

	int n = n1;
	while (n != Null)
	{
		list[n].Cnt = 1;
		n = list[n].Next;
	}

	n = n2;
	while (n != Null)
	{
		if (list[n].Cnt == 1)
			return n;
		n = list[n].Next;
	}
	return Null;
}

int main()
{
	int address, next, n1, n2, N;
	char letter;

	cin >> n1 >> n2 >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> address >> letter >> next;
		list[address].Letter = letter;
		list[address].Next = next;
	}

	int n = findCommonNode(n1, n2);
	if (n == Null)
		printf("-1\n");
	else
		printf("%05d\n", n);

	return 0;
}
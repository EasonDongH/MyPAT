//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//
//vector<int> post, in, level;
//
//struct TreeNode
//{
//	int val;
//	TreeNode* left, *right;
//	TreeNode(int V, TreeNode* L = nullptr, TreeNode* R = nullptr) :val(V), left(L), right(R) {}
//};
//
//TreeNode* buildTreeByPostAndIn(int postL, int postR, int inL, int inR)
//{
//	if (postR < postL)
//		return nullptr;
//	TreeNode* node = new TreeNode(post[postR]);
//	int i;
//	for (i = inL; i <= inR; ++i)
//	{
//		if (in[i] == post[postR])
//			break;
//	}
//	int L = i - inL;
//	node->left = buildTreeByPostAndIn(postL, postL + L - 1, inL, i - 1);
//	node->right = buildTreeByPostAndIn(postL + L, postR - 1, i + 1, inR);
//	return node;
//}
//
//void levelOrder(TreeNode* root)
//{
//	queue<TreeNode*> q_TN;
//
//	q_TN.push(root);
//	while (!q_TN.empty())
//	{
//		root = q_TN.front(); q_TN.pop();
//		if (root != nullptr)
//		{
//			level.push_back(root->val);
//			q_TN.push(root->left);
//			q_TN.push(root->right);
//		}
//	}
//}
//
//int main()
//{
//	int N, val;
//	cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> val;
//		post.push_back(val);
//	}
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> val;
//		in.push_back(val);
//	}
//
//	TreeNode* root = buildTreeByPostAndIn(0, N - 1, 0, N - 1);
//	levelOrder(root);
//
//	cout << level[0];
//	for (int i = 1, size = level.size(); i < size; ++i)
//	{
//		cout << " " << level[i];
//	}
//	cout << endl;
//
//	return 0;
//}
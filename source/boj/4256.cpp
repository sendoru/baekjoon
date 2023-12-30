#include <iostream>
#include <vector>

using namespace std;
vector<int> ans;

void getPostOrder(vector<int>& pre, vector<int>& in, int preS, int preE, int inS, int inE)
{
	int inRoot;
	if (preS <= preE)
	{
		ans.push_back(pre[preS]);
		for (int i = 0; i < in.size(); i++)
		{
			if (in[i] == pre[preS])
			{
				inRoot = i;
				break;
			}
		}
		getPostOrder(pre, in, preS + (inRoot - inS) + 1, preE, inRoot + 1, inE);
		getPostOrder(pre, in, preS + 1, preS + (inRoot - inS), inS, inRoot - 1);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> preorder(n), inorder(n);
		for (int i = 0; i < n; i++)
		{
			cin >> preorder[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> inorder[i];
		}

		getPostOrder(preorder, inorder, 0, n - 1, 0, n - 1);
		while (!ans.empty())
		{
			cout << ans.back() << ' ';
			ans.pop_back();
		}
		cout << '\n';
	}
	return 0;
}
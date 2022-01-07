#include <iostream>
#include <vector>

using namespace std;

void printPreorder(vector<int>& in, vector<int>& post, int inS, int inE, int postS, int postE)
{
	int inRoot;
	if (postS <= postE)
	{
		cout << post[postE] << ' ';
		for (int i = 0; i < in.size(); i++)
		{
			if (in[i] == post[postE])
			{
				inRoot = i;
				break;
			}
		}
		printPreorder(in, post, inS, inRoot - 1, postS, postS + inRoot - inS - 1);
		printPreorder(in, post, inRoot + 1, inE, postS + inRoot - inS, postE - 1);
	}
}

int main(void)
{
	int n;
	cin >> n;
	vector<int> inorder(n);
	for (int i = 0; i < n; i++)
	{
		cin >> inorder[i];
	}
	vector<int> postorder(n);
	for (int i = 0; i < n; i++)
	{
		cin >> postorder[i];
	}

	printPreorder(inorder, postorder, 0, n - 1, 0, n - 1);
	return 0;
}
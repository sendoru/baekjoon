#include <iostream>
#include <string>

using namespace std;

void myAdd(int& S, int x)
{
	if ((S >> x) % 2 == 0)
		S += (1 << x);
}

void myRemove(int& S, int x)
{
	if ((S >> x) % 2 == 1)
		S -= (1 << x);
}

void myCheck(int& S, int x)
{
	cout << (S >> x) % 2 << '\n';
}

void myToggle(int& S, int x)
{
	if ((S >> x) % 2 == 0)
		S += (1 << x);
	else
		S -= (1 << x);
}

void myAll(int& S)
{
	S = (1 << 22) - 1;
}

void myEmpty(int& S)
{
	S = 0;
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int S = 0;
	int M;
	int x;
	string myInput;
	cin >> M;

	for (int i = 0; i <= M; i++)
	{
		getline(cin, myInput);
		if (myInput[0] == 'a' && myInput[1] == 'd')
		{
			x = stoi(myInput.substr(4, myInput.size() - 4));
			myAdd(S, x);
		}
		else if (myInput[0] == 'r')
		{
			x = stoi(myInput.substr(7, myInput.size() - 7));
			myRemove(S, x);
		}
		else if (myInput[0] == 'c')
		{
			x = stoi(myInput.substr(6, myInput.size() - 6));
			myCheck(S, x);
		}
		else if (myInput[0] == 't')
		{
			x = stoi(myInput.substr(7, myInput.size() - 7));
			myToggle(S, x);
		}
		else if (myInput[0] == 'a' && myInput[1] == 'l')
		{
			myAll(S);
		}
		else if (myInput[0] == 'e')
		{
			myEmpty(S);
		}
	}
	return 0;
}
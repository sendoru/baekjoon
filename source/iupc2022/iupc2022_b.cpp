#include<iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const int N = 20;

int main(void)
{
	double totalCredit = 0, totalGrade = 0;
	map<string, double> convertGrade =
	{
		{"A+", 4.5},
		{"A0", 4.0},
		{"B+", 3.5},
		{"B0", 3.0},
		{"C+", 2.5},
		{"C0", 2.0},
		{"D+", 1.5},
		{"D0", 1.0},
		{"F", 0.0}
	};

	for (int i = 0; i < N; i++)
	{
		string s, curGrade;
		double curCredit;
		cin >> s >> curCredit >> curGrade;
		if (curGrade != "P")
		{
			totalCredit += curCredit;
			totalGrade += curCredit * convertGrade[curGrade];
		}
	}

	cout.precision(10);
	cout << totalGrade / totalCredit;
}
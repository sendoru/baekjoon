#include <iostream>
#include <algorithm>

using namespace std;

int countOf2[501] = { 0, };
int countOf5[501] = { 0, };
int sumOf2 = 0;
int sumOf5 = 0;

int main()
{
	for (int i = 2; i < 501; i += 2) countOf2[i] += 1;
	for (int i = 4; i < 501; i += 4) countOf2[i] += 1;
	for (int i = 8; i < 501; i += 8) countOf2[i] += 1;
	for (int i = 16; i < 501; i += 16) countOf2[i] += 1;
	for (int i = 32; i < 501; i += 32) countOf2[i] += 1;
	for (int i = 64; i < 501; i += 64) countOf2[i] += 1;
	for (int i = 128; i < 501; i += 128) countOf2[i] += 1;
	for (int i = 256; i < 501; i += 256) countOf2[i] += 1;

	for (int i = 5; i < 501; i += 5) countOf5[i] += 1;
	for (int i = 25; i < 501; i += 25) countOf5[i] += 1;
	for (int i = 125; i < 501; i += 125) countOf5[i] += 1;

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		sumOf2 += countOf2[i];
		sumOf5 += countOf5[i];
	}

	cout << min(sumOf2, sumOf5) << '\n';

	return 0;
}
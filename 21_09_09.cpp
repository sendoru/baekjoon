#include <iostream>
using namespace std;

int main(void)
{
	int a[20];
	int* p = &(a[5]);
	for (int i = 0; i < 20; i++)
		a[i] = i;
	cout << p + 5 << endl; //address of a[10]
	cout << *(p + 5) << endl; //10
	cout << *(p++) << endl; //5
	cout << *(--p) << endl; //5
	int* q = &(a[10]);
	cout << *(p + (q - p) / 2) << endl; //7
	return 0;
}
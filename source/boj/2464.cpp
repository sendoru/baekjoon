#include <iostream>
#include <vector>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main(void)
{
    ull n;
    cin >> n;
    int zeroToOne = -1, oneToZero = -1;
    for (ull i = 63; i >= 1; i--)
    {
        if ((n & (1ull << i)) && !(n & (1ull << (i - 1))))
        {
            oneToZero = i;
        }
        else if (!(n & (1ull << i)) && (n & (1ull << (i - 1))))
        {
            zeroToOne = i;
        }
    }

    ull a = n;
    if (oneToZero == -1)
    {
        a = 0ull;
    }
    else
    {
        a += 1ull << (oneToZero - 1);
        a -= 1ull << oneToZero;
        ll oneCnt = 0;
        for (int i = oneToZero - 2; i >= 0; i--)
        {
            if (a & (1ull << i))
            {
                a -= 1ull << i;
                oneCnt++;
            }
        }
        for (int i = oneToZero - 2; oneCnt != 0; i--)
        {
            a += 1ull << i;
            oneCnt--;
        }
    }

    ull b = n;
    if (zeroToOne == -1)
    {
        b = 0ull;
    }
    else
    {
        b -= 1ull << (zeroToOne - 1);
        b += 1ull << zeroToOne;
        ll oneCnt = 0;
        for (int i = zeroToOne - 2; i >= 0; i--)
        {
            if (b & (1ull << i))
            {
                b -= 1ull << i;
                oneCnt++;
            }
        }
        for (int i = 0; i < oneCnt; i++)
        {
            b += 1ull << i;
        }
    }

    cout << a << ' ' << b;


    return 0;
}
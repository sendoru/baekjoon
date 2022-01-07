#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int ll;

class Line
{
public:
	ll xStart, yStart, xEnd, yEnd;
	
	Line()
	{
		xStart = 0;
		yStart = 0;
		xEnd = 0;
		yEnd = 0;
	}
	Line(ll xStart_, ll yStart_, ll xEnd_, ll yEnd_)
	{
		xStart = xStart_;
		yStart = yStart_;
		xEnd = xEnd_;
		yEnd = yEnd_;
	}

	bool operator<(Line other)
	{
		if (xStart != other.xStart)
		{
			return xStart < other.xStart;
		}
		if (yStart != other.yStart)
		{
			return yStart < other.yStart;
		}
		if (xEnd != other.xEnd)
		{
			return xEnd < other.xEnd;
		}
		return yEnd < other.yEnd;
	}

	bool operator>(Line other)
	{
		if (xStart != other.xStart)
		{
			return xStart > other.xStart;
		}
		if (yStart != other.yStart)
		{
			return yStart > other.yStart;
		}
		if (xEnd != other.xEnd)
		{
			return xEnd > other.xEnd;
		}
		return yEnd > other.yEnd;
	}

};

int ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	ll tmp = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
	if (tmp > 0)	return 1;
	if (tmp == 0)	return 0;
	if (tmp < 0)	return -1;
}

void swap(ll& a, ll& b)
{
	ll temp = a;
	a = b;
	b = temp;
}

int cross(Line l1, Line l2)
{
	ll x1 = l1.xStart,
		y1 = l1.yStart,
		x2 = l1.xEnd,
		y2 = l1.yEnd,
		x3 = l2.xStart,
		y3 = l2.yStart,
		x4 = l2.xEnd,
		y4 = l2.yEnd;

	int isCross1 = ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4);
	int isCross2 = ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2);

	if ((isCross1 == -1 && isCross2 == -1) || (isCross1 == 0 && isCross2 == -1) || (isCross1 == -1 && isCross2 == 0))
	{
		return 1;
	}
	else if (isCross1 == 1 || isCross2 == 1)
	{
		return 0;
	}

	// 두 선분의 방향벡터가 평행할 경우
	else if ((x4 - x3) * (y2 - y1) == (x2 - x1) * (y4 - y3))
	{
		if (x1 - x2 == 0)
		{
			if ((y1 - y3) * (y2 - y3) <= 0 || (y1 - y4) * (y2 - y4) <= 0
				|| (y1 >= min(y3, y4) && y1 <= max(y3, y4) && y2 >= min(y3, y4) && y2 <= max(y3, y4))
				|| (y3 >= min(y1, y2) && y3 <= max(y1, y2) && y4 >= min(y1, y2) && y4 <= max(y1, y2)))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if ((x1 - x3) * (x2 - x3) <= 0 || (x1 - x4) * (x2 - x4) <= 0
				|| (x1 >= min(x3, x4) && x1 <= max(x3, x4) && x2 >= min(x3, x4) && x2 <= max(x3, x4))
				|| (x3 >= min(x1, x2) && x3 <= max(x1, x2) && x4 >= min(x1, x2) && x4 <= max(x1, x2)))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	else
	{
		return 1;
	}
}

template <typename T>
class Disjoint
{
public:
	T data;
	ll size;
	Disjoint* parent;

	Disjoint()
	{
		size = 1;
		parent = this;
	}

	Disjoint(T data_)
	{
		data = data_;
		size = 1;
		parent = this;
	}

	Disjoint* getParent()
	{
		if (parent == this)
		{
			return this;
		}
		Disjoint* tempParent = parent->getParent();
		return parent = tempParent;
	}

	bool hasSameParents(Disjoint* other)
	{
		return getParent() == other->getParent();
	}

	void unite(Disjoint* other)
	{
		Disjoint* d1 = getParent();
		Disjoint* d2 = other->getParent();
		if (d1 == d2)
		{
			return;
		}
		if (d1->data < d2->data)
		{
			d1->size += d2->size;
			d2->parent = d1->parent;
		}
		else
		{
			d2->size += d1->size;
			d1->parent = d2->parent;
		}
	}

	ll getSize()
	{
		return getParent()->size;
	}
};

int main(void)
{
	ll n, groupCnt, maxSize = 0;
	cin >> n;
	groupCnt = n;
	vector<Disjoint<Line> > lines(n);
	for (int i = 0; i < n; i++)
	{
		cin >> lines[i].data.xStart >> lines[i].data.yStart >> lines[i].data.xEnd >> lines[i].data.yEnd;
		for (int j = 0; j < i; j++)
		{
			if (lines[i].getParent() != lines[j].getParent())
			{
				if (cross(lines[i].data, lines[j].data))
				{
					lines[i].unite(&(lines[j]));
					groupCnt--;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		maxSize = max(maxSize, lines[i].getSize());
	}

	cout << groupCnt << '\n';
	cout << maxSize << '\n';

	return 0;
}
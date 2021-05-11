#include <iostream>
#include <vector>

using namespace std;

// Disjiont는 집합의 집합(?)이라고 생각하면 될듯
template <typename T>
class Disjoint
{
public:
	T data;
	Disjoint* parent;

	Disjoint()
	{
		data = 0;
		parent = this;
	}

	Disjoint(T data_)
	{
		data = data_;
		parent = this;
	}

	Disjoint(T data_, Disjoint parent_)
	{
		data = data_;
		parent = &parent_;
	}

	Disjoint(T data_, Disjoint* parent_)
	{
		data = data_;
		parent = parent_;
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

	bool hasSameParents(Disjoint other)
	{
		return getParent() == other.getParent();
	}

	void unite(Disjoint other)
	{
		Disjoint* d1 = getParent();
		Disjoint* d2 = other.getParent();
		if (d1 == d2)
		{
			return;
		}
		if (d1->data < d2->data)
		{
			d2->parent = d1->parent;
		}
		else
		{
			d1->parent = d2->parent;
		}
	}
};

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<Disjoint<int> > disjoints(n + 1);
	vector<int> connects(n + 1);
	vector<int> route(m);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> connects[j];
			if (connects[j])
			{
				disjoints[i].unite(disjoints[j]);
			}
		}
	}

	bool connected = true;
	for (int i = 0; i < m; i++)
	{
		cin >> route[i];
	}

	for (int i = 1; i < m; i++)
	{
		if (!disjoints[route[0]].hasSameParents(disjoints[route[i]]))
		{
			connected = false;
			break;
		}
	}

	cout << (connected ? "YES" : "NO") << '\n';
	return 0;
}

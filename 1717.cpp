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

	int op, a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> op >> a >> b;
		if (op == 0)
		{
			disjoints[a].unite(disjoints[b]);
		}
		else
		{
			if (disjoints[a].hasSameParents(disjoints[b]))
			{
				cout << "YES" << '\n';
			}
			else
			{
				cout << "NO" << '\n';
			}
		}
	}

	return 0;
}

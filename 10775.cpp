#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
typedef long long ll;

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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int g, p;
	cin >> g >> p;
	vector<int> planes;
	vector<Disjoint<int> > parents;
	for (int i = 0; i <= g; i++)
	{
		parents.push_back(Disjoint<int>(i));
	}
	for (int i = 0; i <= g; i++)
	{
		parents[i].parent = &parents[i];
	}
	for (int i = 0; i < p; i++)
	{
		int temp;
		cin >> temp;
		planes.push_back(temp);
	}
	int ans = 0;
	for (int elem : planes)
	{
		Disjoint<int>* temp = parents[elem].getParent();
		if (temp == &parents[0])
		{
			break;
		}
		(*temp).unite(&parents[temp->data - 1]);
		ans++;
	}

	cout << ans << '\n';
	return 0;
}

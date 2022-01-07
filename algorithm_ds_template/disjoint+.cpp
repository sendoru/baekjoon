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

	int t;
	cin >> t;
	while (t--)
	{
		int f;
		cin >> f;
		unordered_map<string, Disjoint<string> > people;
		while (f--)
		{
			string f1Name, f2Name;
			cin >> f1Name >> f2Name;

			if (people.find(f1Name) == people.end())
			{
				people.insert({ f1Name, Disjoint<string>(f1Name) });
			}
			Disjoint<string>* f1 = &(people[f1Name]);
			if (f1->parent->data == "")
			{
				f1->parent = f1;
			}

			if (people.find(f2Name) == people.end())
			{
				people.insert({ f2Name, Disjoint<string>(f2Name) });
			}
			Disjoint<string>* f2 = &(people[f2Name]);
			if (f2->parent->data == "")
			{
				f2->parent = f2;
			}

			f1->unite(f2);
			cout << f1->getSize() << '\n';
		}
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <unordered_set>

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
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, m, peopleCnt, tmp, partyCnt = 0;
	cin >> n >> m;
	int awared = -1;
	vector<Disjoint<int> > people(n + 1);
	vector<vector<int> > party(m);

	for (int i = 0; i <= n; i++)
	{
		people[i].data = i;
	}

	cin >> peopleCnt;
	for (int i = 0; i < peopleCnt; i++)
	{
		cin >> tmp;
		if (awared != -1)
		{
			people[tmp].unite(&(people[awared]));
		}
		awared = people[tmp].getParent()->data;
	}

	for (int i = 0; i < m; i++)
	{
		bool flag = false;
		cin >> peopleCnt;
		for (int j = 0; j < peopleCnt; j++)
		{
			cin >> tmp;
			party[i].push_back(tmp);
			if (j >= 1)
			{
				people[party[i][j]].unite(&(people[party[i][j - 1]]));
			}
		}
	}

	if (awared == -1)
	{
		partyCnt = party.size();
	}

	else
	{
		for (int i = 0; i < m; i++)
		{
			if (party[i].empty() || people[party[i][0]].getParent()->data != people[awared].getParent()->data)
			{
				partyCnt++;
			}
		}
	}

	cout << partyCnt << '\n';
	return 0;
}
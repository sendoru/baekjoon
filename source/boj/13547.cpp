#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;

class SegQuery
{
    int l, r, idx, bucketSize;
    friend class Mos;

public:
    SegQuery()
    {
        l = 0; r = 0; idx = 0; bucketSize = 1000;
    }
    SegQuery (int _l, int _r, int _idx, int _bucketSize)
    {
        l = _l;
        r = _r;
        idx = _idx;
        bucketSize = _bucketSize;
    }
    SegQuery(int _l, int _r, int _idx)
    {
        l = _l;
        r = _r;
        idx = _idx;
        bucketSize = 1000;
    }
    const bool operator< (const SegQuery& other)
    {
        if (r / bucketSize != other.r / other.bucketSize)
            return r / bucketSize < other.r / other.bucketSize;
        else
            return l < other.l;
    }
    void setBucketSize(int _bucketSize)
    {
        bucketSize = _bucketSize;
    }
};

class Mos
{
    vector<int> seq;
    vector<int> cnt;
    vector<int> ans;
    vector<SegQuery> queries;
    int seqSize, bucketSize;

public:
    Mos(vector<int>& _seq)
    {
        seq = _seq;
        seqSize = seq.size();
        bucketSize = (int)sqrt(seqSize);

        int maxValue = 0;
        for (auto& elem : seq)
            maxValue = max(maxValue, elem);
        cnt.resize((ll)maxValue + 1);
    }

    Mos(vector<int>& _seq, vector<SegQuery> _queries)
    {
        seq = _seq;
        seqSize = seq.size();
        bucketSize = (int)sqrt(seqSize);

        int maxValue = 0;
        for (auto& elem : seq)
            maxValue = max(maxValue, elem);
        cnt.resize((ll)maxValue + 1);

        queries = _queries;
        for (auto& query : queries)
            query.setBucketSize(bucketSize);

        ans.resize(queries.size());
    }

    void sortQueries()
    {
        sort(queries.begin(), queries.end());
    }

    void AddQuery(SegQuery& query)
    {
        queries.push_back(query);
        queries.back().setBucketSize(bucketSize);
        ans.push_back(0);
    }

    vector<int> solve()
    {
        sortQueries();
        int curCnt = 0, lo = 1, hi = 0;
        auto f = [&] (int idx, bool add) -> void
        {
            if (add)
            {
                if (cnt[seq[idx]] == 0)
                {
                    curCnt++;
                }
                cnt[seq[idx]]++;
            }
            else
            {
                if (cnt[seq[idx]] == 1)
                {
                    curCnt--;
                }
                cnt[seq[idx]]--;
            }
        };

        for (auto& query : queries)
        {
            while (query.l < lo)
            {
                lo--;
                f(lo, 1);
            }
            while (query.l > lo)
            {
                f(lo, 0);
                lo++;
            }
            while (query.r < hi)
            {
                f(hi, 0);
                hi--;
            }
            while (query.r > hi)
            {
                hi++;
                f(hi, 1);
            }
            ans[query.idx] = curCnt;
        }

        return ans;
    }
};

void coordinateCompress (vector<int>& v)
{
    vector<pair<int, int>> tmp(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        tmp[i].first = v[i];
        tmp[i].second = i;
    }
    sort(v.begin(), v.end());
    sort(tmp.begin(), tmp.end());
    tmp[0].first = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i - 1])
        {
            tmp[i].first = tmp[i - 1].first;
        }
        else
        {
            tmp[i].first = tmp[i - 1].first + 1;
        }
    }
    sort(tmp.begin(), tmp.end(), [] (pair<int, int> a, pair<int, int> b) -> bool {return a.second < b.second;});
    for (int i = 0; i < v.size(); i++)
    {
        v[i] = tmp[i].first;
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> seq(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> seq[i];
    }
    coordinateCompress(seq);

    int m;
    cin >> m;
    vector<SegQuery> queries(m);
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        queries[i] = SegQuery(l, r, i);
    }

    Mos mos(seq, queries);
    auto ans = mos.solve();
    for (auto elem : ans)
        cout << elem << '\n';

    return 0;
}
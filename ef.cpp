pair<int, int> findRoot(pair<int, int> x, vector<vector<pair<int, int>>>& roots)
{
	if (roots[x] == x) return x;
	return roots[x] = findRoot(roots[x], roots);
}

bool hasSameRoots(pair<int, int> x, pair<int, int> y, vector<vector<pair<int, int>>>& roots)
{
	return (findRoot(x, roots) == findRoot(y, roots));
}

void unite(pair<int, int> x, pair<int, int> y, vector<vector<pair<int, int>>>& roots, vector<vector<pair<int, int>>>& sizes)
{
	pair<int, int> xRoot = findRoot(x, roots), yRoot = findRoot(y, roots);
	if (xRoot != yRoot)
	{
		sizes[xRoot] += sizes[yRoot];
		roots[yRoot] = xRoot;
	}
}
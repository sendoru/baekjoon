#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

int bfs(vector<string>& maze)
{
    int dr[] = { 1, -1, 0, 0 };
    int dc[] = { 0, 0, -1, 1 };
    int rSize = maze.size(), cSize = maze[0].size();
    vector<vector<int>> visited(rSize, vector<int>(cSize, -1));

    deque<pair<int, int>> dq;
    dq.push_back({ 0, 0 });
    visited[0][0] = 0;

    while (!dq.empty())
    {
        pair<int, int> curNode = dq.front();
        dq.pop_front();

        if (curNode == make_pair(rSize - 1, cSize - 1))
        {
            return visited[curNode.first][curNode.second];
        }

        for (int i = 0; i < 4; i++)
        {
            pair<int, int> nextNode = { curNode.first + dr[i], curNode.second + dc[i] };
            if (nextNode.first >= 0 && nextNode.first < rSize && nextNode.second >= 0 && nextNode.second < cSize && visited[nextNode.first][nextNode.second] == -1)
            {
                int nextCost = maze[nextNode.first][nextNode.second];
                if (nextCost == '0')
                {
                    visited[nextNode.first][nextNode.second] = visited[curNode.first][curNode.second];
                    dq.push_front(nextNode);
                }
                else
                {
                    visited[nextNode.first][nextNode.second] = visited[curNode.first][curNode.second] + 1;
                    dq.push_back(nextNode);
                }
            }
        }
    }

    return -1;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    vector<string> maze(m);
    for (int i = 0; i < m; i++)
    {
        cin >> maze[i];
    }

    cout << bfs(maze);
    return 0;
}
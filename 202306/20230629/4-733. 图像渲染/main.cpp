#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution
{
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int newColor, int oldColor)
    {
        // 递归的写法，对于每一个条件都要限制好
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != oldColor)
        {
            return;
        }

        image[sr][sc] = newColor;
        dfs(image, sr + 1, sc, newColor, oldColor);
        dfs(image, sr - 1, sc, newColor, oldColor);
        dfs(image, sr, sc + 1, newColor, oldColor);
        dfs(image, sr, sc - 1, newColor, oldColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int oldColor = image[sr][sc];
        if (oldColor != newColor)
        {
            dfs(image, sr, sc, newColor, oldColor);
        }
        return image;
    }
};
class Solution1
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        int oldColor = image[sr][sc];
        if (oldColor == newColor)
        {
            return image;
        }

        int rows = image.size();
        int cols = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = newColor;

        vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();

            for (pair<int, int> dir : directions)
            {
                int newRow = curr.first + dir.first;
                int newCol = curr.second + dir.second;

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && image[newRow][newCol] == oldColor)
                {
                    q.push({newRow, newCol});
                    image[newRow][newCol] = newColor;
                }
            }
        }
        return image;
    }
};
#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <set>
#include <array>
using namespace std;
class Solution1
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
    }
};
class Solution
{
private:
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    // directions数组表示四个可能的方向：右、下、左、上。
    // 每个方向由一个行列增量的对表示。
    // 例如，{0, 1}表示向右移动（列增量为1），{1, 0}表示向下移动（行增量为1），以此类推。
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return {};
        }
        // 如果矩阵为空或矩阵的行数或列数为0，则返回空向量。

        int rows = matrix.size(), columns = matrix[0].size();
        // 获取矩阵的行数和列数。
        vector<vector<bool>> visited(rows, vector<bool>(columns));
        // 创建一个visited矩阵，用于标记已访问的位置。
        int total = rows * columns;
        // 计算矩阵中元素的总数。
        vector<int> order(total);
        // 创建一个用于存储螺旋顺序元素的向量，大小为总数。

        int row = 0, column = 0;
        // 初始化当前位置为矩阵的左上角。
        int directionIndex = 0;
        // 初始化方向索引为0，表示向右移动。
        for (int i = 0; i < total; i++)
        {
            order[i] = matrix[row][column];
            // 将当前位置的元素添加到螺旋顺序的向量中。
            visited[row][column] = true;
            // 标记当前位置为已访问。

            int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
            // 计算下一个位置的行和列。
            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn])
            {
                // 如果下一个位置超出边界或已经访问过，则表示需要改变方向。
                directionIndex = (directionIndex + 1) % 4;
                // 改变方向索引，使其循环在四个方向间切换。
            }
            row += directions[directionIndex][0];
            column += directions[directionIndex][1];
            // 更新当前位置为下一个位置。
        }
        return order;
        // 返回螺旋顺序的向量。
    }
};

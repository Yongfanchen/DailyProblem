# 学习的算法框架

## 1.链表、数组

---

## 2.二叉树

### 1.快速排序的框架：二叉树的前序遍历

```c++
void sort(int nums[], int lo, int hi){
    /****前序遍历位置****/
    //通过交换元素构建分解点
    int p = paritition(nums, lo, hi);
    /*****************/

    sort(nums, lo, p - 1);
    sort(nums, p + 1, hi);
}
```

### 2.归并排序的框架：二叉树的后序遍历

```c++
// 定义：排序 nums[lo..hi]
void sort(vector<int>& nums, int lo, int hi) {
    int mid = (lo + hi) / 2;
    // 对 nums[lo..mid] 进行排序
    sort(nums, lo, mid);
    // 对 nums[mid+1..hi] 进行排序
    sort(nums, mid + 1, hi);

    /****** 在后序位置进行归并操作 ******/
    // 合并 nums[lo..mid] 和 nums[mid+1..hi]
    merge(nums, lo, mid, hi);
    /**********************************/
}
```

### 3.二叉树遍历的框架

```c++
void traverse(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    // 前序位置
    traverse(root->left);
    // 中序位置
    traverse(root->right);
    // 后序位置
}
```

### 4.数组、链表遍历的框架(其实都是遍历的框架)

```c++
//迭代遍历数组
void traverse(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {

    }
}

//递归遍历数组
void traverse(vector<int>& arr, int i) {
    if (i == arr.size()) {
        return;
    }
    //前序位置
    traverse(arr, i + 1);
    //后序位置
}

//迭代遍历单链表
void traverse(ListNode* head) {
    for (ListNode* p = head; p != nullptr; p = p -> next) {

    }
}

//递归遍历单链表
void traverse(ListNode* head) {
    if (head == nullptr) {
        return;
    }
    //前序位置
    traverse(head -> next);
    //后序位置
}
```

### 5.倒序导引一条单链表上的所有的值

```c++
//递归遍历单链表，倒序打印链表元素
void traverse(ListNode* head) {
    if(head == NULL) {
        return;
    }
    traverse(head->next);
    //后序位置
    print(head->val);
}
```

![树的遍历](binarytree.jpeg)

### 6.多叉树的遍历

```c++
//多叉树遍历框架
void traverse(TreeNode* root) {
    if(root == nullptr) return;
    //前序位置
    for(TreeNode* child : root->children) {
        traverse(child);
    }
    //后序位置
}
```

### 7.二叉树的层序遍历

```c++
//输入一颗二叉树的根节点，层序遍历这颗二叉树
void leverTraverse (TreeNode* root) {
    if (root == nullprt) return;
    queue<TreeNode*> q;
    q.push(root);

    //从上到下遍历二叉树的每一层
    while (!q.empty()) {
        int sz = q.size();
        //从左到右遍历每一层的每个节点
        for (int i = 0; i < sz; i++) {
            TreeNode* cur = q.front();
            q.pop();
            //将下一层节点放入队列
            if (cur->left != nullptr) {
                q.push(cur->left);
            }
            if (cur->right != nullptr) {
                q.push(cur->right);
            }
        }
    }
}
```

## 3.图

### 1，图的逻辑结构

```c++
/*图节点的逻辑结构*/
class Vertex{
    int id;
    vector<Vertex*> neighbors;
};

/*基本的N叉树节点*/
class TreeNode {
public:
    int val;
    vector<TreeNode*> children;

}

//邻接表
//graph[x] 存储x的所有邻居节点
vector<int> graph[];

//邻接矩阵
//matrix[x][y] 记录x是否有一条指向y的边
bool matrix[][];

//记住是邻接表使用的更频繁


//加权有向图
//邻接表
//graph[x] 存储x的所以邻居节点以及对应的权重
vector<pari<int,int>> graph[];

//邻接矩阵
//matrix[x][y] 记录x指向y的边的权重，0表示不相邻
vector<vector<int>> matrix;
```

### 2,多叉树的遍历框架

```c++
/*多叉树的遍历框架*/
void traverse(TreeNode* root) {
    if (root == nullptr) return;
    //前序位置
    for(TreeNode* child : root->children) {
        traverse(child);
    }
}
```

### 3,图的遍历框架

```c++
//记录被遍历的过的节点
vector<bool> visited;

//记录从起点到到当前节点的路径
vector<bool> onPath;

/*图遍历框架*/
void traverse(Graph graph, int s) {
    if (visited[s]) return;
    //经过节点s，标记为已遍历
    visited[s] = true;
    //做选择；标记节点s在路径上

    onPath[s] = true;
    for(int neighbor : graph.neighnor(s)) {
        traverse(graph, neighbor);
    }
    //撤销选择：节点s离开路径
    onPath[s] = false;
}
```

### 4.回溯算法和$DFS$的区别

```c++
//DFS 算法，关注点在节点
void traverse(TreeNode* root) {
    if(root == nullptr) return;
    printf("进入节点 %s", root);
    for (TreeNode* child : root->children) {
        traverse(child);
    }
    printf("离开节点 %s", root);
}

//回溯算法 关注点在树枝
void backtrack(TreeNode* root) {
    if (root == nullptr) return;
    for (TreeNode* child : root->children) {
        //做选择
        prinft("从 %s 到 %s", root, child);
        backtrack(child);
        //撤销选择
        printf("从 %s 到 %s", child, root);
    }
}

```

### 5.环检测算法与拓扑排序



### 6.$DFS$的遍历框架

```c++
//防止重复遍历同一个节点
vector<bool> visited;
//从节点s开始DFS遍历，将遍历过的节点标记为true
void traverse (vector<int>* graph, int s) {
    if (visited[s]) {
        return;
    }

    /*前序遍历代码位置*/
    //将当前节点标记为已遍历
    visited[s] = true;
    for (int t : graph[s]) {
        traverse(graph, t);
    }
    /*后序遍历位置*/
}
```

### 7.$BFS$的遍历框架：

$BFS$的问题本质：就是让你在一幅图中，找到从起点 start 到 target 的最近距离，听起来很枯燥，但是$BFS$就是干这个事。

```c++
int BFS (Node start, Node target) {
    queue<Node> q;
    set<Node> visited;

    q.push(start);

    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; i++) {
            Node cur = q.front();
            q.pop();
            if (cur == target)
                return step;
            for (Node x : cur.adj()) {
                if (visited.count(x) == 0) {
                    q.push(x);
                    visited.insert(x);
                }
            }
        }
    }
    //如果走到这，说明在图中没有找到目标节点
}
```

密码锁问题

首先算法题不能一蹴而就，需要慢慢来,先将框架写好然后再在框架上面补充。

```c++
void BFS(string target) {
    queue<string> q;
    q.push("0000");
    while (!q.empty()) {
        int sz = q.size();
        /*将当前队列中的所有节点向周围扩散*/
        for (int i = 0; i < sz; i++) {
            string cur = q.front();
            q.pop();
            /*判断是否到达终点*/
            cout << cur << endl;
            
            /*将每一个节点的相邻节点加入队列*/
            for	(int j = 0; j < 4; j++) {
                string up = plusOne(cur, j);
                string down = minusOne(cur, j);
                q.push(up);
                q.push(down);
            }
        }
        /*这里增加步数*/
    }
    return;
}
```



```c++
// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码还未经过力扣测试，仅供参考，如有疑惑，可以参照我写的 java 代码对比查看。

int openLock(vector<string>& deadends, string target) {
    // 记录需要跳过的死亡密码
    unordered_set<string> deads;
    for (string s : deadends) {
        deads.insert(s);
    }
    // 记录已经穷举过的密码，防止走回头路
    unordered_set<string> visited;
    queue<string> q;
    // 从起点开始启动广度优先搜索
    int step = 0;
    q.push("0000");
    visited.insert("0000");

    while (!q.empty()) {
        int sz = q.size();
        /* 将当前队列中的所有节点向周围扩散 */
        for (int i = 0; i < sz; i++) {
            string cur = q.front();
            q.pop();

            /* 判断是否到达终点 */
            if (deads.count(cur))
                continue;
            if (cur == target)
                return step;

            /* 将一个节点的未遍历相邻节点加入队列 */
            for (int j = 0; j < 4; j++) {
                string up = plusOne(cur, j);
                if (!visited.count(up)) {
                    q.push(up);
                    visited.insert(up);
                }
                string down = minusOne(cur, j);
                if (!visited.count(down)) {
                    q.push(down);
                    visited.insert(down);
                }
            }
        }
        /* 在这里增加步数 */
        step++;
    }
    // 如果穷举完都没找到目标密码，那就是找不到了
    return -1;
}
```

## 4.回溯算法

回溯算法的框架，是一个决策树的遍历过程。需要解决三个问题。

1、路径：也就是已经做出的选择

2、选择列表：也就是你当前可以做的选择

3、结束条件：也就是到达决策树底层，无法再做选择的条件。

```python
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return

    for 选择 in 选择列表:
        做选择
        backtrack(路径, 选择列表)
        撤销选择

```

核心就是 for 循环里面的递归，在递归调用前做选择，在递归调用之后撤销选择。

多叉树的遍历框架：

```c++
void traverse(TreeNode* root) {
    for (TreeNode* child : root->child) {
        //前序位置需要的操作
        traverse(child);
        //后序位置需要的操作
    }
}
```

```python
for 选择 in 选择列表 :
    #做选择
    将该选择从选择列表溢出
    if(满足条件) return;
    路径.add(选择)
    braktrack(路径, 选择列表)
    #撤销选择
    路径.add(选择)
    将该选择再加入列表
```

递归前做出选择，递归后撤销刚刚的选择。回溯算法其实就是多叉树的遍历问题，关键就是再前序遍历和后序遍历的位置做一些操作，算法框架如下：

```python
def backtrack(...)
	for 选择 in 选择列表:
        做选择
        backtrack(...)
        撤销选择
```

n 皇后问题在判断时是否存在皇后时

```c++
bool isValid (vector<string> &board, int row, int col) {
    int n = board.size();
    //1.首先检查board的[row,col]元素的直上方列
    for (int i = 0; i < low; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }
    //2.如何检查右上方是否有皇后冲突
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {

    }
    //3.然后检查左上方是否有皇后冲突
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {

    }
}
```

## 5.动态规划

动态规划问题的一般形式就是求最值。求解动态规划的核心问题是穷举。

1.正确的“状态转移方程”

2.具备最优子结构

3.存在“重叠子问题”

明确 base case->明确“状态”->明确“选择”->定义 DP 数组/函数的含义。

```python
#自顶向下递归的动态规划
def dp(状态1， 状态2， ...):
    for 选择 in 所有可能的选择：
    	#此时的状态已经因为做了选择而改变
   		result = 求最值(result, dp(状态1， 状态2， ...))
   return result


#自底向上迭代的动态规划
#初始化base case
dp[0][0][...] = base case
#进行状态转移
for 状态1 in 状态1的所有取值：
	for 状态2 in 状态2的所有取值：
    	for ...
        	dp[状态1][状态2][...] = 求最值(选择1， 选择2 ...)

```

## 6.股票问题

状态机是什么？

![状态机](iamge/shareproblem.png)

那么转移方程为

```c++
dp[i][k][0] = max(dp[i-1][k][0],dp[i-1][k][1] + prices[i])
    		  max(今年选择 rest,  今天选择sell)
```

解释：今天我没有持有股票，有两种可能，我从这两种可能中求最大利润

1，我昨天没有持有股票，且截止昨天最大交易次数限制为 k；然后我们今天选择 rest，所以我今天还是没有持有，最大交易次数限制还是为 k；

2，我昨天持有股票，且截止昨天最大交易次数限制为 k；但是我今天 sell 了，所以我今天持有股票，最大交易次数限制依然为 k。

```c++
dp[i][k][1] = max(dp[i-1][k][1],dp[i-1][k][0] - prices[i])
    		  max(今年选择 rest,  今天选择buy)
```

解释：我今天持有股票，最大交易次数限制为 k，那么对昨天来说，有两种可能，我从这两种可能求最大利润：

1，我昨天就持有股票，最大交易次数限制为 k，然后今天选择 rest，所以我今天还是持有这股票，最大交易次数限制依然为 k。

2，我状态没有股票，且截止昨天最大交易次数限制为 k - 1 ；但今天我选择 buy，所以今天我就持有股票了，最大交易次数限制为 l。

结果是

```cpp
dp[n-1][k][0]  //将股票卖出去，并且最大限制交易次数为k
```

状态转移方程已经确定，接下来确定的是，定义 base case，就是最简单的情况，然后开始。

```c++
dp[-1][...][0] = 0
//解释：因为 i 是从 0 开始的，所以 i = -1 意味着还没有开始，这时候的利润当然是 0。

dp[-1][...][1] = -infinity
//解释：还没开始的时候，是不可能持有股票的。
//因为我们的算法要求一个最大值，所以初始值设为一个最小值，方便取最大值。

dp[...][0][0] = 0
//解释：因为 k 是从 1 开始的，所以 k = 0 意味着根本不允许交易，这时候利润当然是 0。

dp[...][0][1] = -infinity
//解释：不允许交易的情况下，是不可能持有股票的。
//因为我们的算法要求一个最大值，所以初始值设为一个最小值，方便取最大值。

```

上面的状态方程整理一下就是

```c++
base case;
dp[-1][...][0] = dp[...][0][0] = 0;
dp[-1][...][1] = dp[...][0][1] = INT_MIN;


//状态转移方程
dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);

```




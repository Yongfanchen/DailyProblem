# 学习的算法框架

## 1.链表、数组



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



## 3.图

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

核心就是for循环里面的递归，在递归调用前做选择，在递归调用之后撤销选择。

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

n皇后问题在判断时是否存在皇后时

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

明确base case->明确“状态”->明确“选择”->定义 DP 数组/函数的含义。



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






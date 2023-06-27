#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;
/*
645. ����ļ���
���� s ������ 1 �� n �����������ҵ��ǣ���Ϊ���ݴ��󣬵��¼�������ĳһ�����ָ����˳��˼������������һ�����ֵ�ֵ�����¼��� ��ʧ��һ������ ���� ��һ�������ظ� ��

����һ������ nums �����˼��� S ���������Ľ����

�����ҳ��ظ����ֵ����������ҵ���ʧ�����������������������ʽ���ء�

ʾ�� 1��

���룺nums = [1,2,2,4]
�����[2,3]
ʾ�� 2��

���룺nums = [1,1]
�����[1,2]
*/
class Solution
{
public:
	vector<int> findErrorNums(vector<int> &nums)
	{
		unordered_map<int, int> hashmap;
		for (auto & num : nums)
		{
			hashmap[num]++;
		}
		vector<int> res(2);
		int n = nums.size();
		for (int i = 1; i <= n; i++)
		{
			int count = hashmap[i];
			if (count == 2)
				res[0] = i;
			else if (count == 0)
				res[1] = i;
		}
		return res;
	}
};

class Solution
{
public:
	vector<int> findErrorNums(vector<int>& nums)
	{
		vector<int> errorNums(2);
		int n = nums.size();
		unordered_map<int, int> mp;
		for (auto& num : nums)
		{
			mp[num]++;
		}
		for (int i = 1; i <= n; i++)
		{
			int count = mp[i];
			if (count == 2)
			{
				errorNums[0] = i;
			}
			else if (count == 0)
			{
				errorNums[1] = i;
			}
		}
		return errorNums;
	}
};

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
#include <cmath>
#include <map>
using namespace std;
class Solution1 {

	//����һ�������ظ����ֵ����� nums �������� ���п��ܵ�ȫ���� ������� ������˳�� ���ش𰸡�
private:

	vector<vector<int>> res;

	void backtrack(vector<int>& nums, vector<int>&track, vector<bool>& used) {
		//��������
		if (track.size() == nums.size()) {
			res.push_back(track);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			//�ų����Ϸ���ѡ��
			if (used[i]) {
				continue;
			}
			track.push_back(nums[i]);
			used[i] = true;
			//������һ�������
			backtrack(nums, track, used);
			//ȡ��ѡ��
			track.pop_back();
			used[i] = false;
		}
	}


public:

	//����һ�鲻�ظ������֣��������ǵ�ȫ����
	vector<vector<int>> permute(vector<int>& nums) {

		//��¼��·����
		vector<int> track;

		//"·��"�е�Ԫ�ػᱻ���Ϊtrue�������ظ�ʹ��
		vector<bool> used(nums.size(), false);

		backtrack(nums, track, used);
		return res;
	}
};
//��˺һ��ȫ����
class Solution {
private:

	//���������
	vector<vector<int>> res;

public:
	vector<vector<int>> permute(vector<int>& nums) {

		//����Ƿ��ù�Ҫ��ǵ�������������±�
		vector<bool> used(nums.size(), false);
		vector<int> track;
		backtrack(nums, track, used);
		return res;
	}
	void backtrack(vector<int>& nums, vector<int>&track, vector<bool> &used) {
		
		//��������
		if (track.size() == nums.size()) {
			res.push_back(track);
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (used[i]) {
				continue;
			}
			track.push_back(nums[i]);
			//����ȷused[i]�Ĵ���
			used[i] = true;
			backtrack(nums, track, used);
			track.pop_back();

			used[i] = false;
		}
	}

};
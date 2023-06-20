#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <set>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> setInt;
        vector<int> res;
        for (auto & num : nums) {
            setInt.insert(num);
        }
        int n = setInt.size();
        for(auto iter = setInt.begin(); iter != setInt.end(); iter++) {
            res.emplace_back(*iter);
        }
        if (res.size() <= 2) {
            return res[n - 1];
        }
        return res[n - 3];
    }
};
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    int findComplement(int num) {
        vector<int> temp;
        while (num != 0) {
            temp.emplace_back(num & 1);
        }
    }
};
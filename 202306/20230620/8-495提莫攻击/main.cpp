#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int size = timeSeries.size();
        int res = 0;
        for (int i = 1; i < size; i++) {
            if (timeSeries[i] - timeSeries[i - 1] > duration) {
                res += duration;
            } else {
                res += timeSeries[i] - timeSeries[i - 1];
            }
        }
        return res + duration;
    }
};
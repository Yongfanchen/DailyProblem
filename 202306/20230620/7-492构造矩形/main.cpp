#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
class Solution1 {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(1.0 * area);
        while (area % w) {
            --w;
        }
        return {area / w, w};
    }
};

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l = sqrt(area);
        if (l * l != area) {
            l = l + 1;
        }
        while (area % l) {
            ++l;
        }
        return {l, area / l};
    }
};
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
            num >>= 1;
        }
        int n = temp.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            cout << temp[i] << endl;
            if (temp[i] == 0) {
                res += pow(2, i) * 1;
            } else if (temp[i] == 1) {
                res += 0;
            }
            
           // res += pow(2, i) * temp[i];
        }
        return res;
    }
};

int main() {
    Solution s;
    int res = s.findComplement(5);
    cout << res << endl;
    return 0;
}
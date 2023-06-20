#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

    int hammingDistance(int x, int y) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int tempx = x & 1;
            cout << "tempx:" << tempx << endl;
            int tempy = y & 1;
            cout << "tempy:" << tempy << endl;
            int  tempxy = tempx ^ tempy;
            cout << "tempx ^ tempy : " << tempxy << endl;
            if (tempx ^ tempy) {  //相同为0
                res++;
            }
            x >>= 1;
            y >>= 1;
        }
        return res;
    }

int main() {
    int res = hammingDistance(1, 4);
    cout << res << endl;
    return 0;
}
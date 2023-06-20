#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

string addStrings(string num1, string num2) {
    string res;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    std::cout << num1 << endl;
    std::cout << num2 << endl;
    int size1 = num1.size();
    int size2 = num2.size();
    int max = 0;
    if (size1 > size2 ) {
        max = size1;
        int gap = size1 - size2;
        for (int i = 0; i < gap; i++) {
            num2 += "0";
        }
    } else {
        max = size2;
        int gap = size2 - size1;
        for (int i = 0; i < gap; i++) {
            num1 += "0";
        }
    }

    // reverse(num1.begin(), num1.end());
    // reverse(num2.begin(), num2.end());
    std::cout << num1 << std::endl;
    std::cout << num2 << std::endl;
    int carry = 0;
    for (int i = 0; i < max; i++ ) {
        int temp = num1[i] - '0' + num2[i] - '0' + carry; 
        std::cout << num1[i] - '0' << std::endl;
        std::cout << num2[i] - '0' << std::endl;
        //int temp = num1[i] + num2[i] + carry;
        if (temp >= 10) {
            res += to_string(temp % 10);
            carry = 1;
            std::cout << temp << std::endl;
        } else {
            res += to_string(temp);
            carry = 0;
            std::cout << temp << std::endl;
        }
    } 
    if (carry == 1) {
        res += "1";
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    string res = addStrings("456", "77");
    std::cout << res << std::endl;
    return 0;
}
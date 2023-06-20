#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;


// 构建部分匹配表（计算 next 数组）
std::vector<int> buildNextArray(const std::string& pattern) {
    int patternLength = pattern.length();
    std::vector<int> next(patternLength, 0);
    int j = 0;  // 已匹配前缀的结束索引

    // 从第二个字符开始计算 next 数组
    for (int i = 1; i < patternLength; i++) {
        // 当前字符和已匹配前缀的下一个字符不相等时，回溯到上一个匹配前缀的下一个字符
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1];
        }

        // 当前字符和已匹配前缀的下一个字符相等时，增加匹配前缀的长度
        if (pattern[i] == pattern[j]) {
            j++;
        }

        // 将匹配前缀的长度赋值给 next 数组的当前位置
        next[i] = j;
    }

    return next;
}

int main() {
    std::string pattern = "ABACABAB";
    
    std::vector<int> next = buildNextArray(pattern);
    
    std::cout << "Next array: ";
    for (int i = 0; i < next.size(); i++) {
        std::cout << next[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
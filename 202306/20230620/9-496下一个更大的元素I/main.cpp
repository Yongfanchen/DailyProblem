#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stack>
using namespace std;

template <typename ValueType>
void printVector(const std::vector<ValueType>& vec) {
    std::cout << "{";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << vec[i];
    }
    std::cout << "}" << std::endl;
}

template <typename KeyType, typename ValueType>
void printUnorderedMap(const std::unordered_map<KeyType, ValueType>& map) {
    std::cout << "[";
    bool isFirst = true;
    for (const auto& pair : map) {
        if (!isFirst) {
            std::cout << ", ";
        }
        std::cout << "{" << pair.first << ", " << pair.second << "}";
        isFirst = false;
    }
    std::cout << "]" << std::endl;
}

template <typename ValueType>
void printStack(const std::stack<ValueType>& stack) {
    if (stack.empty()) {
        std::cout << "stack is empty" << std::endl;
        return;
    }

    std::stack<ValueType> tempStack = stack;
    std::cout << "{top:";
    while (!tempStack.empty()) {
        std::cout << tempStack.top();
        tempStack.pop();
        if (!tempStack.empty()) {
            std::cout << ", ";
        }
    }
    std::cout << ", bottom:" << stack.top() << "}" << std::endl;
}

class Solution1 {
public:
    vector<int> nextGreaterElement1(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashMap;
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            while (!st.empty() && num >= st.top()) {
                st.pop();
            }
            hashMap[num] = st.empty() ? -1 : st.top();
            st.push(num);
        }
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            res[i] = hashMap[nums1[i]];
        }
        return res;
    }
};

//思路是单调栈 


vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int n = nums2.size();
    unordered_map<int, int> hashmap;
    stack<int> st;
    for (int i = n - 1; i >= 0; --i) {
       // cout << "num[" << i << "] = " << nums2[i] <<endl;
        int num = nums2[i];
        while (!st.empty() && num >= st.top()) {
            cout << st.top() << endl;
            st.pop();
          //  cout << "st.pop()" << endl;
           // printStack<int>(st);
        }
        //string isEmpty = st.empty() ? "empty" : "not empty";
        //cout << "st is " << isEmpty << endl;
        hashmap[num] = st.empty() ? -1 : st.top();
        st.push(num);
        //cout << "st.push(" << num << ")" << endl;
        //printStack<int>(st);
    }
    vector<int> res(nums1.size());
    for (int i = 0; i < nums1.size(); i++) {
        res[i] = hashmap[nums1[i]];
    }
    //printUnorderedMap<int, int>(hashmap);
    return res;
}



int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> res;
    res = nextGreaterElement(nums1, nums2);
    printVector<int>(res);
    // printVector(nums1);
    // printVector(nums2);
    return 0;
}
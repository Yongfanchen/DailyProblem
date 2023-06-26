#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename ValueType>
void printVector(const std::vector<ValueType> &vec) {
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
void printUnorderedMap(const std::unordered_map<KeyType, ValueType> &map) {
  std::cout << "[";
  bool isFirst = true;
  for (const auto &pair : map) {
    if (!isFirst) {
      std::cout << ", ";
    }
    std::cout << "{" << pair.first << ", " << pair.second << "}";
    isFirst = false;
  }
  std::cout << "]" << std::endl;
}

template <typename ValueType>
void printStack(const std::stack<ValueType> &stack) {
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

template <typename ValueType>
void printQueue(const std::queue<ValueType> &queue) {
  if (queue.empty()) {
    std::cout << "Queue is empty" << std::endl;
    return;
  }

  std::queue<ValueType> tempQueue = queue;
  std::cout << "{front:";
  while (!tempQueue.empty()) {
    std::cout << tempQueue.front();
    tempQueue.pop();
    if (!tempQueue.empty()) {
      std::cout << ", ";
    }
  }
  std::cout << ", rear:" << queue.back() << "}" << std::endl;
}

template <typename T>
void printPairs(const std::vector<std::pair<T, T>> &pairs) {
  std::cout << "{";
  bool isFirst = true;
  for (const auto &pair : pairs) {
    if (!isFirst) {
      std::cout << ", ";
    }
    std::cout << "{" << pair.first << ", " << pair.second << "}";
    isFirst = false;
  }
  std::cout << "}" << std::endl;
}

vector<string> spiltStr(const string &s, char c) {
  vector<string> res;
  string current;
  for (char ch : s) {
    if (ch == c) {
      res.push_back(current);
      current.clear();
    } else {
      current += ch;
    }
  }
  res.push_back(current);
  return res;
}
int main() {
  std::vector<std::pair<int, int>> arr = {{1, 2}, {3, 5}};
  printPairs(arr);

  return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stack>
#include <cctype>

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
bool isContainer(const string& small, const string& big) {
    for (auto & ch : big) {
        if (small.find(ch) == string::npos) {
            return false;
        }
    }
    return true;
}
bool isAllCharactersInString(const std::string& s, const std::string& big) {
    std::string lowercaseS;
    for (char ch : s) {
        lowercaseS += std::tolower(ch);
    }

    std::string lowercaseBig;
    for (char ch : big) {
        lowercaseBig += std::tolower(ch);
    }

    for (char ch : lowercaseBig) {
        if (lowercaseS.find(ch) == std::string::npos) {
            return false;
        }
    }

    return true;
}
vector<string> findWords(vector<string>& words) {
    string s1 = "qwertyuiop";
    string s2 = "asdfghjkl";
    string s3 = "zxcvbnm";

    vector<string> res;
    for(auto & word : words) {
        if (isAllCharactersInString(s1, word) || isAllCharactersInString(s2, word) || isAllCharactersInString(s3, word)) {
            res.push_back(word);
        }
    }
    return res;
}

int main() {
    vector<string> words;
    words = {"Hello", "Alaska", "Dad", "Peace"};
    printVector<string>(words);
    vector <string> res = findWords(words);
    printVector<string>(res);
    return 0;
}
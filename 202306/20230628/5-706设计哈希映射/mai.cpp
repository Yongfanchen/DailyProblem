#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;
class MyHashMap
{
private:
    vector<list<pair<int, int>>> data;
    static const int base = 769;
    static int hash(int key)
    {
        return key % base;
    }

public:
    MyHashMap()
    {
    }

    void put(int key, int value)
    {
    }

    int get(int key)
    {
    }

    void remove(int key)
    {
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
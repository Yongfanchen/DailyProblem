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
    MyHashMap() : data(base)
    {
    }

    void put(int key, int value)
    {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++)
        {
            if ((*it).first == key)
            {
                (*it).second = value;
                return;
            }
        }
        data[h].push_back(make_pair(key, value));
    }

    int get(int key)
    {
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++)
        {
            if ((*it).first == key)
            {
                return (*it).second;
            }
        }
        return -1;
    }

    void remove(int key)
    {
        if (get(key) == -1)
            return;
        int h = hash(key);
        for (auto it = data[h].begin(); it != data[h].end(); it++)
        {
            if ((*it).first == key)
            {
                data[h].erase(it);
                return;
            }
        }
    }
};

int main()
{
}

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
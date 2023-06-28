#include <iostream>
#include <list>
#include <vector>
using namespace std;
class MyHashSet {
private:
	vector<list<int>> data;
	static const int base = 769;
	static int hash(int key)
	{
		return key % base;
	}
public:
	MyHashSet() :data(base)
	{}

	void add(int key)
	{
		int h = hash(key);
		for (auto it = data[h].begin(); it != data[h].end(); it++) {
			if ((*it) == key) {
				return;
			}
		}
		data[h].push_back(key);
	}

	void remove(int key)
	{
		int h = hash(key);
		for (auto it = data[h].begin(); it != data[h].end(); it++) {
			if ((*it) == key) {
				data[h].erase(it);
				return;
			}
		}
	}

	bool contains(int key)
	{
		int k = hash(key);
		for (auto it = data[k].begin(); it != data[k].end(); it++) {
			if ((*it) == key) {
				return true;
			}
		}
		return false;
	}
};

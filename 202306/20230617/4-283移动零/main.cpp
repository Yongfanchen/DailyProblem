#include <iostream>
#include <vector>

using namespace std;

void moveZeros(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) {
        return;
    }
    int j = 0;
    for (int i = 0; i< size; i++) {
        if (nums[i] != 0) {
            nums[j++] = nums[i];
        }
    }
    for (int i = j; i < size; i++) {
        nums[j++] = 0;
    }
}
class Solution {
public:
    bool isPerfectSquare(int num) {
        long x = 1, square = 1;
        while (square <= num) {
            if(square == num) {
                return true;
            }
            ++x;
            square = x * x;
        }
        return false;
    }
};

//二分查找的方法
bool isSquare(int num) {
    int left = 0, right = num;
    while (left <= right) {
        int mid = (left + right) / 2;
        long square = (long) mid * mid;
        if (square < num) {
            left = mid + 1;
        } else if (square > num) {
            right = mid - 1;
        } else {
            return true;
        }
    }
    return false;
}
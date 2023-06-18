/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int guessNumber = guess(mid);
            if (guessNumber == -1) {
                right = mid;
            }else if (guessNumber == 1) {  //在这里要注意  给left和right赋值要注意 到达是mid，mid + 1，mid - 1 ？
                left = mid + 1;
            }else {
                return mid;
            }
        }
        return left;
    }
};
int guess(int n) {

}
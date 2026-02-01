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

    int Binary(int l, int h) {
        int mid = l + (h - l) / 2;

        int res = guess(mid);

        if (res == -1) {
            return Binary(l, mid - 1);
        }

        else if (res == 1) {
            return Binary(mid + 1, h);
        }

        else {
            return mid;
        }




    }


    int guessNumber(int n) {

        int res = Binary(1, n);

        return res;

        
    }
};
/*
https://www.lintcode.com/en/problem/container-with-most-water/
最低木板的高度决定水位，高位的木板有着另一种单调性，即高位木板向里移动的所有位置，形成的 container 水量都小于原来位置。
*/

public class Solution {
    /**
     * @param heights: an array of integers
     * @return: an integer
     */
    public int maxArea(int[] heights) {
        // write your code here
        if(heights == null || heights.length == 0) return 0;
        int max = 0;
        int left = 0;
        int right = heights.length - 1;

        while(left < right){
            int width = right - left;
            int curArea = Math.min(heights[left], heights[right]) * width;
            max = Math.max(max, curArea);

            if(heights[left] < heights[right]){ //move lower one
                left ++;
            } else {
                right --;
            }
        }

        return max;
    }
}

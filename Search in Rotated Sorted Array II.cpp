/*
当有重复数字，会存在A[mid] = A[end]的情况。此时右半序列A[mid-1 : end]可能是sorted，也可能并没有sorted，如下例子。

3 1 2 3 3 3 3 
3 3 3 3 1 2 3

所以当A[mid] = A[end] != target时，无法排除一半的序列，而只能排除掉A[end]：

A[mid] = A[end] != target时：搜寻A[start : end-1]

正因为这个变化，在最坏情况下，算法的复杂度退化成了O(n)：
序列 2 2 2 2 2 2 2 中寻找target = 1。
*/

class Solution {
public:
    bool search(int A[], int n, int target) {
        int start = 0, end = n-1;
        while(start<=end) {
            int mid = start + (end-start)/2;
            if(A[mid]==target) return true;  
       
            if(A[mid]<A[end]) { // right half sorted
                if(target>A[mid] && target<=A[end])
                    start = mid+1;
                else
                    end = mid-1;
            }
            else if(A[mid]>A[end]) {  // left half sorted
                if(target>=A[start] && target<A[mid]) 
                    end = mid-1;
                else
                    start = mid+1;
            }
            else {
                end--;
            }
        }
        return false;
    }        
};

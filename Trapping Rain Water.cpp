class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        if(n<=2) return 0;
        int water=0;
        int left=0;
        int right = n-1;
        int leftMax=height[left];
        int rightMax = height[right];
        while(left<right) {
            if(height[left]<height[right]) { 
                left++;
                if(left<=n-1 && height[left]<leftMax) {
                    water += leftMax-height[left]; //use leftMax, instead of height[left]
                                                   //因为 height[left]未必是当前左边最高高度
                                                   //而注水量要由当前左边最高高度决定。
                }
                leftMax = max(leftMax, height[left]); //update leftMax 
            }
            else {
                right--;
                if(right>=0 && height[right]<rightMax) {
                    water += rightMax-height[right];
                }
                rightMax = max(rightMax, height[right]);
            }
                
        }
        return water;
    }
};

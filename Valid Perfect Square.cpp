class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==0 || num==1) return true;
        int left = 0, right = num;
        while(left<=right) {
            long mid = left+(right-left)/2;
            if(mid*mid==num) return true;
            else if(mid*mid<num)
                left = mid+1;
            else
                right = mid-1;
        }
        return false;
    }
};

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==0 || num==1) return true;
        for(int i=0; i<=num/2; i++) {
            if(i*i==num)
                return true;
        }
        return false;
    }
};

//https://www.youtube.com/watch?v=v_wj_mOAlig
class NumArray {
public:
    NumArray(vector<int> nums) {
        bit_arr = vector<int> (nums.size()+1, 0); //start from 1 for binary indx tree
        mNums = vector<int> (nums.size(), 0);
        for(int i=0; i<nums.size(); i++) {
            update(i, nums[i]);
            mNums[i] = nums[i];
        }
        
    }
    
    void update(int i, int val) {      
        int diff = val-mNums[i]; //difference from previous value in nums
        int indx = i+1;
        while(indx<bit_arr.size()) {
            bit_arr[indx] += diff;
            indx += indx&(-indx);
        }
        mNums[i] = val; //need to update also for mutiple change in one position
    }
    
    int sumRange(int i, int j) {
        int indx1 = i+1, indx2 = j+1;
        return range(indx2)-range(indx1-1);
    }
    
    int range(int indx) {
        int rst=0;
        while(indx>0) {
            rst += bit_arr[indx];
            indx -= indx&(-indx);
        }
        return rst;
    }
private:
    vector<int> bit_arr; //binary indx tree
    vector<int> mNums; //save curr val in nums to calculate diff
};

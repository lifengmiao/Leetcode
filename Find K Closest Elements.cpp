//best
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res = arr;
        while (res.size() > k) {
            int first  = 0, last = res.size() - 1;
            if (x - res.front() <= res.back() - x) {
                res.pop_back();
            } else {
                res.erase(res.begin());
            }
        }
        return res;
    }
};

//easy understand
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res = arr;
        while (res.size() > k) {
            int first  = 0, last = res.size() - 1;
            if (x - res.front() <= res.back() - x) {
                res.pop_back();
            } else {
                res.erase(res.begin());
            }
        }
        return res;
    }
};

//self error
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int start = 0;
        int left = 0;
        int right = arr.size()-1;
        
        while(left<=right) {
            int mid = left+(right-left)/2;
            if(arr[mid] == x) 
                start = mid;
            else if(arr[mid]<x) {
                left = mid+1;
            }
            else
                right = mid-1;
        }
        start = left;
        int i=start-1;
        int j = start;
        while(k>0) {
            if(arr[j]-x <= arr[i]-x) {
                res.push_back(arr[j]);
                j++;
            }
            else {
                res.push_back(arr[i]);
                i--;
            }
            k--;
        }
        return res;
    }
};

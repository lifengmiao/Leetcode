/*
general solution using heap
*/
class Solution {
private:
    struct mycompare{
        bool operator()(pair<int, int>& p1, pair<int, int>& p2){
            return p1.first + p1.second < p2.first + p2.second;
        }
    };
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        priority_queue<pair<int,int>, vector<pair<int, int> >, mycompare> pq;
        for(int i = 0; i < min((int)nums1.size(), k); i++){
            for(int j = 0; j < min((int)nums2.size(), k); j++){
                if(pq.size() < k)
                    pq.push(make_pair(nums1[i], nums2[j]));
                else if(nums1[i] + nums2[j] < pq.top().first + pq.top().second){
                    pq.push(make_pair(nums1[i], nums2[j]));
                    pq.pop();
                }
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top());
            pq.pop();
        }
        return res;
    }
};

/*
use solution in
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84551/simple-Java-O(KlogK)-solution-with-explanation
need to save one more value--indx of cur nums2 element

*/
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> rst;
        if(nums1.size()==0 || nums2.size()==0) return rst;
        priority_queue<vector<int>, vector<vector<int>>,  mycompare> pq;
        for(int i=0; i<nums1.size()&&i<k; i++) {
            pq.push(vector<int>{nums1[i], nums2[0], 0});
        }
        while(k>0 && !pq.empty()) {
            vector<int> item = pq.top();
            pq.pop();
            rst.push_back(make_pair(item[0], item[1]));
            k--;
            if(item[2]==nums2.size()-1) continue;
            pq.push(vector<int>{item[0], nums2[item[2]+1], item[2]+1});
        }
        return rst;
    }
    
    struct mycompare{
        bool operator() (vector<int>& p1, vector<int>& p2) {
            return p1[0]+p1[1] > p2[0]+p2[1];
        }
    };
};

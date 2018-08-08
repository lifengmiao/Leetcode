//self Wrong solution : Error case  [[2,100],[3,200],[4,300],[5,500],[5,400],[5,250],[6,370],[6,360],[7,380]]
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        if(envelopes.size()==0||envelopes.size()==1) return envelopes.size();
        int res = 1;
        sort(envelopes.begin(), envelopes.end());
        pair<int, int> cur=envelopes[0];
        for(int i=1; i<envelopes.size(); i++) {
            if(envelopes[i].first>cur.first && envelopes[i].second>cur.second) {
                res++;
                cur= envelopes[i];
            }
                
        }
        return res;
    }
};

//DP
class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int res = 0, n = envelopes.size();
        vector<int> dp(n, 1);
        sort(envelopes.begin(), envelopes.end());
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

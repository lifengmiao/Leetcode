class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> m;
        vector<int> res;
        for(int i=0; i<S.length(); i++) {
            if(!m.count(S[i])) {
                res.push_back(1);
                m[S[i]] = i;
            }
            else {
                int dis = i-m[S[i]];
                int sum = res.back();
                res.pop_back();
                while(dis>sum) {
                    sum += res.back();
                    res.pop_back();
                }
                res.push_back(sum+1); //one more for the new duplicate element
            }
        }
        return res;
    }
};

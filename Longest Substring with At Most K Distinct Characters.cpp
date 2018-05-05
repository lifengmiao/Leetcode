class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.length()<=k) return s.length();
        int maxL = 0;
        int j=0;
        int curC = 0;
        vector<int> hash(256,0);
        for(int i=0; i<s.length(); i++) {
            while(j<s.length()) {
                if(curC==k && hash[s[j]]==0) 
                    break;
                if(hash[s[j]]==0)
                    curC++;
                hash[s[j]]++;
                j++;
            }
            maxL = max(maxL, j-i);
            hash[s[i]]--;
            if(hash[s[i]]==0)
                curC--;
        }
        return maxL;
    }
};

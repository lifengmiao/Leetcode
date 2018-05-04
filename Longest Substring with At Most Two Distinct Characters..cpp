class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if(s.length()<=2) return s.length();
        int maxL = 0;
        int j=0;
        int curC = 0;
        vector<int> hash(256,0);
        for(int i=0; i<s.length(); i++) {
            while(j<s.length()) {
                if(curC==2 && hash[s[j]]==0) //如果current count已经是2,即使有新的element加入也不要增加current cnt，因为如果增加，后面减不掉
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

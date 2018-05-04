public class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length() <= 1) return s.length();
        int max = 1;
        boolean[] hash = new boolean[256];
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            while(j < s.length()){
                if(!hash[s.charAt(j)]){
                    hash[s.charAt(j++)] = true;
                } else {
                    break;
                }
            }
            max = Math.max(max, j - i);
            hash[s.charAt(i)] = false;
        }

        return max;
    }
}

//Self solution
//Two pointer
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mMap(256,-1);
        int n = s.length();
        if(n==0) return 0;
        int maxL = 1;
        int left = 0;
        int right = 0;
        while(left<=right && right<n) {
            if(mMap[s[right]]==-1) {
                mMap[s[right]] = right;
                right++;
            }
            else {
                cout<<right-left<<endl;
                maxL = max(maxL, right-left);
                while(left<=mMap[s[right]]) {
                    mMap[s[left]]==-1;
                    left++;
                }
                mMap[s[right]] = right;
                right ++;
            }
                
        }
        maxL = max(maxL, right-left);
        return maxL;
    }
};

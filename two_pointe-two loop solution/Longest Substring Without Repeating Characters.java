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

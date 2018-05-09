public class Solution {
    public List<String> removeInvalidParentheses(String s) {
        Set<String> set = new HashSet<>();

        int leftCount = 0;
        int rightCount = 0;
        int openCount = 0;

        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == '(') leftCount++;
            if(s.charAt(i) == ')'){
                if(leftCount > 0) leftCount--;
                else rightCount ++;
            }
        }

        dfs(set, s, 0, leftCount, rightCount, openCount, new StringBuilder());

        return new ArrayList<String>(set);
    }

    private void dfs(Set<String> set, String str, int index, int leftCount, 
                     int rightCount, int openCount, StringBuilder sb){
        if(index == str.length() && leftCount == 0 && rightCount == 0 && openCount == 0){
            set.add(sb.toString());
            return;
        }

        if(index == str.length() || leftCount < 0 || rightCount < 0 || openCount < 0) return;

        char chr = str.charAt(index);
        int len = sb.length();

        if(chr == '('){
            // Remove current '('
            dfs(set, str, index + 1, leftCount - 1, rightCount, openCount, sb);
            // Keep current '('
            dfs(set, str, index + 1, leftCount, rightCount, openCount + 1, sb.append(chr));
        } else if(chr == ')'){
            // Remove current ')' 
            dfs(set, str, index + 1, leftCount, rightCount - 1, openCount, sb);
            // Keep current ')'
            dfs(set, str, index + 1, leftCount, rightCount, openCount - 1, sb.append(chr));
        } else {
            // Just keep the character
            dfs(set, str, index + 1, leftCount, rightCount, openCount, sb.append(chr));
        }

        // Back-tracking
        sb.setLength(len);
    }
}

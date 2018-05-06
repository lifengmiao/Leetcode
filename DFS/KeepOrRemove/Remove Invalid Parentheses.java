/*
在所有 DFS 解法中，我最喜欢这个，非常简洁易懂，而且不依赖什么 trick，便于和面试官交流。
先扫一遍原 string ，记录下需要移除的左括号数量和右括号数量，保证最后的解最优；
于是开始 DFS，对于每一个新的字符，我们都有两个选择：'留' 或者 '不留'，就像二叉树的分叉一样，留下了 dfs + backtracking 的空间。
于是当我们针对各种情况进行 dfs 的时候，我们一定可以考虑到所有可能的有效 path，接下来需要定义什么是 “有效 path”
base case 是左右括号和开括号数量都为零，并且 index 读取完了所有字符，则把结果添加进去；
如果在任何时刻，左右括号和开括号的数量为负，我们都可以直接剪枝返回。
这种解法的主要优点是好理解，空间上因为只用了一个 StringBuilder 非常经济，相比 BFS 速度和空间上都优异很多。
*/
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

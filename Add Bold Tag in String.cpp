/*
建一个和字符串s等长的bold布尔型数组，表示如果该字符在单词里面就为true，那么最后我们就可以根据
bold数组的真假值来添加标签了。我们遍历字符串s中的每一个字符，把遍历到的每一个字符当作起始位置，
我们都匹配一遍字典中的所有单词，如果能匹配上，我们就用i + len来更新end，len是当前单词的长度，
end表示字典中的单词在字符串s中结束的位置，那么如果i小于end，bold[i]就要赋值为true了。最后我们
更新完bold数组了，就再遍历一遍字符串s，如果bold[i]为false，直接将s[i]加入结果res中；如果bold[i]为true，
那么我们用while循环来找出所有连续为true的个数，然后在左右两端加上标签，参见代码如下：
*/
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        int n = s.length();
        string rst;
        vector<bool> bold(n, false);
        int end = 0; //end is index of next element
        for(int i=0; i<n; i++) {
            for(string it:dict) {
                int len = it.length();
                if(i+len<=n && s.substr(i,len)==it) {
                    end = max(end, i+len); //end is the maximum extention till now
                }
            }
            bold[i] = end>i;
        }
        for(int i=0; i<n; i++) {
            if(!bold[i]) rst += s[i];
            else {
                int j=i;
                while(j<n && bold[j])
                    j++;
                rst += "<b>" + s.substr(i, j-i) + "</b>";
                i = j-1; //i will add another 1, since it is in for loop
            }
            
        }
        return rst;
    }
};

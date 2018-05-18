/*
Self
*/
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int cnt;
        for(int k=0; k<A.length(); k++) {
            int j=0, i=k;
            cnt = 1;
            while(j<B.length() && A[i]==B[j]) {
                // cout<<A[i]<<i<<j<<endl;
                j++;
                i++;
                if(i==A.length() && j!=B.length()) {
                    i=0;
                    cnt++;
                }
            }
            if(j==B.length()) return cnt;
        }
        return -1;
    }
};
/*
Use find
这道题让我们用字符串B来匹配字符串A，问字符串A需要重复几次，如果无法匹配，则返回-1。
那么B要能成为A的字符串，那么A的长度肯定要大于等于B，所以当A的长度小于B的时候，
我们可以先进行重复A，直到A的长度大于等于B，并且累计次数cnt。那么此时我们用find来找，
看B是否存在A中，如果存在直接返回cnt。如果不存在，我们再加上一个A，再来找，这样可以
处理这种情况A="abc", B="cab"，如果此时还找不到，说明无法匹配，返回-1，参见代码如下：
*/
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int n1 = A.size(), n2 = B.size(), cnt = 1;
        string t = A;
        while (t.size() < n2) {
            t += A;
            ++cnt;
        }
        if (t.find(B) != string::npos) return cnt;
        t += A;
        return (t.find(B) != string::npos) ? cnt + 1 : -1;
    }
};

/*
下面这个方法就比较巧妙了，由史蒂芬大神提出来的，这个方法用了两个变量unweighted和weighted，
非权重和跟权重和，初始化均为0，然后如果nestedList不为空开始循环，先声明一个空数组nextLevel，
遍历nestedList中的元素，如果是数字，则非权重和加上这个数字，如果是数组，就加入nextLevel，
这样遍历完成后，第一层的数字和保存在非权重和unweighted中了，其余元素都存入了nextLevel中，
此时我们将unweighted加到weighted中，将nextLevel赋给nestedList，这样再进入下一层计算，
由于上一层的值还在unweighted中，所以第二层计算完将unweighted加入weighted中时，相当于第一层的数字和被加了两次，
这样就完美的符合要求了，这个思路又巧妙又牛B，大神就是大神啊，参见代码如下：
*/

class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int levelSum = 0, totalSum=0;
        while(!nestedList.empty()) {
            vector<NestedInteger> nextLevel; //用vector代替queue，每层开始新建vector,相当于清空
            for(auto it:nestedList) {
                if(it.isInteger()) {
                    levelSum += it.getInteger();
                }
                else {
                    nextLevel.insert(nextLevel.end(), it.getList().begin(), it.getList().end());
                    //getList本来返回vector<NestedInteger>，这种insert的方法把getList得到的vector中所有elements，放在nextLevel末尾，
                    //而不是直接把getList得到的vector直接放入。所以nextLevel使用vector<NestedList> 而不是vector<vector<NestedList>>
                    //相当于把getList得到的vector拆开了
                }
            }
            totalSum += levelSum;
            nestedList = nextLevel;
        }
        return totalSum;
    }
};


//self solution
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        vector<vector<int>> rst;
        vector<int> list;
        queue<vector<NestedInteger>> mQ;
        for(int i=0; i<nestedList.size(); i++) {
            if(nestedList[i].isInteger()) {
                list.push_back(nestedList[i].getInteger());
            }
            else {
                mQ.push(nestedList[i].getList());
            }
        }
        rst.push_back(list);
        list.clear();
        while(!mQ.empty()) {            
            int currQSize = mQ.size();
            for(int k=0; k<currQSize; k++) {
                vector<NestedInteger> currNest = mQ.front();
                mQ.pop();
                for(int i=0; i<currNest.size(); i++) {
                    if(currNest[i].isInteger()) {
                        list.push_back(currNest[i].getInteger());
                    }
                    else {
                        mQ.push(currNest[i].getList());
                    }
                }
            }
            rst.push_back(list);
            list.clear();
        }
        int weight = 1;
        int sum = 0;
        for(int i=rst.size()-1; i>=0; i--) {
            for(int j=0; j<rst[i].size(); j++) {
                sum += rst[i][j]*weight;
            }
            weight++;
        }
        return sum;
    }
};

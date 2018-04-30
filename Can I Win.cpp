/*
After solving several "Game Playing" questions in leetcode, I find them to be pretty similar. Most of them can be solved using the top-down DP approach, which "brute-forcely" simulates every possible state of the game.

The key part for the top-down dp strategy is that we need to avoid repeatedly solving sub-problems. Instead, we should use some strategy to "remember" the outcome of sub-problems. Then when we see them again, we instantly know their result. By doing this, we can always reduce time complexity from exponential to polynomial.
(EDIT: Thanks for @billbirdh for pointing out the mistake here. For this problem, by applying the memo, we at most compute for every subproblem once, and there are O(2^n) subproblems, so the complexity is O(2^n) after memorization. (Without memo, time complexity should be like O(n!))

For this question, the key part is: what is the state of the game? Intuitively, to uniquely determine the result of any state, we need to know:

The unchosen numbers
The remaining desiredTotal to reach
A second thought reveals that 1) and 2) are actually related because we can always get the 2) by deducting the sum of chosen numbers from original desiredTotal.

Then the problem becomes how to describe the state using 1).

In my solution, I use a boolean array to denote which numbers have been chosen, and then a question comes to mind, if we want to use a Hashmap to remember the outcome of sub-problems, can we just use Map<boolean[], Boolean> ? Obviously we cannot, because the if we use boolean[] as a key, the reference to boolean[] won't reveal the actual content in boolean[].

Since in the problem statement, it says maxChoosableInteger will not be larger than 20, which means the length of our boolean[] array will be less than 20. Then we can use an Integer to represent this boolean[] array. How?

Say the boolean[] is {false, false, true, true, false}, then we can transfer it to an Integer with binary representation as 00110. Since Integer is a perfect choice to be the key of HashMap, then we now can "memorize" the sub-problems using Map<Integer, Boolean>.

The rest part of the solution is just simulating the game process using the top-down dp.
*/


class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum=(1+maxChoosableInteger)*maxChoosableInteger/2; //total sum of all choosable numbers
        if (sum<desiredTotal) return false;
        if(desiredTotal<=0) return true;
        vector<bool> used(maxChoosableInteger+1, false); //one extra to easily represent number
        map<int, bool> mMap; //used to memorize calculated results, the key 'int' is converted from 'used'
        return dfs(desiredTotal, used, mMap);
    }
    
    bool dfs(int remainTotal, vector<bool>& used, map<int, bool>& mMap) {
        if(remainTotal<=0) return false; //the other player already win 
        int key = format(used); //convert binary to int
        if(mMap.find(key)!=mMap.end())
            return mMap[key]; //use memorized calculted result
        for(int i=1; i<used.size(); i++) {
            if(used[i]==false) {
                used[i]=true;
                if(!dfs(remainTotal-i, used, mMap)) { //after pick number i, the other player lose
                    mMap[key] = true;
                    used[i]=false; //since it will return, here need to change used[i] back to 'false'
                    return true;
                }
                used[i]=false;
            }
        }
        mMap[key]=false;
        return false;
    }
    
    int format(vector<bool>& used) {
        int rst=0;
        for(auto it:used) {
            rst<<=1;
            if(it==true)
                rst = rst|1;
        }
        return rst;
    }
};

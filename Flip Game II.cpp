/*
博弈类 DP ~ 天然的记忆化搜素，而且状态因为用 String 可以完全表示，也很好处理。
在 recursion 过程中，因为只能把 "++" 变成 "--"，我们每一步的状态空间和选择会越来越小，而且没有回头路或者环。于是每一步之后，新的状态都是一个更小的子问题。
Optimal Substructure: 如果当前状态下，我的任何 move 可以得到一个对手无法获胜的局面，则我当前局面必胜。所以计算过程就是遍历所有可能 move，top-down 记忆化搜索就好了，循环中间可以直接 early termination.
*/
class Solution {
public:
    bool canWin(string s) {
        if(s.length()==0) return false;
        map<string, bool> hash; //key is current string; value is for curr string first play can win/not
        return memorizedSearch(s, hash);
    }
    
    bool memorizedSearch(string currState, map<string, bool> hash) {
        if(hash.find(currState)!=hash.end()) //hash memorize the calculated results
            return hash[currState];
        bool canWin = false;
        for(int i=0; i<currState.length()-1;i++){
            if(currState[i]=='+' && currState[i+1]=='+') {
                currState[i]='-';
                currState[i+1]='-';
                bool rst = memorizedSearch(currState, hash);
                if(rst==false) {
                    canWin = true;
                    break;
                }
                currState[i]='+';
                currState[i+1]='+';
            }
        }
        hash[currState] = canWin;
        return canWin;
    }
};

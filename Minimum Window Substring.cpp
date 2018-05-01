/*
https://leetcode.com/problems/minimum-window-substring/discuss/26808/Here-is-a-10-line-template-that-can-solve-most-'substring'-problems
*/
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0); //number of each char in  current substr, use minus number for convinient
        for(auto c: t) map[c]++; //initialize for number of chars needed in t
        int counter=t.size(); 
        int begin=0, end=0, dMin=INT_MAX, head=0;
        for(int end = 0; end<s.size(); end++) {
            if(map[s[end]]>0) 
                counter--; //find a good element
            map[s[end]]--; //no matter needed or not, cnt--, minus values means more such element in substr than needed
            while(counter==0){ //valid substr contain all needed chars
                if(end-begin+1<dMin) {
                    dMin=end-begin+1;
                    head = begin; //save head of substr with min distance
                }
                if(map[s[begin]]==0) //this char has excactly the number needed, if remove it, the result substr is not vailid anymore
                    counter++;  //the result substr is not vailid and need one more char
                map[s[begin]]++; //update number of this char in current substr
                begin++;
            }  
        }
        return dMin==INT_MAX? "":s.substr(head, dMin);
    }
};

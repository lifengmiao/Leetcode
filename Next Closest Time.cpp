class Solution {
public:
    string nextClosestTime(string time) {
        string res = time;
        set<int> s{time[0], time[1], time[3], time[4]}; //remove duplicate and sort
        string str(s.begin(), s.end()); //change back to string instead of using set
        for (int i = res.size() - 1; i >= 0; --i) { //start from lower minues digit
            if (res[i] == ':') continue;
            int pos = str.find(res[i]); //find position of current digit in sorted string
            if (pos == str.size() - 1) { //largest digit need to go back to smallest digit
                res[i] = str[0];
            } else {
                char next = str[pos + 1]; //next digit in sorted string
                if (i == 4) { //lower minues digit
                    res[i] = next;
                    return res;
                } else if (i == 3 && next <= '5') { //higher minues digit
                    res[i] = next;
                    return res; 
                } else if (i == 1 && (res[0] != '2' || (res[0] == '2' && next <= '3'))) { //lower hour digit
                    res[i] = next;
                    return res;
                } else if (i == 0 && next <= '2') { //higher hour digit
                    res[i] = next;
                    return res;
                }
                res[i] = str[0]; //out of boundary go back to smallest
            }
        }
        return res;
    }
};

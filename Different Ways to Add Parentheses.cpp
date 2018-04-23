class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int n= input.length();
        vector<int> rst;
        for(int i=0;i<n;i++) {
            if(input[i]=='+'||input[i]=='-'||input[i]=='*') {
                char op = input[i];
                vector<int> left = diffWaysToCompute(input.substr(0,i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for(auto it1:left) {
                    for(auto it2:right) {
                        if(op == '+') rst.push_back(it1 + it2);
                        if(op == '-') rst.push_back(it1 - it2);
                        if(op == '*') rst.push_back(it1 * it2);
                    }
                }
            }
        }
        if(rst.size()==0) 
            rst.push_back(stoi(input));
        return rst;
            
    }
};

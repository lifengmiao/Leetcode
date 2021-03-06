/*
https://mnmunknown.gitbooks.io/algorithm-notes/content/kuo_hao_ff0c_shu_zhi_ff0c_yu_ji_suan_qi.html
计算器类问题，离不开 Dijkstra 的 Shunting-yard algorithm 和 reverse polish notation.
*/
class Solution {
public:
    int calculate(string s) {
        return solveRPN(getRPN(s));
    }
    
    int getPrecedence(char chr) {
        if(chr=='*'||chr=='/') return 3;
        if(chr=='+'||chr=='-') return 2;
        return 0;
    }
    
    string getRPN(string s) {
        string res="";
        stack<char> ss;
        for(int i=0; i<s.length(); i++) {
            if(s[i]==' ') continue;
            if(s[i]>='0' && s[i]<='9') {
                res += s[i];
            }
            else {
                res += ' ';
                if(s[i]=='(') 
                    ss.push(s[i]);
                else if(s[i]==')') {
                    while(!ss.empty() && ss.top()!='(') {
                        res += ss.top();
                        res += ' ';
                        ss.pop();
                    }
                    ss.pop(); //pop out '('
                }
                else {
                    while(!ss.empty() && getPrecedence(s[i])<=getPrecedence(ss.top())) {
                        res += ss.top();
                        res += ' ';
                        ss.pop();
                    }
                    ss.push(s[i]);
                }
            }
        }
        while(!ss.empty()) {
            res += ' ';
            res += ss.top();
            ss.pop();
        }
        return res;
    }
    
    int solveRPN (string s) {
        istringstream in(s);
        string cur;
        stack<int> stack_num;
        while(in>>cur) {
            if(cur!="+" && cur!="-" && cur!="*" && cur!="/") {
                stack_num.push(stoi(cur));
            }
            else {
                int num2 = stack_num.top();stack_num.pop();
                int num1 = stack_num.top();stack_num.pop();
                if(cur=="+")
                    stack_num.push(num2+num1);
                if(cur=="-")
                    stack_num.push(num1-num2);
                if(cur=="*")
                    stack_num.push(num2*num1);
                if(cur=="/")
                    stack_num.push(num1/num2);
            }
        }
        int out = stack_num.top();
        stack_num.pop();
        return out;
            
    }
};

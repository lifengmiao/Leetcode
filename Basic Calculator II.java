/*
https://mnmunknown.gitbooks.io/algorithm-notes/content/kuo_hao_ff0c_shu_zhi_ff0c_yu_ji_suan_qi.html
计算器类问题，离不开 Dijkstra 的 Shunting-yard algorithm 和 reverse polish notation.
*/
public class Solution {
    public int calculate(String s) {
        return evalRPN(getRPN(s));
    }

    private String getRPN(String s){
        StringBuilder sb = new StringBuilder();
        Stack<Character> stack = new Stack<>();

        for(int i = 0; i < s.length(); i++){
            char chr = s.charAt(i);
            if(chr == ' ') continue;

            if(Character.isDigit(chr)){
                sb.append(chr);
            } else {
                sb.append(' ');
                if(chr == '('){
                    stack.push(chr);
                } else if(chr == ')'){
                    while(stack.peek() != '('){
                        sb.append(stack.pop());
                        sb.append(' ');
                    }
                    stack.pop();
                } else {
                    while(!stack.isEmpty() && getPrecedence(chr) <= getPrecedence(stack.peek())){
                        sb.append(stack.pop());
                        sb.append(' ');
                    }
                    stack.push(chr);
                }
            }
        }
        while(!stack.isEmpty()){
            sb.append(' ');
            sb.append(stack.pop());
        }
        return sb.toString();
    }

    private int evalRPN(String s){
        String[] strs = s.split(" ");
        Stack<Integer> stack = new Stack<>();

        for(String str : strs){
            if(str.equals("")) continue;
            // Is operator
            if("+-*/".indexOf(str) != -1){
                int num2 = stack.pop();
                int num1 = stack.pop();

                if(str.equals("+")) stack.push(num1 + num2);
                if(str.equals("-")) stack.push(num1 - num2);
                if(str.equals("*")) stack.push(num1 * num2);
                if(str.equals("/")) stack.push(num1 / num2);
            } else {
                stack.push(Integer.parseInt(str));
            }
        }
        return stack.pop();
    }

    private int getPrecedence(char chr){
        if(chr == '*' || chr == '/') return 3;
        if(chr == '+' || chr == '-') return 2;

        return 0;
    }
}

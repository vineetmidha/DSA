// https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/balanced-brackets-3-4fc590c6/description/

import java.util.*;
 
class TestClass {
    public static void main(String args[] ) throws Exception {
        Scanner sc = new Scanner(System.in);
 
        int t = sc.nextInt();
 
        while (t-- > 0){
            String s = sc.next();
 
            System.out.println(solve(s)?"YES":"NO");
        }
    }
 
    static boolean solve(String s){
        Stack<Character> stack = new Stack();
 
        for (int i=0; i<s.length(); i++){
            char bracket = s.charAt(i);
            if (bracket=='(' || bracket=='[' || bracket=='{'){
                stack.push(bracket);
            } else {
                if (stack.empty()){
                    return false;
                }
 
                char openingBracket = stack.pop();
 
                if (openingBracket=='(' && bracket!=')'){
                    return false;
                } else if (openingBracket=='[' && bracket!=']'){
                    return false;
                } else if (openingBracket=='{' && bracket!='}'){
                    return false;
                }
            }
        }
        return stack.empty();
    }
}

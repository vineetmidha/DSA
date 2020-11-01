// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    bool isOperator(string symbol){
        if (symbol.size()>1){
            return false;
        }
        char opr = symbol[0];
        switch (opr){
            case '+':
            case '-':
            case '*':
            case '/': return true;
        }
        return false;
    }
    
    int getResult(char opr, int first, int second){
        int result = 0;
        switch (opr){
            case '+': result = first + second; break;
            case '-': result = first - second; break;
            case '*': result = first * second; break;
            case '/': result = first / second; break;
        }
        return result;
        
    }
    int evalRPN(vector<string>& tokens) {
        if (tokens.size()==1) return stoi(tokens[0]);
        
        stack<int> s;
        int result = 0;
        
        for (int i=0; i<tokens.size(); i++){
            if (!isOperator(tokens[i])){
                int n = stoi(tokens[i]);
                s.push(n);
            } else {
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                result = getResult(tokens[i][0], first, second);
                s.push(result);
            }
        }
        
        return result;
    }
};


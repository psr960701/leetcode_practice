// 后缀表达式
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int num1,num2;
        for(int i=0;i<tokens.size();i++)
        {
            if ((tokens[i]=="+")||(tokens[i]=="-")||(tokens[i]=="*")||(tokens[i]=="/"))
            {
                num2=s.top();
                s.pop();
                num1=s.top();
                s.pop();
                if (tokens[i]=="+")
                {
                    s.push(num1+num2);
                }
                if (tokens[i]=="*")
                {
                    s.push(num1*num2);
                }
                if (tokens[i]=="-")
                {
                    s.push(num1-num2);
                }
                if (tokens[i]=="/")
                {
                    s.push(num1/num2);
                }
            } 
            else 
            {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};
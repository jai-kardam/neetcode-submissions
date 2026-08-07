class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int>stk;
      for(string t:tokens){
        if(!(t=="*" || t=="+"|| t=="-" || t=="/"))stk.push(stoi(t));
        if(t=="+"){
            int a=stk.top();
            stk.pop();
            int b=stk.top();
            stk.pop();
            stk.push(a+b);

        }
        if(t=="-"){
          int a=stk.top();
            stk.pop();
            int b=stk.top();
            stk.pop();
            stk.push(b-a);  
        }
        if(t=="*"){
            int a=stk.top();
            stk.pop();
            int b=stk.top();
            stk.pop();
            stk.push(a*b);
        }
        if(t=="/"){
            int a=stk.top();
            stk.pop();
            int b=stk.top();
            stk.pop();
            stk.push(b/a);
        }

      }  
    return stk.top();}
};

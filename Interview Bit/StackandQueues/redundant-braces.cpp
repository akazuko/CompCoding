int Solution::braces(string A) {
    stack<char> br;
    stack<char> op;
    bool opt = true;
    for(char i : A){
        if(i=='('){
          br.push(i);
          opt = false;
        } 
        else if(i=='+'||i=='-'||i=='*'||i=='/') {
            op.push(i);
            opt = true;
        }
        else if(i==')'){
            if(op.empty()) return 1;
            else{
                if(!opt) return 1;
                br.pop();
                op.pop();
            }
        }
    }
    return 0;
}
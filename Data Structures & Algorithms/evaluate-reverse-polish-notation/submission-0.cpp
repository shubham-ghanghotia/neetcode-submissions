class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(int i = 0; i < tokens.size(); i++){
            string tkn = tokens[i];
            if(
                (tkn != "+" ) &&
                (tkn != "-" ) &&
                (tkn != "*" ) &&
                (tkn != "/" ) ){
                    st.push(stoi(tkn));
                } else {
                    int second = st.top(); st.pop();
                    int first = st.top(); st.pop();

                    int result = 0;
                    if(tkn == "+") {
                        result = second + first;
                    } else if(tkn == "-"){
                        result = first - second;
                    } else if(tkn == "*") {
                        result = second * first;
                    } else {
                        result = first / second;
                    }

                    st.push(result);
                }
        }

        return st.top();
    }
};

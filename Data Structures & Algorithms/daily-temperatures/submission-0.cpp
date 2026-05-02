class Solution {
public:
    // Brute force approach
    // TC : O(n^2)
    // SC : O(1)
    // vector<int> dailyTemperatures(vector<int>& temperatures) {
    //     int m = temperatures.size();
    //     vector<int> result(m, 0);
    //     for(int i = 0; i < m; i++ ){
    //         int today = temperatures[i];
    //         for(int j = i + 1; j < m; j++){
    //             int nextD = temperatures[j];
    //             if(nextD > today){
    //                 result[i] = (j - i);
    //                 break;
    //             }
    //         }
    //     }
    //     return result;
    // }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int m = temperatures.size();
        vector<int> result(m, 0);
        
        stack<int> st;

        st.push(0);

        for(int i = 1; i < m; i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i] ){
                result[st.top()] = (i - st.top());
                st.pop();
            }
            st.push(i);
        }

        return result;
    }
};

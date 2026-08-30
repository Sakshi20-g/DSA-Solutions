class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.length();i++){
            if(st.empty() || s[i]!=st.top()) st.push(s[i]);
            else st.pop();
        }
        s = "";
        while(st.size()>0){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return s;
    }
};
int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        stack<int>st;
        string s;
        cin>>s;
        int num=1;
        int l=s.length();
        for(int i=0;i<l+1;i++){
            st.push(num++);
            if(l==i || s[i]=='I'){
                while(!st.empty()){
                    cout<<st.top();
                    st.pop();
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}


/*
 * Given a pattern containing only I's and D's. I for increasing and D for decreasing.
Devise an algorithm to print the minimum number following that pattern.
Digits from 1-9 and digits can't repeat.
Input
5
D
I
DD
IIDDD
DDIDDIID

Output
21
12
321
126543
321654798
*/

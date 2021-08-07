#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string s; cin >> s;

    stack<char> st;
    int ans = 0, temp = 1;
    bool isRight = true; 
    for (int i=0; i<s.length(); i++) {
        char c = s[i];
        
        if (c == '(') { temp *= 2; st.push('('); }
        
        if (c == '[') { temp *= 3; st.push('['); }
        
        if (c == ')') {
            
            if (st.empty() || st.top() != '(') {
                isRight = false;
                break;
            }
            temp /= 2;
            if (i > 0 && s[i-1] == '(') {
                ans += temp * 2;
            }
            st.pop();
        }
        
        if (c == ']') {
            if (st.empty() || st.top() != '[') {
                isRight = false;
                break;
            }
            temp /= 3;
            if (i > 0 && s[i-1] == '[') {
                ans += temp * 3;
            }
            st.pop();
        }
    }
    if (not(st.empty())) {
        isRight = false;
    }

    cout << ((isRight) ? ans : 0) << endl;
}

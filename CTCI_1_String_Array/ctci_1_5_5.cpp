// to_string() is only supported in c++ 11, need to update the compiler
#include <iostream>
#include <string>
using namespace std;

string compressed(string s) {
    string ans;
    char last = s.at(0);
    int count = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s.at(i) == last) {
            count++;
        }
        else {
            ans += last + to_string(count);
            last = s.at(i);
            count = 1;
        }
    }
    // important to get the last char in the string
    ans += last + to_string(count);
    if (ans.length() >= s.length()) {
        return s;
    }
    return ans;
}

int main() {
    string s1 = "abcd";
    string s2 = "aaabbb";
    cout<<compressed(s1)<<' '<<compressed(s2)<<endl;   
    return 0;
}
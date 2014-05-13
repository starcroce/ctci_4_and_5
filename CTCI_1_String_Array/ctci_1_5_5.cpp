#include <iostream>
#include <string>
using namespace std;

string compress(string s)
{
    char last = s[0];
    int count = 1;
    string res = "";
    for(int i = 1; i < s.size(); i++)
    {
        if(s[i] == last)
        {
            count++;
        }
        else
        {
            res += last;
            res += (char)('0' + count);;
            last = s[i];
            count = 1;
        }
    }
    res += last;
    res += (char)('0' + count);
    if(res.size() >= s.size())
        return s;
    return res;
}

int main(int argc, char const *argv[])
{
    string s1 = "qqqwww";
    string s2 = "abcd";
    cout<<compress(s1)<<" "<<compress(s2)<<endl;
    return 0;
}
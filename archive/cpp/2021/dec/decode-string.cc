#include <string>

using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        int i = 0;
        return _decode(s, i);
    }

    string _decode(const string &s, int &i)
    {
        string res;

        while (i < s.size() && s[i] != ']')
        {
            if (!isdigit(s[i]))
            {
                res += s[i++];
            }
            else
            {
                int n = 0;
                while (i < s.size() && isdigit(s[i]))
                {
                    n = n * 10 + s[i++] - '0';
                }
                i++; // [
                string t = _decode(s, i);
                i++; // ]

                while (n-- > 0)
                {
                    res += t;
                }
            }
        }
        return res;
    }
};
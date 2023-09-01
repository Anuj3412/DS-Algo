#include<bits/stdc++.h>
using namespace std;





int32_t main()
{
    // init_code();
    int t;
    cin >> t;
    string ans = "MAYBE";
    while (t--)
    {
        int s, o, n;
        cin >> s >> o >> n;
        string str;
        cin >> str;
        int read = o;
        int readmax = o;
        int readmin = o;
        int i = 0;
        while (i < str.length())
        {

            if (str[i] == '+')
            {
                read++;
                readmax++;
                if (readmax > s){
                    ans = "YES";
                    break;
                }
            }
            else if (str[i] == '-')
            {
                read--;
                readmin--;
            }
            i++;
        }
        if (readmax < s)
        {
            ans = "NO";
        }
        else if(readmax==s){
            ans = "MAYBE";
        }
        cout << ans << "\n";
    }
    return 0;
}

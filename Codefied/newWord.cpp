#include <iostream>

using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    if ((n * 25) < k)
    {
        cout << "-1";
        return 0;
    }
    string str = "";
    for (int i = 0; i < n; i++)
    {
        if (k > 0)
        {
            int gap=0;
            if (k < (122 - (int) s.at(i)))
            {
                str = str +(char)(((int) s.at(i))+k) ;
                k=0;
            }
            else
            {
                gap = 122 - ((int) s.at(i));
                str = str + char(gap +'a');
            }
            k -= gap;
        } else {
            str += s.at(i);
        }
    }
    cout << str;
}
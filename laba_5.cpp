#include <iostream>
#include <string>
using namespace std;

string compress_string(string& str) {
    size_t strs;
    char s;
    int s1, s2, n, m, i;
    string out = "";
    while (true) {
        strs = str.size();
        s = str[0];
        n = m = 1;
        for (i = 1; i < strs; ++i) {
            if (str[i] == str[i - 1]) {
                ++n;
            }
            else {
                if (n >= m) {
                    s = str[i - 1];
                    m = n;
                    s2 = i - 1;
                    s1 = s2 - m + 1;
                }
                n = 1;
            }
        }
        if (n >= m) {
            s = str[strs - 1];
            m = n;
            s2 = i - 1;
            s1 = s2 - m + 1;
        }
        if (m == 1) {
            out += str;
            break;
        }
        cout << "max_char: " << s << "\t" << "length: " << m << "\t" << "range: " << s1 << " -- " << s2 << endl;
        
        out += to_string(s1) + ", " + to_string(m) + s + "; ";

        string str_new = "";
        for (i = 0; i < strs; ++i) {
            if (i < s1 || i > s2)
                str_new += str[i];
        }
        str = str_new;
    }
    return out;
}

int main()
{
    setlocale(LC_ALL, "ru");
    string str;
    cout << "Разложить строку: ";
    cin >> str;
    cout << compress_string(str) << endl;
}
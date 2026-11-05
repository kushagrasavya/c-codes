#include <iostream>
#include <string>

using namespace std;

void LPS(const string &pattern, int *lps) {
    int n = pattern.size();
    int len = 0;  

    lps[0] = 0; 

    int i = 1;
    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMP(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();

    int *lps = new int[m];
    LPS(pattern, lps);

    int i = 0;  
    int j = 0;  

    while (i < n) {
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    delete[] lps;
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";
    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "pattern found at index: " << endl;
    KMP(text, pattern);
    return 0;
}

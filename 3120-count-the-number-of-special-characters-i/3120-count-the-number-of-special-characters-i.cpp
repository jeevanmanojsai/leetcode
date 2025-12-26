class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool lower[26] = {false};
        bool upper[26] = {false};

        for (char c : word) {
            if (islower(c)) lower[c - 'a'] = true;
            else if (isupper(c)) upper[c - 'A'] = true;
        }

        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] && upper[i]) res++;
        }

        return res;
    }
};
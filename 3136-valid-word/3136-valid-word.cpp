class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false; // must have at least 3 chars
        
        int v = 0, c = 0;
        for (char ch : word) {
            if (!isalnum(ch)) return false; // only letters and digits allowed

            if (isalpha(ch)) {
                char lower = tolower(ch);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                    v++;
                else
                    c++;
            }
        }
        return v > 0 && c > 0; // needs at least one vowel and one consonant
    }
};

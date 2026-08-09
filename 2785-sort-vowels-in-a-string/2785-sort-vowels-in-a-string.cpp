class Solution {
public:
    bool isVowel (char c) {
        if (
            c == 'A' ||
            c == 'E' ||
            c == 'I' ||
            c == 'O' ||
            c == 'U' ||
            c == 'a' ||
            c == 'e' ||
            c == 'i' ||
            c == 'o' ||
            c == 'u'
        ) return true;

        return false;
    }

    string sortVowels(string s) {
        string vowels = "";

        for (char c : s){
            if (isVowel(c)) {
                vowels += c;
            }
        }

        sort(vowels.begin(), vowels.end());

        int i = 0;
        int j = 0;
    
        while (i < s.size()){
            if (isVowel(s[i])) {
                swap (s[i], vowels[j++]);
            }
            i++;
        }

        return s;
    }
};
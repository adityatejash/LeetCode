class Solution {
    public boolean isVowel (Character c) {
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

    public String sortVowels(String s) {
        String vowels = "";

        for (int i=0; i<s.length(); i++){
            if (isVowel (s.charAt(i))) {
                vowels += s.charAt(i);
            }
        }

        char[] v = vowels.toCharArray();
        Arrays.sort(v);

        char[] arr = s.toCharArray();

        int i=0;
        int j=0;

        while (i < arr.length) {
            if (isVowel(arr[i])) {
                arr[i] = v[j++];
            }
            i++;
        }

        return new String(arr);

    }
}
class Solution {
   public: bool halvesAreAlike(string s) {
      int count1 = 0, count2 = 0;
      int mid = size(s) / 2;
      for (int i = 0; i < mid; i++) {
         if (isVowel(s[i]))
            count1++;
         if (isVowel(s[i + mid]))
            count2++;
      }
      if (count1 == count2)
         return true;
      else return false;

   }
   bool isVowel(char & c) {
      return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
   }
};
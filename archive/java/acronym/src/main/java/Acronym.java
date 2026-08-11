import static java.lang.Character.*;

class Acronym {
   private final String acronym;

   Acronym(String phrase) {
      this.acronym = toAcronym(phrase);
   }

// private methods:
   private static boolean isPunctuation(char letter) {
      return !isLetter(letter) && letter != '\'';
   }

   private static boolean isTitle(char last, char current) {
      return !isUpperCase(last) && isUpperCase(current);
   }

   private static String toAcronym(String phrase) {
      final char[] letters = phrase.toCharArray();
      StringBuilder acronym = new StringBuilder();
      char last = '\0';
      
      for (char letter: letters) {
         if (isPunctuation(last) && isLetter(letter) 
         || isTitle(last, letter)) {
            acronym.append(toUpperCase(letter));
         }
         
         last = letter;
      }
      
      return acronym.toString();
   }

// getters:
   public String get() {
      return acronym;
   }
}

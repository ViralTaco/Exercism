public class Scrabble {
   private int score;

   
// constructors:
   public Scrabble(String word) {
      if (word != null && !word.isEmpty()) {
         this.score = makeScore(word.toLowerCase());
      } else {
         this.score = 0;
      }
   }

// private methods:
   private int makeScore(String word) {
      return word.chars().map(letter -> this.letterScore(letter)).sum();
   }
   
   private int letterScore(int letter) {
      switch (letter) {
      case 'a': case 'i': 
      case 'u': case 'l':
      case 'n': case 'o': 
      case 'r': case 'e': 
      case 's': case 't':
         return 1;
      case 'd': case 'g':
         return 2;
      case 'b': case 'c': 
      case 'm': case 'p':
         return 3;
      case 'f': case 'h': 
      case 'v': case 'w': 
      case 'y':
         return 4;
      case 'k':
         return 5;
      case 'j': case 'x':
         return 8;
      case 'q': case 'z':
         return 10;
      default:
         return 0;
      }
   }
   
// getters:
   public int getScore() {
      return this.score;
   }

}

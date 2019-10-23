public class IsogramChecker {

/**
  * This method takes in a String `phrase`
  * and determines if `phrase` is an isogram.
  * An isogram is a word or phrase without a repeating letter.
  * @param `phrase` a string
  * @return true if `phrase` is an isogram or empty/null
  * else it returns false
  */
  public static boolean isIsogram(String phrase) 
  { // based on Cismoski's solution
    // https://exercism.io/tracks/java/exercises/isogram/solutions/6afec98114b14394894f98783ee262b4
    phrase = phrase.toLowerCase().replaceAll("[^a-z]", "");
    
    return phrase == null 
        || phrase.isEmpty() 
        || phrase.chars()
                 .distinct()
                 .count() == phrase.length()
    ;
  }

}

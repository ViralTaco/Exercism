public class IsogramChecker {
/**
 * This method takes in a String `phrase`
 * and determines if `phrase` is an isogram.
 * An isogram is a word or phrase without a repeating letter.
 * @param `phrase` a string
 * @return true if `phrase` is an isogram, empty, or null.
 */
  public static boolean isIsogram(String phrase) { 
    if (phrase == null || phrase.isEmpty())
      return true;
    
    phrase = phrase.toLowerCase().replaceAll("[^a-z]", "");
    return phrase.chars().distinct().count() == phrase.length();
  }
}

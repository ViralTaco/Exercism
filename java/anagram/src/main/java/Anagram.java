import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Anagram {
  private int length;
  private String word;
  private char[] letters;
  
  
  /**
   * This constructor takes in a string `word`
   * assigns it's length to `this.length`
   * copies `word` in lowercase in `this.word`
   * makes a char array `this.letters` from `this.word`
   * finally it sorts `this.letters`
   * @param word The word we're trying to find anagrams of.
   * @return an instance of Anagram. 
   * @exception IllegalArgumentException on null param.
   */
  public Anagram(String word) throws IllegalArgumentException
  {
    if (word == null)
      throw new IllegalArgumentException("No word given to Anagram ctor");
    
    this.length = word.length();
    
    this.word = word.toLowerCase();
    this.letters = this.word.toCharArray();
    
    Arrays.sort(this.letters);
  }
  /**
   * This method takes a List<String> of words
   * creates an ArrayList<String> `matches`
   * for each string `s` in the list 
   * if the length of `s` is the same as `this.length`
   * and `s` doesn't match `this.word` (ignoring case)
   * creates a char array `temp` from `s` in lowercase
   * sorts `temp` 
   * if `temp` is equal to `this.letters` it adds `s` to `matches`
   * finally it return matches.
   * @param words A List<String> of words
   * @return `matches` a List<String> containing all the anagrams 
   * of `this.word` that were found in param `words`
   */
  public List<String> match(List<String> words)
  {
    ArrayList<String> matches = new ArrayList<String>();
    
    for (String s: words) {
      if (s.length() == this.length 
      && !(s.equalsIgnoreCase(this.word))) {
        
        char[] temp = s.toLowerCase().toCharArray();
        Arrays.sort(temp);
        
        if (Arrays.equals(this.letters, temp)) matches.add(s);
      }
    }
    return matches;
  }

} // public class Anagram
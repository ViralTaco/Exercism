public class Twofer {
  
  /**
   * This method takes in a String `name`
   * and returns "One for `name`, one for me."
   * if no `name` is given it is replaced by "you"
   * @param name a String
   * @return a formated String "One for `name`, one for me."
   */
  public String twofer(String name)
  {
    return String.format("One for %s, one for me."
    , (name == null || name.isEmpty()) ? "you" : name
    );
  }
}

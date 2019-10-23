public class RaindropConverter {
  /**
   * This method takes in an int `number`
   * If the number is divisible by 3: specifier "Pling"
   * If the number is divisible by 5: specifier "Plang"
   * If the number is divisible by 7: specifier "Plong"
   * @param number an integer 
   * @return a String containing the factors of `number`
   * using a concatenation of the afforementioned specifiers
   * or the number as a string
   */
  public static String convert(int number) 
  {
    StringBuilder builder = new StringBuilder();
    
    if (number % 3 == 0) builder.append("Pling");
    if (number % 5 == 0) builder.append("Plang");
    if (number % 7 == 0) builder.append("Plong");
    
    return (builder.length() == 0) 
         ? Integer.toString(number)
         : builder.toString()
    ;
  }

}

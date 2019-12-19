public class RaindropConverter {
/**
 * This method takes in an Integer `number`
 * If `number` is divisible by 3: specifier "Pling"
 * If `number` is divisible by 5: specifier "Plang"
 * If `number` is divisible by 7: specifier "Plong"
 * @param number an integer 
 * @return a String containing the factors of `number`
 * using a concatenation of the afforementioned specifiers
 * or the number as a string
 */
  public static String convert(Integer number) {
    StringBuilder builder = new StringBuilder();
    
    if (number % 3 == 0) builder.append("Pling");
    if (number % 5 == 0) builder.append("Plang");
    if (number % 7 == 0) builder.append("Plong");
    
    return (builder.length() == 0) ? number.toString() : builder.toString();
  }

}

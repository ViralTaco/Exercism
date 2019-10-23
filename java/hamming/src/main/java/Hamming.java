public class Hamming {
  private final int hammingDistance;
  
  public Hamming(String left, String right) throws IllegalArgumentException
  {
    if (left.length() == right.length()) {
      this.hammingDistance = difference(left.toCharArray(), right.toCharArray());
    } else if (left == null || left.isEmpty()) {
      throw new IllegalArgumentException("left strand must not be empty.");
    } else if (right == null || right.isEmpty()) {
      throw new IllegalArgumentException("right strand must not be empty.");
    } else {
      throw new IllegalArgumentException(
        "leftStrand and rightStrand must be of equal length."
      );
    }
  }
  
  private int difference(char[] left, char[] right)
  {
    int dissimilarities = 0;
    
    for (int i = 0; i < left.length; ++i) {
      if (left[i] != right[i]) dissimilarities += 1;
    }
    
    return dissimilarities;
  }
  
  public int getHammingDistance() 
  { 
    return this.hammingDistance; 
  }

} // public class Hamming

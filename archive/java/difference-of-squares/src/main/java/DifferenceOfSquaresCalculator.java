class DifferenceOfSquaresCalculator {
// private methods:
   private int squareOfSum(int x) {
      final int root = (x * (x + 1)) / 2;
      return root * root;
   }
   
   private int sumOfSquare(int x) { // O(1)
      return (x * (x + 1) * (2 * x + 1)) / 6; 
   }
   
// public methods:
   public int computeSquareOfSumTo(int x) {
      return squareOfSum(x);
   }

   public int computeSumOfSquaresTo(int x) {
      return sumOfSquare(x);
   }

   public int computeDifferenceOfSquares(int x) {
      return (int) Math.abs(sumOfSquare(x) - squareOfSum(x));
   }

}

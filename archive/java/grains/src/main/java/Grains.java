import java.math.BigInteger;

public class Grains {
   private static final BigInteger 
      TWO_POW_SIXTY_FOUR = new BigInteger("18446744073709551615"); 
   private static final String 
      SQUARE_OUT_OF_RANGE = "square must be between 1 and 64";

// private methods:
   private static BigInteger onSquare(final int square) {
      if (square < 1 || square > 64) 
         throw new IllegalArgumentException(SQUARE_OUT_OF_RANGE);

      return BigInteger.ONE.shiftLeft(square - 1);
   }
   
   private static BigInteger onBoard() {
      return TWO_POW_SIXTY_FOUR;
   }
   
// absoluteTrashNameAbstractGetterFactoryBullshitGitGud:
   public static BigInteger computeNumberOfGrainsOnSquare(final int square) {
      return Grains.onSquare(square);
   }

   public static BigInteger computeTotalNumberOfGrainsOnBoard() {
      // "total number" as opposed to half the number. Jesus Christ
      return Grains.onBoard();
   }

}

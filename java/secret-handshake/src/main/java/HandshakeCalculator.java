import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

class HandshakeCalculator {
   private final int REVERSE = 0b0001_0000;

   public List<Signal> calculateHandshake(int number) {
      List<Signal> list = new ArrayList<Signal>();
      
      for (Signal signal: Signal.values()) {
         if ((number & signal.value) != 0) {
            list.add(signal);
         }
      }
      
      if ((number & REVERSE) != 0) {
         Collections.reverse(list);
      }
      
      return list;
   }

}

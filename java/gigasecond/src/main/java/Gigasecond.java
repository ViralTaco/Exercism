import java.time.*;

public class Gigasecond {
   private LocalDateTime birthDateTime;
   
// constructors:    
   public Gigasecond(LocalDateTime birthDateTime) {
      this.birthDateTime = birthDateTime.plusSeconds((long) 1E9);
   }
   
   public Gigasecond(LocalDate birthDate) {
      this(LocalDateTime.of(birthDate, LocalTime.MIN));
   }

// getters:
   public LocalDateTime getDateTime() {
      return this.birthDateTime;
   }
}

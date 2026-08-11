
struct Raindrops {
  var sounds: String = ""
  
  init(_ number: Int) 
  {
    if number % 3 == 0 {
      sounds += "Pling"
    }
    
    if number % 5 == 0 {
      sounds += "Plang"
    }
    
    if number % 7 == 0 {
      sounds += "Plong"
    }
    
    if sounds == "" {
      sounds = String(number)
    }
  }
} // struct Raindrops

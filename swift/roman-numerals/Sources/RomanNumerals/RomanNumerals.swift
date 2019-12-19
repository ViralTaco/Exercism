extension String {
  init(_ numeral: RomanNumeral) {
    self = numeral.description
  }
}

class RomanNumeral: CustomStringConvertible {
  private static let numerals = [
    1000: "M", 900: "CM", 500: "D", 400: "CD"
  , 100:  "C", 90:  "XC", 50:  "L", 40:  "XL"
  , 10:   "X", 9:   "IX", 5:   "V", 4:   "IV"
  , 1:    "I",
  ].sorted(by: >) // To keep descending order
  
  private let number: Int

  var description: String {
    var num = number
    var this = ""
    
    for numeral in RomanNumeral.numerals {
      while num >= numeral.key {
        this += numeral.value
        num -= numeral.key
      }
    }
    
    return this
  }
  
  init(_ number: Int) {
    self.number = number
  }
}

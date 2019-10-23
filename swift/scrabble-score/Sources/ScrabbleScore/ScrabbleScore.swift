struct Scrabble {
  var score = 0
  
  init(_ word: String?) {
    self.score = Scrabble.score(word ?? "")
  }
  
  static func score(_ word: String) -> Int {
    var sum = 0
    
    for c in word.lowercased() {
      sum += Scrabble.letterScore(letter: c)
    }
    
    return sum
  }
  
  static func letterScore(letter: Character) -> Int {
    switch letter {
    case "a", "e", "i", "o", "u", "l", "n", "r", "s", "t":
      return 1
    case "d", "g":
      return 2
    case "b", "c", "m", "p":
      return 3
    case "f", "h", "v", "w", "y":
      return 4
    case "k":
      return 5
    case "j", "x":
      return 8
    case "q", "z":
      return 10
    default:
      return 0
    }
  }
}

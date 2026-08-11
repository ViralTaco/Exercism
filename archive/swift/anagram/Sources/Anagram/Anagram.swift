import Foundation

struct KeyWordPair {
  var sorted: String
  let word: String
  
  init(word: String) {
    self.word = word.lowercased()
    sorted = String(self.word.sorted())
  }

  func equalIsh(other: KeyWordPair) -> Bool {
    return self.word != other.word &&
           self.sorted == other.sorted
  }
  
  func equalIsh(other: String) -> Bool {
    return self.equalIsh(other: KeyWordPair(word: other))
  }
}

class Anagram {
  var hash: KeyWordPair
  let length: Int

  init(word: String) {
    length = word.count
    hash = KeyWordPair(word: word)
  }
  
  func match(_ words: [String]) -> [String] {
    return words.filter {
      $0.count == length && hash.equalIsh(other: $0)
    }
  }
  
}

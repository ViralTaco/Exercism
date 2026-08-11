class WordCount {
  let words: [String]

  init(words: String) {
    self.words =
      words.filter { $0.isLetter || $0.isWhitespace || $0.isNumber }
      .lowercased().split(separator: " ").reduce(into: [String](), {
        array, word in array += [String(word)]
      })
  }

  public func count() -> [String : Int] {
    var map = [String : Int]()

    for word in words {
      if let value = map[word] {
        map.updateValue(value + 1, forKey: word)
      } else {
        map.updateValue(1, forKey: word)
      }
    }

    return map
  }
}

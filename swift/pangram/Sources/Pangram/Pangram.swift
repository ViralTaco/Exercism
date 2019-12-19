enum Pangram {
  static func isPangram(_ phrase: String) -> Bool {
    Set(phrase.lowercased().filter { $0.isLetter && $0.isASCII }).count == 26
  }
}

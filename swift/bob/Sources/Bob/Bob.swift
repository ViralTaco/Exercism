enum Bob {
  private static let actions = (
    Sure: "Sure.",
    Fine: "Fine. Be that way!",
    Chill: "Whoa, chill out!",
    Whatever: "Whatever."
  )

  public static func hey(_ str: String) -> String {
    if isLoud(phrase: str) {
      return actions.Chill
    } else if isQuestion(phrase: str) {
      return actions.Sure
    } else if isSilent(phrase: str) {
      return actions.Fine
    } else {
      return actions.Whatever
    }
  }

  private static func isLoud(phrase: String) -> Bool {
    return phrase.contains(where: { $0.isLetter }) // has letters
        && phrase.uppercased() == phrase           // is all caps
  }

  private static func isQuestion(phrase: String) -> Bool {
    return phrase.hasSuffix("?")
  }

  private static func isSilent(phrase: String) -> Bool {
    return !phrase.contains(where: { $0.isLetter || $0.isNumber })
  }
}


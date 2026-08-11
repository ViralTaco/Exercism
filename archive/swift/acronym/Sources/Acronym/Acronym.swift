import Foundation

struct Acronym {
  static func abbreviate(_ phrase: String) -> String {
    var last: Character = "\0"
    var acronym: String = ""
    for c in phrase {
      if c.isLetter && !last.isLetter
      || (!last.isUppercase && c.isUppercase) {
        acronym.append(c)
      }
      last = c
    }
    return acronym.uppercased()
  }
}

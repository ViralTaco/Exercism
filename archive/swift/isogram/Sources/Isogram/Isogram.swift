import Foundation

struct Isogram {
  public static func isIsogram(_ phrase: String) -> Bool {
    let str = phrase.filter({ $0.isLetter }).lowercased()
    return str.count == Set(str).count
  }
}

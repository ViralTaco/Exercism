
class AtbashCipher {
  static let clear = "abcdefghijklmnopqrstuvwxyz"
  static let atbash = clear.reversed()
  static let mappings = Dictionary(uniqueKeysWithValues: zip(clear, atbash))
  
  public static func encode(_ cleartext: String) -> String {
    var ciphertext: String = ""
    var inserts = 0

    for c in cleartext.lowercased() {
      if c.isLetter {
        ciphertext.append(mappings[c]!)
      } else if c.isNumber {
        ciphertext.append(c)
      } else {
        continue
      }

      inserts += 1

      if inserts.isMultiple(of: 5) {
        ciphertext.append(" ")
      }
    }

    if ciphertext.hasSuffix(" ") {
      _ = ciphertext.popLast()
    }

    return ciphertext
  }
}

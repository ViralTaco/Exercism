class RotationalCipher {
  private static let clear = Array("abcdefghijklmnopqrstuvwxyz")

  public static func rotate(_ cleartext: String, ROT center: Int) -> String {
    var ciphertext: String = ""
    let cipher = clear[center..<26] + clear[0..<center]
    let pairing = Dictionary(uniqueKeysWithValues: zip(clear, cipher))

    for letter in cleartext {
      if !letter.isLetter {
        ciphertext.append(letter)
      } else if letter.isLowercase {
        ciphertext.append(pairing[letter]!)
      } else { // UPPERCASE letter
        let lowercase = letter.lowercased().first!
        let cipherLetter = pairing[lowercase]!
        ciphertext.append(cipherLetter.uppercased())
      }
    }

    return ciphertext
  }
}

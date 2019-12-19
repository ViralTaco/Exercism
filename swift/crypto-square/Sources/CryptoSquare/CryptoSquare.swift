public class Crypto {
  let normalizePlaintext: String
  let size: Int
  let plaintextSegments: [String]

  let ciphertext: String
  let normalizeCiphertext: String

// public constructors:
  init(_ cleartext: String) {
    normalizePlaintext = cleartext.filter{ $0.isLetter || $0.isNumber }
                        .lowercased()

    size = Crypto.measure(length: normalizePlaintext.count)

    plaintextSegments = Crypto.segment(stem: normalizePlaintext, size: size)
    ciphertext = Crypto.encrypt(segment: plaintextSegments, size: size)

    normalizeCiphertext = Crypto.segment(stem: ciphertext, size: size - 1)
                         .joined(separator: " ")
  }

// private methods:
  private static func measure(length: Int) -> Int {
    var size = 0

    while size * size < length {
      size += 1
    }

    return size > 1 ? size : length
  }

  private static func segment(stem: String, size: Int) -> [String] {
    let end = stem.endIndex
    var start = stem.startIndex
    var segments = [String]()

    while start < end {
      let mid = stem.index(start, offsetBy: size, limitedBy: end) ?? end
      segments.append(String(stem[start..<mid]))
      start = mid
    }

    return segments
  }

  private static func encrypt(segment: [String], size: Int) -> String {
    var ciphertext = Array(repeating: "", count: size)

    for row in segment {
      var index = 0
      for col in row {
        ciphertext[index].append(col)
        index += 1
      }
    }

    return ciphertext.joined()
  }
}

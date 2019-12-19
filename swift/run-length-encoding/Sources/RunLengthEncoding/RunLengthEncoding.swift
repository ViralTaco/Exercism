fileprivate extension String {
  func nextIndex(from: String.Index) -> String.Index {
    return self.index(from, offsetBy: 1, limitedBy: self.endIndex)
        ?? self.endIndex
  }
}

struct RunLengthEncoding {
  static func encode(_ text: String) -> String {
    var last: Character = "\0"
    var count = 0
    var encoded = ""

    var start = text.startIndex
    let end = text.endIndex

    while start < end {
      while text[start] == last && !last.isWhitespace {
        count += 1
        last = text[start]
        start = text.nextIndex(from: start)
        if start == end {
          break
        }
      }

      if count != 0 {
        let encodedLast = encoded.last
        if encodedLast == last {
          _ = encoded.popLast()
        }
        encoded.append("\(count + 1)\(last)")
        count = 0
      }

      if start < end {
        encoded.append(text[start])
        last = text[start]
        start = text.nextIndex(from: start)
      }
    }

    return encoded
  }

  static func decode(_ text: String) -> String {
    var decoded = ""
    var amount = ""

    var start = text.startIndex
    let end = text.endIndex

    while start < end {
      while text[start].isNumber {
        amount.append(text[start])
        start = text.nextIndex(from: start)
        if start == end {
          break
        }
      }

      if !amount.isEmpty {
        repeatElement(text[start], count: Int(amount) ?? 0).forEach {
          decoded.append($0)
        }
        amount = ""
      } else {
        decoded.append(text[start])
      }

      start = text.nextIndex(from: start)
    }

    return decoded
  }
}

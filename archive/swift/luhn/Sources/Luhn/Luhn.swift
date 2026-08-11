struct Luhn {
  let isValid: Bool

  init(_ cardNumber: String) {
    let number = cardNumber.filter { $0.isNumber }

    if number.count <= 1
    || cardNumber.contains(where: { !$0.isNumber && !$0.isWhitespace }) {
      isValid = false
      return
    }

    let digits = number.reversed().compactMap { Int(String($0)) }
    var checksum = 0

    for i in 0..<digits.count {
      if (i + 1) % 2 == 0 {
        let num = digits[i] * 2
        checksum += (num > 9) ? num - 9 : num
      } else {
        checksum += digits[i]
      }
    }

    isValid = checksum.isMultiple(of: 10)
  }
}

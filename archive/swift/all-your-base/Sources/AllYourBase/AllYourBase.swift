fileprivate func pow(base: Int, exponent: Int) -> Int {
  if exponent == 0 {
    return 1
  }

  var n = 1
  for _ in 1...exponent {
    n *= base
  }
  return n
}

public enum BaseError: Error {
  case invalidInputBase
  case invalidOutputBase
  case invalidPositiveDigit
  case negativeDigit
}

struct Base {
  private static func
  digits(baseIn: Int, digits: [Int], baseOut: Int) -> [Int] {
    var index = digits.count - 1
    var number = 0
    var outDigits = [Int]()

    for digit in digits {
      number += digit * pow(base: baseIn, exponent: index)
      index -= 1
    }

    while number > 0 {
      outDigits.append(number % baseOut)
      number /= baseOut
    }
    
    return outDigits.reversed()
  }

  public static func
    outputDigits(inputBase: Int, inputDigits: [Int],
                 outputBase: Int) throws -> [Int] {
    if inputBase <= 1 {
      throw BaseError.invalidInputBase
    } else if outputBase <= 1 {
      throw BaseError.invalidOutputBase
    } else if inputDigits.contains(where: { $0 >= inputBase }) {
      throw BaseError.invalidPositiveDigit
    } else if inputDigits.contains(where: { $0 < 0 }) {
      throw BaseError.negativeDigit
    }

    return digits(baseIn: inputBase, digits: inputDigits, baseOut: outputBase)
  }
}

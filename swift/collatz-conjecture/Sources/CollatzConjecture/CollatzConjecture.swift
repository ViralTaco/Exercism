import Foundation

struct CollatzConjecture {
  enum InvalidArgumentError: Error {
    case tooSmall(Int)
  }

  static func steps(_ number: Int) throws -> Int {
    guard number > 0 else {
      throw InvalidArgumentError.tooSmall(number)
    }

    var num = number // mutable copy of `number` argument
    var stepCount = 0
    while num > 1 {
      if num.isMultiple(of: 2) {
        num /= 2
      } else {
        num = (num * 3) + 1
      }

      stepCount += 1
    }

    return stepCount
  }
}


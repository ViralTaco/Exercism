import Foundation

fileprivate extension Int {
  var isPrime: Bool {
    guard self > 3 else {
      return self >= 2 // <= 1: false; 2, 3: true
    }

    let root = Int(Double(self).squareRoot())
    for i in 2...root {
      if self % i == 0 {
        return false
      }
    }
    return true
  }
}

class Prime {
  fileprivate static let smallLimit = 59
  fileprivate static let smallPrimes = [
    nil, 2, 3, 5, 7, 11, 13, 17
  , 19, 23, 29, 31, 37, 41, 43, 47, 53
  , 59, 61, 67, 71, 73, 79, 83, 89, 97
  , 101, 103, 107, 109, 113, 127, 131
  , 137, 139, 149, 151, 157, 163, 167
  , 173, 179, 181, 191, 193, 197, 199
  , 211, 223, 227, 229, 233, 239, 241
  , 251, 257, 263, 269, 271
  ]

  static func nth(_ n: Int) -> Int? {
    guard n > 0 else {
      return nil
    }

    if n < smallLimit {
      return smallPrimes[n]
    }

    var i = n
    var result = 3

    while i > 1 {
      if result.isPrime { i -= 1 }
      result += 2
    }

    return result - 2
  }
}

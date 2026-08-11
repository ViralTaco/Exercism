import Foundation

class NumberClassifier {
  enum Classifications {
    case perfect
    case deficient
    case abundant
  }

  let number: Int

  init(number: Int) {
    self.number = number
  }

  var sumOfFactors: Int {
    var sum: Int = 1
    for x in 2..<number {
      if number.isMultiple(of: x) {
        sum += x
      }
    }
    return sum
  }

  var classification: Classifications {
    switch sumOfFactors {
    case number:
      return .perfect
    case ..<number:
      return .deficient
    default:
      return .abundant
    }
  }
}

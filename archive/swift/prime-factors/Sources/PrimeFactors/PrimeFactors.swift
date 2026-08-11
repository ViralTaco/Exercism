import Foundation

class PrimeFactors {
  public let toArray: [UInt]

  init(_ number: UInt) {
    toArray = PrimeFactors.factorize(number: number)
  }

  static func isPrime(number: UInt) -> Bool {
    let limit = UInt(sqrt(Double(number)))

    if limit < 2 {
      return limit == 1
    }

    for i in 2...limit {
      if number.isMultiple(of: i) {
        return false
      }
    }

    return true
  }

  static func factorize(number: UInt) -> [UInt] {
    var factors = [UInt]()
    var num = number

    while num.isMultiple(of: 2) && num >= 2 {
      num /= 2
      factors += [2]
    }

    var divisor: UInt = 3
    while num > 1 {
      if isPrime(number: divisor) {
        while num % divisor == 0 {
          num /= divisor
          factors += [divisor]
        }
      }
      divisor += 2
    }

    return factors
  }
}

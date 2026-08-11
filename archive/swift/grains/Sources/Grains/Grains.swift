enum Grains {
  enum GrainsError: Error {
    case inputTooHigh(String)
    case inputTooLow(String)

    static func forInput(_ input: Int) -> GrainsError {
      let message = "Input[\(input)] invalid. "
                  + "Input should be between 1 and 64 (inclusive)"

      return input < 1 ? inputTooLow(message) : inputTooHigh(message)
    }
  }

  static let total = UInt64.max

  static func square(_ square: Int) throws -> UInt {
    guard square >= 1 && square <= 64 else {
      throw GrainsError.forInput(square)
    }

    return UInt(1) << (square - 1)
  }
}

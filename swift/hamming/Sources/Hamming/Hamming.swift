enum Hamming {
  static func compute(_ left: String, against right: String) -> Int? {
    guard left.count == right.count else {
      return nil
    }

    return zip(left, right).filter({ $0 != $1 }).count
  }
}

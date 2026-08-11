class Series {
  private let digits: [Int]
  private var size: Int { digits.count }
  
  init(_ number: String) {
    self.digits = number.compactMap { Int(String($0)) }
  }
  
  public func slices(_ length: Int) -> [[Int]] {
    if length == size {
      return [digits]
    } else if length < size && length > 0 {
      var slices = [[Int]]()
      let limit = size - length
      
      for i in 0...limit {
        let end = digits.endIndex - (limit - i)
        slices.append(Array(digits[i..<end]))
      }
      
      return slices
    } else { // invalid size
      return [[Int]]()
    }
  }
}

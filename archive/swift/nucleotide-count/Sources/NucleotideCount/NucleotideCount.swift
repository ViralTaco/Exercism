class DNA {
  var nucleotides = ["T": 0, "A": 0, "C": 0, "G": 0]
  
  init?(strand: String) {
    for c in strand.uppercased() {
      let key = String(c)

      guard nucleotides[key] != nil else {
        return nil
      }
      nucleotides[key]! += 1
    }
  }
  
  public func counts() -> [String: Int] {
    return nucleotides
  }
  
  public func count(_ key: String) -> Int {
    return nucleotides[key]!
  }
}

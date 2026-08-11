fileprivate extension String {
  static func random(length: Int) -> String {
    let base = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    var randomString = ""

    for _ in 0..<length {
      let randomValue = Int.random(in: 0..<base.count)
      let index = base.index(base.startIndex, offsetBy: randomValue)
      randomString += "\(base[index])"
    }
    return randomString
  }
}

struct Robot {
  var name: String
  
  init() {
    self.name = Robot.makeName()
  }
  
  mutating func resetName() -> Void {
    self.name = Robot.makeName()
  }
  
  private static func makeName() -> String {
    var rng = SystemRandomNumberGenerator()
    let num = Int.random(in: 100...999, using: &rng)
    return "\(String.random(length: 2))\(num)"
  }
}

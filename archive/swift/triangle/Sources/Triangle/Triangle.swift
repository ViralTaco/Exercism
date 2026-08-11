import Foundation

class Triangle {
  typealias Side = Double
  var kind: String

  init(_ a: Side, _ b: Side, _ c: Side) {
    if a + b <= c || b + c <= a || a + c <= b
    || a <= 0 || b <= 0 || c <= 0 {
      kind = "ErrorKind"
    } else if a == b && b == c {
      kind = "Equilateral"
    } else if a == b || a == c || b == c {
      kind = "Isosceles"
    } else {
      kind = "Scalene"
    }
  }
}


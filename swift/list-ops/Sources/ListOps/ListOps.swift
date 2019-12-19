import Foundation

struct ListOps {
  static func append<T: Equatable>(_ lhs: [T], _ rhs: [T]) -> [T] {
    return lhs + rhs
  }

  static func concat<T: Equatable>(_ arrays: [T]...) -> [T] {
    var table: [T] = []
    for array in arrays { table += array }
    return table
  }

  static func filter<T: Equatable>(_ array: [T], _ fun: ((T) -> Bool)) -> [T] {
    var table: [T] = []
    for item in array { if fun(item) { table += [item] } }
    return table
  }

}

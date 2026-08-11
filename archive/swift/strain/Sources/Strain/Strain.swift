extension Array {
  func keep(_ predicate: (Element) -> Bool) -> [Element] {
    var result = [Element]()

    for elem in self {
      if predicate(elem) {
        result.append(elem)
      }
    }

    return result
  }

  func discard(_ predicate: (Element) -> Bool) -> [Element] {
    return self.keep { !predicate($0) }
  }
}

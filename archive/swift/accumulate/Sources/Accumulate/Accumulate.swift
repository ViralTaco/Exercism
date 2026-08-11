extension Sequence {
  func accumulate<T>(_ fun: (Element) -> T) -> [T] {
    var collection: [T] = []
    for element in self {
      collection += [fun(element)]
    }
    return collection
  }
}

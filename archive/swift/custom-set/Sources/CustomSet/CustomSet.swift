struct CustomSet<T: Hashable & Comparable> {
  private var data: Set<T>
  
  init(_ data: [T]) {
    self.data = Set(data.sorted())
  }
  
  public static func == (_ lhs: CustomSet<T>, _ rhs: CustomSet<T>) -> Bool {
    return lhs.data == rhs.data
  }
  
  
}

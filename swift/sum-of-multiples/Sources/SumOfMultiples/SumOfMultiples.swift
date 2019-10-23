public func toLimit(_ limit: Int, inMultiples multiples: [Int]) -> Int {
  var multiplesOfEach: Set<Int> = []
  
  for num in multiples where num > 0 && num < limit {
    var i = num
    while i < limit {
      multiplesOfEach.insert(i)
      i += num
    }
  }
  
  return multiplesOfEach.reduce(0, +)
}

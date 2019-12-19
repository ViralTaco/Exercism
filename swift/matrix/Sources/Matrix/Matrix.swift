struct Matrix {
  let columnCount: Int

  var rows: [[Int]] = []
  var columns: [[Int]] {
    Array(0..<columnCount).reduce([[Int]](), {
      (arr, i) in arr + [rows.map { $0[i] }]
    })
  }

  init(_ text: String) {
    rows = text.split(separator: "\n")
      .map { $0.split(separator: " ") }
      .map { $0.compactMap { Int($0) } }

    columnCount = rows[0].count
  }
}

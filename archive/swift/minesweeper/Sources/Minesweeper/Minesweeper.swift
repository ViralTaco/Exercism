class Board {
  var height: Int
  var width: Int
  var board: [[Int]]

  init(_ rowsStr: [String]) {
    let rows = Array(rowsStr).map { Array($0) }
    height = rows.count - 2
    width = rows[0].count - 2

    let inner = Array(repeating: 0, count: width)
    board = Array(repeating: inner, count: height)

    for x in 1...(width + 1) {
      for y in 1...(height + 1) {
        if rows[x][y] == "*" {

        }
      }
    }
  }
}

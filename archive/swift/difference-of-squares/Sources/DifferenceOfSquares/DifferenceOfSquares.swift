import Foundation

class Squares {
  let number: Int
  
  init(_ num: Int) {
    number = num
  }
  
  var squareOfSum: Int {
    var sum = number
    
    for i in 1..<number {
      sum += i
    }
    return sum * sum
  }
  
  var sumOfSquares: Int {
    var sum = number * number
    
    for i in 1..<number {
      sum += i * i
    }
    return sum
  }
  
  var differenceOfSquares: Int {
    return squareOfSum - sumOfSquares
  }

}

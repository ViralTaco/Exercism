enum BracketPush {
  static func paired(text: String) -> Bool {
    var symbols = ""
    
    for char in text {
      let last = symbols.last
      
      switch char {
      case "(", "{", "[":
        symbols += String(char)
      case ")":
        if last == "(" {
          _ = symbols.popLast()
        } else {
          return false
        }
      case "}":
        if last == "{" {
          _ = symbols.popLast()
        } else {
          return false
        }
      case "]":
        if last == "[" {
          _ = symbols.popLast()
        } else {
          return false
        }
      default:
        break
      }
    }
    
    return symbols.isEmpty
  }
}

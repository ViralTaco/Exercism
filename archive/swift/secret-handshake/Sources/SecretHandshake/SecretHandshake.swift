class SecretHandshake {
  private static let secrets = [
    0b0001: "wink"
  , 0b0010: "double blink"
  , 0b0100: "close your eyes"
  , 0b1000: "jump"
  ].sorted(by: <)
  
  private static let reverse = 0b0001_0000
  
  let commands: [String]
  
  init(_ handshake: Int) {
    var commands = [String]()
    for secret in SecretHandshake.secrets {
      if handshake & secret.key != 0 { // bitand
        commands += [secret.value]
      }
    }
    
    if handshake & SecretHandshake.reverse != 0 { // bitand
      commands.reverse()
    }
    
    self.commands = commands
  }
}

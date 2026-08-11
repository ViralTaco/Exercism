struct Bowling {
  public enum BowlingError: Error {
    case invalidNumberOfPins
    case tooManyPinsInFrame
    case gameInProgress
    case gameIsOver
  }
  var pins = [Int]()

  mutating func roll(pins: Int) throws {
    if pins < 0 || pins > 10 {
      throw BowlingError.invalidNumberOfPins
    }

    self.pins.append(pins)
  }

  func score() throws -> Int {
    var openFrames = 0
    var last = 0

    for frame in self.pins {
      if frame == 10 {
        openFrames = 3
      } else if frame + last == 10 {
        openFrames = 2
      } else {
        openFrames = 1
      }

      last = frame
      openFrames -= 1
    }

    if openFrames > 0 {
      throw BowlingError.gameInProgress
    }

    return self.pins.reduce(0, { total, i in total + i })
  }
}

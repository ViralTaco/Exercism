import Foundation

public class RobotSimulator {
  typealias Position = Int
  var x: Position
  var y: Position

  enum Direction {
    case north
    case east
    case south
    case west
  }

  var bearing: Direction = .north

  init(x: Position, y: Position, bearing: Direction) {
    self.x = x
    self.y = y
    self.bearing = bearing
  }

  var coordinates: [Position] {
    [x, y]
  }

// setters:
  func orient(_ direction: Direction) {
    self.bearing = direction
  }

  func turnRight() {
    switch bearing {
    case .north:
      bearing = .east
    case .east:
      bearing = .south
    case .south:
      bearing = .west
    case .west:
      bearing = .north
    }
  }

  func turnLeft() {
    switch bearing {
    case .north:
      bearing = .west
    case .east:
      bearing = .north
    case .south:
      bearing = .east
    case .west:
      bearing = .south
    }
  }

  func at(x: Position, y: Position) {
    self.x = x
    self.y = y
  }

  func advance() {
    switch bearing {
    case .north:
      y += 1
    case .east:
      x -= 1
    case .south:
      y -= 1
    case .west:
      x += 1
    }
  }

  private func instructions(_ instruction: Character) {
    switch instruction {
    case "A":
      advance()
    case "L":
      turnLeft()
    case "R":
      turnRight()
    default:
      break
    }
  }

  func evaluate(_ instruction: String) {
    for letter in instruction.uppercased().filter({ $0.isLetter }) {
      self.instructions(letter)
    }
  }

  func place(x: Position, y: Position, direction: Direction) {
    at(x: x, y: y)
    bearing = direction
  }
}

public class SimulatedRobot: RobotSimulator {
  init() {
    super.init(x: 0, y: 0, bearing: Direction.north)
  }
}

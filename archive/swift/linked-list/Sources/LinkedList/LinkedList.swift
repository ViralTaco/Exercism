public class Node<T> {
  var value: T
  var next: Node<T>?

  init(value: T, next: Node<T>?) {
    self.value = value
    self.next = next
  }

  func set(next: Node<T>?) {
    self.next = next
  }

  func set(value: T) {
    self.value = value
  }
}

public class Deque<T> {
  private var data = [Node<T>]()
  private var first: Node<T>? = nil

// setters:
  func push(_ value: T) {
    let next = Node(value: value, next: nil)

    var current: Node<T>? = first
    while let nextNode = first?.next {
      current = nextNode
    }

    current.set(next: next)

    data.append(next)
  }

  func unshift(_ value: T) {
    let next = Node(value: value, next: data.first)
    data = [next] + data
  }

// getters:
  func pop() -> T? {
    guard !data.isEmpty else {
      return nil
    }
    return data.removeLast().value
  }

  // shift() ≈ popFirst()
  func shift() -> T? {
    guard !data.isEmpty else {
      return nil
    }
    let first = data.first?.value 

    if data.count > 1 {
      data = Array(data.suffix(from: 1))
    }

    return first
  }
}

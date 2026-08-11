import Foundation

struct SpaceAge {
  // 365.25 (days) * 24 (hours) * 60 (minutes) * 60 = 31,557,600 (seconds)
  let secondsInYear: TimeInterval = 31_557_600.0
  var seconds: TimeInterval

  init(_ seconds: UInt) {
    self.seconds = TimeInterval(seconds)
  }

/* Planet    ┃ Orbital Period (yrs)
 ━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━
   Mercury   ┃ 0.2408467
   Venus     ┃ 0.61519726
   Earth     ┃ 1.0
   Mars      ┃ 1.8808158
   Jupiter   ┃ 11.862615
   Saturn    ┃ 29.447498
   Uranus    ┃ 84.016846
   Neptune   ┃ 164.79132
 ━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━ */
  var onEarth: TimeInterval {
    seconds / secondsInYear
  }
  var onMercury: TimeInterval {
    onEarth / 0.2408467
  }
  var onVenus: TimeInterval {
    onEarth / 0.61519726
  }
  var onMars: TimeInterval {
    onEarth / 1.8808158
  }
  var onJupiter: TimeInterval {
    onEarth / 11.862615
  }
  var onSaturn: TimeInterval {
    onEarth / 29.447498
  }
  var onUranus: TimeInterval {
    onEarth / 84.016846
  }
  var onNeptune: TimeInterval {
    onEarth / 164.79132
  }
}

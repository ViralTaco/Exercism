import Foundation

struct Gigasecond {
  var timestamp: DateFormatter {
    let df = DateFormatter()
    df.dateFormat = "yyyy-MM-dd'T'HH:mm:ss"
    df.timeZone = TimeZone(abbreviation: "UTC")
    return df
  }

  let gigasecond: TimeInterval = 1E9 // 10^9
  var description: String?

  init?(from date: String)
  {
    if let begin = timestamp.date(from: date) {
      description = timestamp.string(for: begin + gigasecond)
    } else { // Cry
      return nil
    }
  }
  
} // struct Gigasecond

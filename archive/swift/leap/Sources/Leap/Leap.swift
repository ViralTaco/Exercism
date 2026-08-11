struct Year {
  var isLeapYear: Bool
  
  init(calendarYear year: UInt) {
    self.isLeapYear = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0
  }
}

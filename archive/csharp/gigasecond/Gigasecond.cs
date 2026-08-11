using System;

public static class Gigasecond {
  private const double kGigaSecond = 1.0e9;

  public static DateTime Add(DateTime moment)
  => moment.AddSeconds(kGigaSecond);
}
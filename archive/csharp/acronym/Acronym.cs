using System.Text.RegularExpressions;

public struct EmoString {
  public string value;
  public EmoString(string str) => value = str;

  public EmoString Shout()
  {
    value = value.ToUpper();
    return this;
  }

  public EmoString Rephrase(string pattern = "")
  {
    var matches = "";
    foreach (Match match in Regex.Matches(value, pattern)) {
      matches += match.Value;
    }

    value = matches;
    return this;
  }

  public EmoString Sterilize(char ignore = '\0')
  {
    for (int i = 0; i < value.Length; ++i) {
      if (value[i] == ignore) {
        value = value.Remove(i, 1);
      } else if (!char.IsLetter(value[i])) {
        value = value.Replace(value[i], ' ');
      }
    }
    return this;
  }

  override public string ToString() => value;
}

public static class Acronym {

  public static string Abbreviate(string phrase = null)
  => phrase == null ? "" :
     new EmoString(phrase)
        .Sterilize(ignore: '\'')
        .Rephrase(pattern: @"\b[\w]")
        .Shout()
        .ToString()
        ;
}
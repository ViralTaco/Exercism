class Acronym {
  String abbreviate(String phrase)
  => phrase.toUpperCase()
           .replaceAll(new RegExp(r"[^A-Z|\']"), ' ')
           .replaceAll(new RegExp(r"\B[(\w)]|\'."), '')
           .split(' ')
           .join()
           ;
}

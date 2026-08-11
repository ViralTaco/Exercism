fileprivate extension String {
  func segment(size: Int) -> [String] {
    let end = self.endIndex
    var start = self.startIndex
    var segments = [String]()

    while start < end {
      let mid = self.index(start, offsetBy: size, limitedBy: end) ?? end
      segments.append(String(self[start..<mid]))
      start = mid
    }

    return segments
  }
}

public class ProteinTranslation {
  enum ProteinTranslationError: Error {
    case invalidCodon(String)
  }
  
  private static func translate(codon: String) -> String? {
    switch codon {
    case "AUG":
      return "Methionine"
    case "UUU", "UUC":
      return "Phenylalanine"
    case "UUA", "UUG":
      return "Leucine"
    case "UCU", "UCC", "UCA", "UCG":
      return "Serine"
    case "UAU", "UAC":
      return "Tyrosine"
    case "UGU", "UGC":
      return "Cysteine"
    case "UGG":
      return "Tryptophan"
    case "UAA", "UAG", "UGA":
      return "STOP"
    default:
      return nil
    }
  }

  static func translationOfCodon(_ codon: String) throws -> String {
    if let protein = ProteinTranslation.translate(codon: codon) {
      return protein
    } else {
      throw ProteinTranslationError.invalidCodon(codon)
    }
  }

  static func translationOfRNA(_ codons: String) throws -> [String] {
    let codonArray = codons.segment(size: 3)
    var proteinArray = [String]()

    for codon in codonArray {
      if let protein = ProteinTranslation.translate(codon: codon) {
        if protein == "STOP" { break }
        proteinArray.append(protein)
      } else {
        throw ProteinTranslationError.invalidCodon(codon)
      }
    }

    return proteinArray
  }
}

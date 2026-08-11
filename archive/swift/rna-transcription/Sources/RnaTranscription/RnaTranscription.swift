enum TranscriptionError: Error {
  case invalidNucleotide(message: String)
}

class Nucleotide {
  let sequence: String
  
  init(_ dna: String) {
    sequence = dna.uppercased()
  }
  
  func complementOfDNA() throws -> String {
    var complement = ""
    
    for nucleotide in sequence {
      switch nucleotide {
      case "G":
        complement += "C"
      case "C":
        complement += "G"
      case "T":
        complement += "A"
      case "A":
        complement += "U"
      default:
        throw TranscriptionError.invalidNucleotide(
          message: "\(nucleotide) is not a valid Nucleotide"
        )
      }
    }
    
    return complement
  }
}

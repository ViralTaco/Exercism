import java.util.List;
import java.util.ArrayList;

class ProteinTranslator {

   private static String translateCodon(String codon) {
      switch (codon) {
      case "AUG":
         return "Methionine";
      case "UUU": case "UUC":
         return "Phenylalanine";
      case "UUA": case "UUG":
         return "Leucine";
      case "UCU": case "UCC": case "UCA": case "UCG":
         return "Serine";
      case "UAU": case "UAC":
         return "Tyrosine";
      case "UGU": case "UGC":
         return "Cysteine";
      case "UGG":
         return "Tryptophan";
      case "UAA": case "UAG": case "UGA":
         return "STOP";
      default:
         break;
      }
      
      return null;
   }
   
   private static List<String> segment(String string, int length) {
      final int limit = string.length();
      List<String> segments = new ArrayList<String>();
      
      for (int i = 0; i + length <= limit; i += length) {
         segments.add(string.substring(i, i + length));
      }
      
      return segments;
   }
   
   private static List<String> segment(String string) {
      return segment(string, 3);
   }
   
   List<String> translate(String codons) {
      List<String> proteins = new ArrayList<String>();
      List<String> segments = segment(codons);
      
      for (String codon: segments) {
         final String protein = translateCodon(codon);
         
         if (protein.equals("STOP") || protein == null) { 
            break; 
         }
         
         proteins.add(protein);
      }
      
      return proteins;
   }
}
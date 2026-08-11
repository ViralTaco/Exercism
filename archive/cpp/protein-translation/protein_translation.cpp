#include "protein_translation.h"
#include <algorithm>

namespace protein_translation {
auto translate(String const& codon) -> String {
  if (codon == "AUG") {
    return "Methionine";
  } else if (codon == "UUU" or codon == "UUC") {
    return "Phenylalanine";
  } else if (codon == "UUA" or codon == "UUG") {
    return "Leucine";
  } else if (codon == "UCU" or codon == "UCC"
         or codon == "UCA" or codon == "UCG") {
    return "Serine";
  } else if (codon == "UAU" or codon == "UAC") {
    return "Tyrosine";
  } else if (codon == "UGU" or codon == "UGC") {
    return "Cysteine";
  } else if (codon == "UGG") {
    return "Tryptophan";
  } else if (codon == "UAA" or codon == "UAG"
         or codon == "UGA") {
    return "STOP";
  } else {
    return nullptr;
  }
}

auto segment(String const& codons,
             const std::size_t segment_length) -> Vector<String> {
  Vector<String> segments{};
  segments.reserve(1ULL + codons.length() / segment_length);

  const auto end = codons.end();
  auto pos = codons.begin();

  while (pos < end) {
    auto new_end = pos + 2ULL;

    if (new_end <= end) {
      segments.push_back(String(pos, new_end));
    }

    pos += 3ULL;
  }

  return segments;
}


auto proteins(String const& condon) -> Vector<String> {
  if (condon.length() > 3ULL) {
    return proteins(segment(condon, 3ULL));
  }

  auto protein = translate(condon);
  if (protein != "STOP") {
    return { protein };
  }

  return {};
}

auto proteins(Vector<String> const& codons) -> Vector<String> {
  Vector<String> protein_array{};
  protein_array.reserve(1ULL + codons.size() / 3);

  for (auto const& codon: codons) {
    const auto prots = proteins(codon);
    if (not prots.empty()) {
      protein_array.push_back(prots[0]);
    }
  }

  return protein_array;
}

}  // namespace protein_translation

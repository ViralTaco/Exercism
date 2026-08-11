#ifndef VT_PROTEIN_TRANSLATION_H
#define VT_PROTEIN_TRANSLATION_H

#define EXERCISM_RUN_ALL_TESTS true

#include <vector>
#include <string>
#include <cstddef>

namespace protein_translation {
template <typename T> using Vector = typename std::vector<T>;
using StringView = std::string_view;
using String = std::string;


auto proteins(String const& condon) -> Vector<String>;
auto proteins(Vector<String> const& codons) -> Vector<String>;
auto segment(String const& codons,
             const std::size_t segment_length) -> Vector<String>;
auto translate(String const& codon) -> String;
}  // namespace protein_translation

#endif //not defined VT_PROTEIN_TRANSLATION_H

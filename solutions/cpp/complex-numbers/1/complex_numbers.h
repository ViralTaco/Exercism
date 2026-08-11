#pragma once // copyright 2024,2026 viraltaco_ <https://viraltaco.com>
#ifndef VT_COMPLEX_NUMBERS_H
#define VT_COMPLEX_NUMBERS_H "0.3.0"

#include <utility>      // std::pair
#include <concepts>     // std::floating_point
#include <type_traits>  // std::is_constant_evaluated
#include <cmath>        // std::{ abs, hypot, exp, cos, sin, fpclassify }
#include <numbers>      // math constants

namespace complex_numbers {

template <std::floating_point value_type> 
class complex {
  using pair_type = std::pair<value_type, value_type>;
  using Self = complex;

  value_type re{ value_type{} };
  value_type im{ value_type{} };

public:
  using type = Self;

  constexpr complex() noexcept = default;

  explicit(false)
  constexpr complex(const value_type real) noexcept
    : re{ real }
    , im{ value_type{} }
  {}

  explicit(false)
  constexpr complex(const value_type real, const value_type imag) noexcept
    : re{ real }
    , im{ imag }
  {}

  // Member access
  constexpr auto real(const value_type real_val) noexcept -> void { re = real_val; }
  constexpr auto imag(const value_type imag_val) noexcept -> void { im = imag_val; }

  [[nodiscard]] constexpr auto split() const noexcept -> pair_type {
    return { re, im };
  }
  [[nodiscard]] constexpr auto real() const& noexcept -> value_type { return re; }
  [[nodiscard]] constexpr auto imag() const& noexcept -> value_type { return im; }

  [[nodiscard]] constexpr auto isreal() const noexcept -> bool {
    return im == value_type{0};
  }
  [[nodiscard]] constexpr auto isimag() const noexcept -> bool {
    return re == value_type{0};
  }

  [[nodiscard]] constexpr auto conj() const noexcept -> Self {
    return { re, -im };
  }

  // Arithmetic methods
  [[nodiscard]] constexpr auto abs() const noexcept -> value_type {
    if (std::is_constant_evaluated()) {
      return std::sqrt(re * re + im * im);
    }
    return std::hypot(re, im);
  }

  [[nodiscard]] constexpr auto norm() const noexcept -> value_type {
    return re * re + im * im;
  }

  // Operators
  constexpr auto operator *(complex const& r) const noexcept -> Self {
    return { re * r.re - im * r.im
           , re * r.im + im * r.re };
  }

  constexpr auto operator /(complex const& r) const noexcept -> Self {
    const value_type n = r.norm();
    return { (re * r.re + im * r.im) / n
           , (im * r.re - re * r.im) / n };
  }

  constexpr auto operator +(complex const& r) const noexcept -> Self {
    return { re + r.re
           , im + r.im };
  }

  constexpr auto operator -(complex const& r) const noexcept -> Self {
    return { re - r.re
           , im - r.im };
  }

  // Member scalar operator s
  constexpr auto operator *(const value_type r) const noexcept -> Self {
    return { re * r
           , im * r };
  }
  constexpr auto operator /(const value_type r) const noexcept -> Self {
    return { re / r
           , im / r };
  }
  constexpr auto operator +(const value_type r) const noexcept -> Self {
    return { re + r
           , im };
  }
  constexpr auto operator -(const value_type r) const noexcept -> Self {
    return { re - r
           , im };
  }

  constexpr auto exp() const noexcept -> Self {
    // e^(a + ib) = e^a * (cos(b) + i*sin(b))
    const value_type ea = std::exp(re);
    return { ea * std::cos(im), ea * std::sin(im) };
  }
};

// Non-member scalar left-hand side operators
#define VT_REAL_COMPLEX_OPERATOR( OP )                                 \
  template <std::floating_point T>                                     \
  constexpr complex<T> operator OP(T const& lhs, complex<T> const& rhs) noexcept { \
    return complex<T>{lhs} OP rhs;                                     \
  } static_assert(true, "Require Semicolon.")

VT_REAL_COMPLEX_OPERATOR(*);
VT_REAL_COMPLEX_OPERATOR(/);
VT_REAL_COMPLEX_OPERATOR(+);
VT_REAL_COMPLEX_OPERATOR(-);

#undef VT_REAL_COMPLEX_OPERATOR

using Complex = typename complex<double>::type;

}  // namespace complex_numbers

#endif  // VT_COMPLEX_NUMBERS_H

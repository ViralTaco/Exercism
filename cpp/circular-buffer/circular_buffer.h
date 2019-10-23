#ifndef VT_CIRCULAR_BUFFER_H
#define VT_CIRCULAR_BUFFER_H

#define EXERCISM_RUN_ALL_TESTS true

#include <stdexcept>
#include <vector>
#include <string>

namespace circular_buffer {

template <typename T> struct position {
public:
  using size_type = T;
  size_type pos_;
  size_type limit_;
  
  position(size_type pos = 0ULL, size_type limit = 0ULL) noexcept
    : pos_{ pos }
    , limit_{ limit }
  {}
  
  void operator =(T new_pos) noexcept {
    pos_ = new_pos;
  }
  
public: // methods
  void set_limit(size_type new_limit) noexcept {
    limit_ = new_limit;
  }
  
  void rewind() noexcept {
    pos_ = 0ULL;
  }
  
public: // operator overloads
  auto operator ++() noexcept {
    if (limit_ != 0ULL)
      pos_ = (pos_ + 1ULL) % limit_;
    return *this;
  }
  
  auto operator --() noexcept {
    if (limit_ != 0ULL)
      pos_ = (pos_ - 1ULL) % limit_;
    return *this;
  }
  
  /* implicit */ operator T() const noexcept {
    return pos_;
  }
};

template <typename T> class circular_buffer {
private:
  using size_type = typename std::vector<T>::size_type;
  
  std::vector<T> buffer_;
  size_type capacity_;
  position<size_type> head_;
  position<size_type> tail_;
  
  bool is_writable_;
  bool is_full_;
  
public: // constructors
  circular_buffer(size_type size)
    : buffer_{ std::vector<T>(size) }
    , capacity_{ size }
    , head_{ 0ULL, capacity_ }
    , tail_{ 0ULL, capacity_ }
    , is_writable_{ true }
    , is_full_{ false }
  {
  }

private: // methods
  void advance() noexcept {
    if (is_full_)
      ++tail_;
      
    ++head_;
    is_full_ = head_ == tail_;
  }

  void retreat() noexcept {
    is_full_ = false;
    ++tail_;
  }
  
public: // methods
  void write(T val) {  
    if (not is_writable_)
      throw std::domain_error("Can't write on overwritten buffer");
    
    if (is_full_)
      throw std::domain_error("Buffer is full");
      
    buffer_.at(head_) = val;
    advance();
  }
  
  void overwrite(T val) {
    buffer_.at(head_) = val;
    advance();
    is_writable_ = false;
  }
  
  T read() {
    is_writable_ = true;
    if (not is_full_ and tail_ == head_) { // buffer is empty
      throw std::domain_error("Nothing to read.");
    }
      
    auto value = buffer_.at(tail_);
    retreat();
    return value;
  }
  
  void clear() {
    buffer_ = std::vector<T>(capacity_); // memory leak? ¯\_(ツ)_/¯
    // capacity remains the same. 
    head_.rewind();
    tail_.rewind();
    is_writable_ = true;
    is_full_ = false;
  } 
};

}  // namespace circular_buffer

#endif // VT_CIRCULAR_BUFFER_H

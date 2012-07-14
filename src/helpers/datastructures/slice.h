#pragma once
#include "core.h"

#include <boost/call_traits.hpp>

/**
 * A slice is an array range accessor.
 * It does not own the data.
 */

template <typename T>
class slice {
  const T * const _data;
  const size_t _size;

  const T * start;
  size_t range;

  const T defaulter;

  typedef typename call_traits<T>::param_type value_type;

public:
  slice(const T * data, size_t size)
    : _data(data), _size(size),
      start(data), range(size),
      defaulter() {}

  value_type operator[](size_t n) {
    if (n >= range) return defaulter;
    return start[n];
  }

  size_t size() {
    return range;
  }
  const T * data() {
    return start;
  }
  void advance(size_t n = 1) {
    if (n > range) n = range;
    start += n;
    range -= n;
  }

  void original_size() {
    return _size;
  }
  const T * original_data() {
    return _data;
  }
  void reset() {
    start = _data;
    range = _size;
  }
};


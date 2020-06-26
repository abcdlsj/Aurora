//
// Created by abcdlsj on 2020/6/9.
//

#ifndef AURORA_AURORA_TIMESTAMP_H_
#define AURORA_AURORA_TIMESTAMP_H_
#include <chrono>

namespace Aurora {
using std::chrono::system_clock;
using namespace std::literals::chrono_literals;

typedef std::chrono::nanoseconds Nanosecond;
typedef std::chrono::microseconds Microsecond;
typedef std::chrono::milliseconds Millisecond;
typedef std::chrono::seconds Second;
typedef std::chrono::minutes Minute;
typedef std::chrono::hours Hour;

typedef std::chrono::time_point<system_clock, Nanosecond> Timestamp;

namespace clock {
inline Timestamp now() {
  return system_clock::now();
}

inline Timestamp nowAfter(Nanosecond interval) {
  return now() + interval;
}

inline Timestamp nowBefore(Nanosecond interval) {
  return now() - interval;
}
}

template<typename T>
struct IntervalTypeCheckImpl {
  static constexpr bool value =
      std::is_same<T, Nanosecond>::value ||
          std::is_same<T, Microsecond>::value ||
          std::is_same<T, Millisecond>::value ||
          std::is_same<T, Second>::value ||
          std::is_same<T, Minute>::value ||
          std::is_same<T, Hour>::value;
};

#define IntervalTypeCheck(T) \
    static_assert(IntervalTypeCheckImpl<T>::value, "bad interval type")

}
#endif //AURORA_AURORA_TIMESTAMP_H_

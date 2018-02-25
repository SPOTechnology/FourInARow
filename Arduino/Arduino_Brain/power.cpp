#include "Arduino.h"

long power(long base, long exponent) {
  long result = base;
  for (long i = 1L; i < exponent; ++i) {
    result *= base;
  }
  if (exponent == 0) {
    result = 1L;
  }
  return result;
}

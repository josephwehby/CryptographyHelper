#include "CryptoHelper.hpp"

bool cryptohelper::isPrime(const BigInt& a, unsigned int k) {
  return false;
}

BigInt cryptohelper::ExtendedEuclidian(const BigInt& e, const BigInt& totient) {
  BigInt quotient = BigInt(1);
  BigInt a, b, remainder, t;
  BigInt x = BigInt(0);
  BigInt y = BigInt(1);

  if (e > totient) {
    a = e;
    b = totient;
  } else {
    a = totient;
    b = e;
  }

  while (true) {
    remainder = a % b;
    quotient = a / b;
    t = x - (y * quotient);
    a = b;
    b = remainder;
    x = y;
    y = t;
    if (remainder == 0) break;
  }

  return x;
}

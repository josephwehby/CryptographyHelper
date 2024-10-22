#include "BigInteger.hpp"

namespace cryptohelper {
  bool isPrime(const BigInt&, unsigned int);
  BigInt ExtendedEuclidian(const BigInt&, const BigInt&);
  BigInt RandomBigInt(const BigInt&, const BigInt&);
}

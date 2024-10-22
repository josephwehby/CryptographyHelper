#include "BigInteger.hpp"

namespace cryptohelper {
  bool isPrime(const BigInt&, unsigned int);
  BigInteger ExtendedEuclidian(const BigInteger&, const BigInteger&);
  BigInteger RandomBigInt(const BigInteger&, const BigInteger&);
}

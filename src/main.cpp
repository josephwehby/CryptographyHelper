#include <iostream>
#include "CryptoHelper.hpp"

int main() {
  std::cout << "crypto helper function" << std::endl;
  
  /*
  BigInt r = cryptohelper::ExtendedEuclidian(17, 120);
  BigInt e = r + 120;
  std::cout << e << std::endl;
  
  BigInt a = BigInt(12345);
  std::cout << cryptohelper::isPrime(a, 10) << std::endl;
  */

  BigInt a = BigInt("49");
  std::cout << a << " is prime: " << cryptohelper::isPrime(a, 7) << std::endl;
  return 0;
}

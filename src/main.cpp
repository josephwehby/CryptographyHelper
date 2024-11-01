#include <iostream>
#include "CryptoHelper.hpp"

int main() {
  std::cout << "crypto helper function" << std::endl;
  
  
  BigInt r = cryptohelper::ExtendedEuclidian(17, 120);

  BigInt e = r + 120;
  std::cout << r << std::endl;
  std::cout << e << std::endl;
  return 0;
}

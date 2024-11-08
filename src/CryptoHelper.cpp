#include "CryptoHelper.hpp"

bool cryptohelper::isPrime(const BigInt& a, unsigned int k) {
  /*
  if (num <= 3) return true;
  if (num % 2 == 0) return false;

  int shift = 1;
  int prev = 1;
  BigInt two = BigInt(0);
  BigInt m;
  num = num - 1;
  
  while (true) {
    two = BigInt(1 << shift);
    if (BigInt::ModPow(num, 1, two) != 0) break;
    prev = shift;
    shift++;  
  }
  
  BigInt t = BigInt(1 << prev);

  m = num / t;
  num = num + 1;
  
  BigInt one = BigInt(1);
  for (unsigned int i = 0; i < k; i++) {
    BigInt a = RandomBigInt(1, num);
    BigInt x = BigInt::ModPow(a, m, num);
    
    if (x == one%num || x == num-1) {
      continue;
    }

    for (int j = 0; j < prev-1; j++) {
      x =  BigInt::ModPow(x, 2, num);
      if (x == num-1) break;
    }

    if (x != num-1) return false;
  }
*/
  std::cout << RandomBigInt(1, a) << std::endl;
  return true;
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

BigInt cryptohelper::RandomBigInt(const BigInt& lower, const BigInt& upper) {
  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<int> dist(0, 255);

  std::vector<uint8_t> bytes = upper.ToBytes();
  int num_bytes = bytes.size();

  std::vector<uint8_t> random_bytes(num_bytes);
  
  BigInt randomNum;
  while (true) {
    for (int i = 0; i < num_bytes; i++) random_bytes[i] = static_cast<uint8_t>(dist(gen));
    randomNum = BigInt(random_bytes);
    if (randomNum < 0) {
      randomNum = randomNum * -1;
    }

    if (randomNum > lower && randomNum < upper) return randomNum;
  }
}

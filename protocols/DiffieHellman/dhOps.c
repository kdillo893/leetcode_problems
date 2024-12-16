#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// library for large numbers
#include <gmp.h>

/**
 * 1 if is prime, 0 if not
 */
int isPrime(mpz_t *number) {

  // if divisible by 2 up to sqrt(number), is not prime.
  mpz_t numSqrt;
  mpz_init(numSqrt);
  mpz_sqrt(numSqrt, *number);
  mpz_t i;
  mpz_init(i);
  for (mpz_set_ui(i, 2); mpz_cmp(numSqrt, i); mpz_add_ui(i, i, 1)) {
    // if is divisible, we aren't prime.
    if (mpz_divisible_p(*number, i)) {
      return 0;
    }
  }

  return 1;
}

/**
 * find a large seed using random library for variance; allow input of seed.
 */
void largePrime(mpz_t *prime, gmp_randstate_t *seed) {

  // if seed provided, use in srand; no need to force it to a specific value
  // Assuming seed is provided for now...
  mpz_urandomb(*prime, *seed, 4096);
  mpz_nextprime(*prime, *prime);
  
  return;
}

/**
 * calculation for diffie hellman stuff (a^b % p)
 */
void primeMod(mpz_t *result, mpz_t *base, mpz_t *power, mpz_t *prime) {

  if (mpz_cmp_ui(*power, 1)) {
    mpz_mod(*result, *base, *prime);
    return;
  }

  return;
}

/**
 * Primitive root explanation here:
 * https://en.wikipedia.org/wiki/Primitive_root_modulo_n
 * Primitive root calc assistance found in links below:
 * https://math.stackexchange.com/questions/124408/finding-a-primitive-root-of-a-prime-number
 */
unsigned long long int generatePrimitiveRoot(unsigned long long int p) {

  // simple check is to go for common denominators of euler thing of p (aka p-1)
  // TODO

  return 0;
}

int main(int argc, char *argv[]) {

  //this is an array declaration 
  gmp_randstate_t bigSeed;
  gmp_randinit_default(bigSeed);
  
  long seed = 0;
  if (argc == 2) {
    seed = atoi(argv[1]);
  }

  mpz_t p;
  mpz_init(p);
  mpz_set_ui(p, 0);

  largePrime(&p, &bigSeed);


  mpz_out_str(stdout, 16, p);
  assert(isPrime(&p));

  // unsigned long long int g = generatePrimitiveRoot(p);

  return EXIT_SUCCESS;
}

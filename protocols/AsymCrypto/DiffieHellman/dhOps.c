#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// library for large numbers
#include <gmp.h>
#include <string.h>

// function decs
int isPrime(mpz_t *number, gmp_randstate_t *seed);
int millerRabin(mpz_t *number, int rounds, gmp_randstate_t *seed);
int millerRabinRound(mpz_t *n, mpz_t *nmin1, mp_bitcnt_t s, mpz_t *q,
                     mpz_t *atest);

/**
 * 1 if is prime, 0 if not
 * if divisible by 2 up to sqrt(number), is not prime.
 */
int isProbablyPrime(mpz_t *number, gmp_randstate_t *seed) {

  printf("checking if this is prime: ");
  mpz_out_str(stdout, 16, *number);
  printf("\n");

  return millerRabin(number, 128, seed);
}

/**
 * Miller Rabin primality check (only discovered this a while ago)
 *
 * "n is prime if and only if solutions of "x^2 = 1 mod n" are x = +- 1
 * -- if passes fermat, can also check "a^((n-1)/2) = +- 1"
 *
 * @return 1 if probably prime, 0 if composite
 */
int millerRabin(mpz_t *number, int rounds, gmp_randstate_t *seed) {
  // find 2^s, largest power of 2 dividing n-1
  mpz_t nmin1;
  mpz_init(nmin1);
  mpz_sub_ui(nmin1, *number, 1);

  // will contain the odd number q that divides n-1 with pow2
  mpz_t q;
  mpz_init(q);

  mp_bitcnt_t power2 = 0;

  while (mpz_divisible_2exp_p(nmin1, power2)) {
    // using q as a test value for the moment
    mpz_div_2exp(q, nmin1, power2);
    // printf("q check:\n");
    // mpz_out_str(stdout, 16, q);
    // printf("\n");

    if (mpz_odd_p(q)) {
      // we're good, q is correct.
      break;
    }

    power2++;
  }

  printf("mrr vals:\npow2 aka (s) = %ld", power2);
  printf("\nq = \n");
  mpz_out_str(stdout, 16, q);
  printf("\nn-1 = \n");
  mpz_out_str(stdout, 16, nmin1);
  printf("\n\n");

  for (int i = 0; i < rounds; i++) {
    // select an "a" for this round, 2 <= a <= n-2
    mpz_t atest;
    mpz_init(atest);
    // temp set atest to n-4, then add 2 to the "random" result for the
    // appropriate range.
    mpz_sub_ui(atest, *number, 4);
    mpz_urandomm(atest, *seed, atest);
    mpz_add_ui(atest, atest, 2);

    printf("round%d: ", i);
    // have an appropriate a, q, s, n... do a round.
    int composite = millerRabinRound(number, &nmin1, power2, &q, &atest);
    printf("composite=%d", composite);
    printf("\n");

    if (composite) {
      return 0;
    }
  }

  return 1;
}

/**
 * places result of a round within res parameter
 * q is odd, s is power2, nmin1 is n-1, atest is base for this round
 * return 1 for if composite, 0 if probably prime
 */
int millerRabinRound(mpz_t *n, mpz_t *nmin1, mp_bitcnt_t s, mpz_t *q,
                     mpz_t *atest) {
  mpz_t x;
  mpz_init(x);

  // wikipedia for this step is nicer:
  // x to hold "a^q mod n", call it "x"
  mpz_powm(x, *atest, *q, *n);

  if (mpz_cmp_ui(x, 1)) {
    return 0;
  }

  printf("\na = \n");
  mpz_out_str(stdout, 16, *atest);
  printf("\nx = \n");
  mpz_out_str(stdout, 16, x);
  printf("\n");

  mpz_t y;
  mpz_init(y);

  for (int i = 0; i < s; i++) {
    printf("i=%d\n", i);
    // each step y = x^2 mod n (this goes from 2^0 to 2^s over loop)
    mpz_powm_ui(y, x, 2, *n);

    // check for composite-ness
    if (mpz_cmp_ui(y, 1)) {
      printf("composite inside loop\n");
      return 1;
    }

    // continue checks; x after this step becomes a^(2^i * q) mod n
    mpz_set(x, y);
  }

  return 0;
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

  // this is an array declaration
  gmp_randstate_t bigSeed;

  char *seed = NULL;
  if (argc >= 2) {
    strcpy(seed, argv[1]);
  }

  // if the seed is there as parameter, parse the characters into gmp number.
  gmp_randinit_default(bigSeed);

  mpz_t p;
  mpz_init(p);
  mpz_set_ui(p, 0);

  largePrime(&p, &bigSeed);

  mpz_out_str(stdout, 16, p);
  printf("\n");
  assert(isProbablyPrime(&p, &bigSeed));

  // unsigned long long int g = generatePrimitiveRoot(p);

  return EXIT_SUCCESS;
}

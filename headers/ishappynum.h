/** NOTE: This solution is inspired by others for this problem.
  Couldn't find the old iteration without outside information 
  to reduce runtime.
*/

int isHappy(int n);

/**
 * Compute wehther the number is happy (sums of digits squared, do they converge
 * to "1")
 */
inline int isHappy(int n) {

  if (n <= 0)
    return 0;

  // number iteration
  while (n != 1) {
    // how do I get the digit? mod 10, divide by 10, repeat.

    int sum = 0;
    while (n > 0) {
      int rem = n % 10;
      sum += rem * rem;

      n = n / 10;
    }

    n = sum; //(new num)

    // sum results that loop? this is inspired by some other solutions,
    //  since the ones I made initially were slow and less nice with memory.
    //
    //  1 = done
    //  2 -> 4 -> 16 -> 37 -> 58 -> 89 -> (64+81)=145 -> 16+25+1=42 -> 20 ..
    //  see 2. 3 -> 9 -> 81 -> 65 -> 36+25=61 -> 37 .. (see 2's loop) 4, see 2's
    //  loop 5 -> 25 -> 29 -> 85 -> 25+64=89... see 2's loop 6 -> 36 -> 45 -> 41
    //  -> 17 -> 50 7 -> 49 -> 16+81=97 -> 81+49=130 -> 10 -> 1...
    // ...

    if (n == 1)
      break;
    if (n == 37)
      break;
    if (n == 89)
      break;
    if (n == 17)
      break;
  }

  return n == 1;
}
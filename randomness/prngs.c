#include <stdint.h>

// pcg32_pie, based on the minimal C version from O'Neill at pcg-random.org;
// I've made a few (subjective) UX improvements for beginner use
//
// I'm not allowing the user to pick the stream/increment constant at all,
// since there is almost never a reason for doing this in common applications.
// This means that the prng state is reduced to a single uint64_t which also
// means we can avoid having a state struct at all. The (fixed) stream constant
// uses the leading hex digits of pi and e multipled by 2^30 (c90fdaa2 and
// adf85459).
//  
// I have also added an XOR with the same digits on the output path prior
// to xorshift mixing.  This prevents the "surprising" result that the 
// first "random 32-bit number" from a (very common) 0 seed is 0.
//
// use: 
//   uint64_t state = 12345; // whatever you like can go here
//   uint32_t some_random_32_bits = pcg32_pie(&state);
//   uint32_t more_random_32_bits = pcg32_pie(&state);

uint32_t pcg32_pie (uint64_t *state) {
  uint64_t old = *state ^ 0xc90fdaa2adf85459ULL;
  *state = *state * 6364136223846793005ULL + 0xc90fdaa2adf85459ULL;
  uint32_t xorshifted = ((old >> 18u) ^ old) >> 27u;
  uint32_t rot = old >> 59u;
  return (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
}   


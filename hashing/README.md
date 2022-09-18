# scribbles/hashing

Minimal cut/paste-able implementations of two good hash functions,
xxhash64 for 64-bit (~50 lines) and murmur3-32 (~25 lines) for 32-bit. They
are derived from, and tested against, the official implementations of
both hash functions.

The base versions are the simplest to read and understand and will work
for most use cases but in principle your compiler could cause a problem
because of Undefined Behavior due to unaligned access. If this is a 
concern for you, see the sibling file that addresses this problem at a 
minor cost in readability and implementation size.

# scribbles
Fragments of code optimized for cut/paste reuse

## Why?

Perhaps you have heard of single-file libraries. They offer a tradeoff of less intra-project granularity (one file instead of many) in return for easier integration (just drop the file in your project and you're done).

"Scribbles" is a parallel idea which optimizes for integration as a simple cut/paste operation. This means, for example, minimizing or eliminating the use of helper/utility functions (so there is only one thing to copy/paste, and only one thing added to the namespace). This comes with constraints in code style, which you may not find acceptable.

## What?

Right now this only contains scribbles for two hash functions (murmur3 32-bit and xxhash64), as well as a 32-bit PCG random generator.


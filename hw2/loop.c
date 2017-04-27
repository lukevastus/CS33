long loop(long x, int n)
{
    long result = 0;
    long mask;
    for (mask = 1; mask != 0; mask = mask << (n & 0xFF))
    {
        result |= x & mask;
    }
    return result;
}

/*
 * A. %rdi holds x, %esi holds n, %rax holds result, %rdx holds mask. 
 * B. Initial value for result is 0; that for mask is 1.
 * C. Mask should be non-zero.
 * D. Mask left shifts by a value corresponding to the lower 8 bits of n (which is n & 0xFF).
 * E. It updates by ORing to (x AND mask).
 * F. See above.
 */

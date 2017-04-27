//
//  2.73.c
//  hw1
//
//  Created by Runjia Li on 4/5/17.
//  Copyright © 2017 Runjia Li. All rights reserved.
//

#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y)
{
    int sum = (int)((unsigned)x + (unsigned)y);
    unsigned k = (sizeof(x) << 3) - 1; /* The shift required to obtain sign of int */
    /* Overflow occurs iff x and y has the same sign and the result has a different sign */
    int overflow = ((x >> k == y >> k) && (x >> k != sum >> k)) << k >> k; /* equates to -1 if overflow occurs and 0 otherwise */
    int sign = ~(x >> k); /* equates to -1 if x is positive and 0 otherwise */
    int sat = (INT_MAX & sign) | (INT_MIN & ~sign); /* equates to INT_MAX if x is negative and INT_MIN otherwise */
    return (sat & overflow) | (sum & ~overflow);
}
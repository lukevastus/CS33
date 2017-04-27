//
//  2.73-redo.c
//  hw1
//
//  Created by Runjia Li on 4/6/17.
//  Copyright © 2017 Runjia Li. All rights reserved.
//

#include <stdio.h>
#include <limits.h>

int saturating_add(int x, int y)
{
    int sum = 0;
    unsigned k = (sizeof(x) << 3) - 1;
    int overflow = __builtin_add_overflow(x, y, &sum) << k >> k;
    int sign = ~(x >> k);
    int sat = (INT_MAX & sign) | (INT_MIN & ~sign); /* equates to INT_MAX if x is negative and INT_MIN otherwise */
    return (sat & overflow) | (sum & ~overflow);
}
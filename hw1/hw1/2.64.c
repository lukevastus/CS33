//
//  2.64.c
//  hw1
//
//  Created by Runjia Li on 4/5/17.
//  Copyright © 2017 Runjia Li. All rights reserved.
//

#include <stdio.h>

int any_odd_one(unsigned x)
{
    return !!(x & 0xAAAAAAAA);
}
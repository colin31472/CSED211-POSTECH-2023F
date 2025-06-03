/* 
 * CS:APP Data Lab 
 * 
 * 유영준 20220665
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
      /*정수 x를 입력받아 -x를 return하는 함수*/
      return ~x + 1;
}
/* 
 * isLess - if x < y  then return 1, else return 0 
 *   Example: isLess(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLess(int x, int y) {
    /*두 정수 x, y를 입력받아 x가 y보다 작으면 1을 return하는 함수*/
    int my = ~y + 1;
    int mMax = 1 << 31;
    int c2 = ((x | mMax) + (my | mMax)) >> 31;
    int c1 = (((x >> 31) & (my >> 31))) | ((x >> 31 | my >> 31) & c2);
    int s = !!(y ^ mMax);
    return s & ((((x + my) >> 31) & 1) ^ (c1 ^ c2));
}
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
    /*floating point number를 입력받아 절댓값을 반환하는 함수*/
    int e = (~(uf << 1)) >> 24;
    if (!e) {
        if (uf << 9) {
            return uf;
        }
    }
    if (!(uf >> 31)) {
        return uf;
    }
    else {
        return uf ^ (1 << 31);
    }
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
    /*floating point number를 입력받아 해당 수의 2를 곱한 값을 반환하는 함수*/
    int e1 = (~(uf << 1)) >> 24;
    int e2 = ((uf << 1)) >> 24;
    if (!e1) {
        return uf;
    }
    else if (!e2) {
        if (uf >> 31) {
            return (uf + uf) ^ (1 << 31);
        }
        else {
            return uf + uf;
        }
    }
    else {
        return uf + (1 << 23);
    }
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
    /* signed integer를 입력받아 floating point로 표현한 수를 반환하는 함수 */
    if (!(x << 1)) {
        if (!(x ^ 0x80000000)) {
            return 0xcf000000;
        }
        else {
            return 0;
        }
    }
    if (1) {
        /* sign 구하기 */
        int sign = (x >> 31) << 31;
        if (sign) {
            x = ~x + 1;
        }
        if (1) {
            /* exp 구하기 */
            unsigned i = x << 1;
            int cnt = 0;
            while (!(i >> 31)) {
                cnt = cnt + 1;
                i = i << 1;
            }
            i = i << 1;
            if (1) {
                unsigned exp = 157 + (~cnt + 1);  //exp = E + bias

                /* f 구하기 */
                unsigned Ri = i >> 9;  //i에 right shift 9만큼 해준 값
                unsigned c_Ri = Ri + 1;  //Ri에 carry가 발생한 경우
                unsigned c_exp = exp + 1;  //overflow가 발생하여 exp에 1을 더해주는 경우
                int isOverflow = !(c_Ri ^ 0x00800000);  //overflow가 발생하는지 여부를 판단하기 위해 선언한 변수
                if (!((i << 23) >> 31)) {
                    i = Ri;
                }
                else {
                    if (i << 24) {
                        i = c_Ri;
                        if (isOverflow) {
                            i = 0;
                            exp = c_exp;
                        }
                    }
                    else {
                        if (i & 0x200) {
                            i = c_Ri;
                            if (isOverflow) {
                                i = 0;
                                exp = c_exp;
                            }
                        }
                        else {
                            i = Ri;
                        }
                    }
                }
                return sign | exp << 23 | i;
            }
        }
    }
    return 0;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
    /* floating point number가 unsigned로 표현된 수를 입력 받아 int형 정수를 반환하는 함수 */
    if (!(~(uf << 1) >> 24)) {
        return 0x80000000u;
    }
    if (!((uf << 1) >> 31)) {
        if (~(uf << 2) >> 25) {
            return 0;
        }
    }
    if ((uf & 0x40000000) && (uf & 0x30000000)) {
        return 0x80000000u;
    }

    if (1) {
        unsigned exp = (uf << 1) >> 24;
        int E = exp + 0xffffff81;
        int x;
        int M = 0x800000 + (uf & 0x7fffff);
        int sign = uf >> 31;

        if ((E + 0xffffffe9) >> 31) {
            x = M >> (23 + (~E + 1));
        }
        else {
            x = M << (E + 0xffffffe9);
        }

        if (sign) {
            return ~x + 1;
        }
        else {
            return x;
        }
    }
    return 0;
}

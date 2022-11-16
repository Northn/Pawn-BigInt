// MIT License

// Copyright (c) 2025 Northn

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#pragma once

#include "common.h"

class script : public ptl::AbstractScript<script> {
public:
    /**
     * Create a new BigInt value
     *
     * @param initial The initial value of BigInt variable
     *
     * @return The BigInt or INVALID_BIGINT if failed
     */
    bigint_ptr_result_t bigint_create(cell initial);

    /**
     * Create a new BigInt value based on another BigInt variable
     *
     * @param initial The initial BigInt variable
     *
     * @return The BigInt or INVALID_BIGINT if failed
     */
    bigint_ptr_result_t bigint_create_bi(bigint_ptr_t initial);

    /**
     * Create a new BigInt value based on another string variable storing an integer
     *
     * @param initial The initial value of BigInt variable stored as string
     *
     * @return The BigInt or INVALID_BIGINT if failed
     */
    bigint_ptr_result_t bigint_create_str(std::string initial);

    /**
     * Destroy a BigInt value
     *
     * @param bigint The BigInt itself
     *
     * @return 1 (true) on success
     */
    cell bigint_destroy(bigint_ptr_t bigint);

    /**
     * Assing a value to BigInt
     *
     * @param bigint The BigInt itself
     * @param value Assigning value
     *
     * @return 1 (true) on success
     */
    cell bigint_set(bigint_ptr_t bigint, cell value);

    /**
     * Assign another BigInt value to this BigInt
     *
     * @param bigint The BigInt itself
     * @param value Assigning value
     *
     * @return 1 (true) on success
     */
    cell bigint_set_bi(bigint_ptr_t bigint, bigint_ptr_t value);

    /**
     * Assign string value to this BigInt based on specified base
     *
     * @param bigint The BigInt itself
     * @param value Assigning value
     *
     * @return 1 (true) on success
     */
    cell bigint_set_str(bigint_ptr_t bigint, std::string value);

    /**
     * @brief Get a value of BigInt
     *
     * @param bigint The BigInt itself
     *
     * @return The value of BigInt
     */
    cell bigint_get(bigint_ptr_t bigint);

    /**
     * Get a value of BigInt to specified output buffer in specified base
     *
     * @param bigint The BigInt itself
     * @param out The output buffer
     * @param out_size Size of output buffer
     *
     * @return 1 (true) on success
     */
    cell bigint_get_str(bigint_ptr_t bigint, cell *out, cell out_size);

    /**
     * Get whether a BigInt fits into single signed Pawn cell variable
     *
     * @param bigint The BigInt itself
     *
     * @return 1 (true) if fits, otherwise 0 (false)
     */
    cell bigint_fits_cell(bigint_ptr_t bigint);

    /**
     * Get whether a BigInt fits into single unsigned Pawn cell variable
     *
     * @param bigint The BigInt itself
     *
     * @return 1 (true) if fits, otherwise 0 (false)
     */
    cell bigint_fits_ucell(bigint_ptr_t bigint);

    /**
     * Get whether a BigInt variable is odd
     *
     * @param bigint The BigInt itself
     *
     * @return 1 (true) if odd, otherwise 0 (false)
     */
    cell bigint_is_odd(bigint_ptr_t bigint);

    /**
     * Get whether a BigInt variable is even
     *
     * @param bigint The BigInt itself
     *
     * @return 1 (true) if even, otherwise 0 (false)
     */
    cell bigint_is_even(bigint_ptr_t bigint);

    /**
     *
     * ARITHMETIC OPERATIONS
     *
     */

    /*
     * op1 += op2;
     */

    cell bigint_add(bigint_ptr_t op1, cell op2);
    cell bigint_add_bi(bigint_ptr_t op1, bigint_ptr_t op2);

    /*
     * op1 -= op2;
     */

    cell bigint_sub(bigint_ptr_t op1, cell op2);
    cell bigint_sub_bi(bigint_ptr_t op1, bigint_ptr_t op2);

    /*
     * op1 *= op2;
     */

    cell bigint_mul(bigint_ptr_t op1, cell op2);
    cell bigint_mul_bi(bigint_ptr_t op1, bigint_ptr_t op2);

    /*
     * auto res = std::div(op1, op2);
     * op1 = res.quot;
     */

    cell bigint_div_q(bigint_ptr_t op1, cell op2);
    cell bigint_div_q_bi(bigint_ptr_t op1, bigint_ptr_t op2);

    /*
     * auto res = std::div(op1, op2);
     * op1 = res.rem;
     */

    cell bigint_div_r(bigint_ptr_t op1, cell op2);
    cell bigint_div_r_bi(bigint_ptr_t op1, bigint_ptr_t op2);

    /*
     * op = std::abs(op);
     */

    cell bigint_abs(bigint_ptr_t op);

     /*
     * op = std::negate(op);
     */

    cell bigint_neg(bigint_ptr_t op);

    /*
     * op1 = op1; if op2 == 1
     * op1 = std::trunc(std::sqrt(op1)); if op2 == 2
     * op1 = std::trunc(std::cbrt(op1)); if op2 == 3
     * op1 = std::trunc(std::pow(op1, 1.0 / op2)); if op2 > 3
     */

    cell bigint_root(bigint_ptr_t op1, cell op2);

     /*
     * op1 = std::pow(op1, op2);
     */

    cell bigint_pow(bigint_ptr_t op1, cell op2);

    /**
     *
     * ARITHMETIC COMPARISONS
     *
     */

    /**
     * Compare a BigInt with a cell
     *
     * @param op1 Left BigInt variable
     * @param op2 Cell variable to compare with
     *
     * @return Return a positive value if op1 > op2, zero if op1 = op2, or a negative value if op1 < op2
     */
    cell bigint_cmp(bigint_ptr_t op1, cell op2);

    /**
     * Compare a BigInt with another BigInt variable
     *
     * @param op1 Left BigInt variable
     * @param op2 Right BigInt variable
     *
     * @return Return a positive value if op1 > op2, zero if op1 = op2, or a negative value if op1 < op2
     */
    cell bigint_cmp_bi(bigint_ptr_t op1, bigint_ptr_t op2);

    /**
     * Compare an absolute BigInt with another absolute cell
     *
     * @param op1 Left BigInt variable
     * @param op2 Cell variable to compare with
     *
     * @return Return a positive value if | op1 | > | op2 |, zero if | op1 | = | op2 |, or a negative value if | op1 | < | op2 |
     */
    cell bigint_cmpabs(bigint_ptr_t op1, cell op2);

    /**
     * Compare an absolute BigInt with another absolute BigInt variable
     *
     * @param op1 Left BigInt variable
     * @param op2 Right BigInt variable
     *
     * @return Return a positive value if | op1 | > | op2 |, zero if | op1 | = | op2 |, or a negative value if | op1 | < | op2 |
     */
    cell bigint_cmpabs_bi(bigint_ptr_t op1, bigint_ptr_t op2);
};

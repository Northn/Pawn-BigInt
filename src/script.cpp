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

#include "script.h"

#include <cmath>
#include <limits>

bigint_ptr_result_t script::bigint_create(cell initial) {
    return reinterpret_cast<bigint_ptr_result_t>(new bigint_t(static_cast<bigint_t>(initial)));
}

bigint_ptr_result_t script::bigint_create_bi(bigint_ptr_t initial) {
    return reinterpret_cast<bigint_ptr_result_t>(new bigint_t(*initial));
}

bigint_ptr_result_t script::bigint_create_str(std::string initial) {
    if (initial.empty()) {
        return INVALID_BIGINT;
    }
    bigint_t value = 0;
#ifdef _HAS_EXCEPTIONS
    try {
#endif
        value = std::stoll(initial);
#ifdef _HAS_EXCEPTIONS
    } catch (const std::exception &e) {
        return INVALID_BIGINT;
    }
#endif
    return reinterpret_cast<bigint_ptr_result_t>(new bigint_t(value));
}

cell script::bigint_destroy(bigint_ptr_t bigint) {
    if (bigint == INVALID_BIGINT) return 0;
    delete reinterpret_cast<bigint_t *>(bigint);
    return 1;
}

cell script::bigint_set(bigint_ptr_t bigint, cell value) {
    *bigint = static_cast<bigint_t>(value);
    return 1;
}

cell script::bigint_set_bi(bigint_ptr_t bigint, bigint_ptr_t value) {
    *bigint = *value;
    return 1;
}

cell script::bigint_set_str(bigint_ptr_t bigint, std::string value) {
    if (value.empty()) {
        return 0;
    }
#ifdef _HAS_EXCEPTIONS
    try {
#endif
        const auto val = std::stoll(value);
        *bigint = static_cast<bigint_t>(val);
#ifdef _HAS_EXCEPTIONS
    } catch (const std::exception &e) {
        return 0;
    }
#endif
    return 1;
}

cell script::bigint_get(bigint_ptr_t bigint) {
    return static_cast<cell>(*bigint);
}

cell script::bigint_get_str(bigint_ptr_t bigint, cell *out, cell out_size) {
    const auto str = std::to_string(*bigint);
    if (out_size <= str.size()) { // _<=_ check required for null character at the end of buffer
        return 0;
    }
    SetString(out, str, out_size);
    return 1;
}

cell script::bigint_fits_cell(bigint_ptr_t bigint) {
    return std::numeric_limits<cell>::min() <= *bigint && *bigint <= std::numeric_limits<cell>::max();
}

cell script::bigint_fits_ucell(bigint_ptr_t bigint) {
    return std::numeric_limits<ucell>::min() <= *bigint && *bigint <= std::numeric_limits<ucell>::max();
}

cell script::bigint_is_odd(bigint_ptr_t bigint) {
    return (*bigint % 2) != 0;
}

cell script::bigint_is_even(bigint_ptr_t bigint) {
    return (*bigint % 2) == 0;
}

cell script::bigint_add(bigint_ptr_t op1, cell op2) {
    *op1 += static_cast<bigint_t>(op2);
    return 1;
}

cell script::bigint_add_bi(bigint_ptr_t op1, bigint_ptr_t op2) {
    *op1 += *op2;
    return 1;
}

cell script::bigint_sub(bigint_ptr_t op1, cell op2) {
    *op1 -= static_cast<bigint_t>(op2);
    return 1;
}

cell script::bigint_sub_bi(bigint_ptr_t op1, bigint_ptr_t op2) {
    *op1 -= *op2;
    return 1;
}

cell script::bigint_mul(bigint_ptr_t op1, cell op2) {
    *op1 *= static_cast<bigint_t>(op2);
    return 1;
}

cell script::bigint_mul_bi(bigint_ptr_t op1, bigint_ptr_t op2) {
    *op1 *= *op2;
    return 1;
}

cell script::bigint_div_q(bigint_ptr_t op1, cell op2) {
    const auto res = std::div(*op1, static_cast<bigint_t>(op2));
    *op1 = res.quot;
    return 1;
}

cell script::bigint_div_q_bi(bigint_ptr_t op1, bigint_ptr_t op2) {
    const auto res = std::div(*op1, *op2);
    *op1 = res.quot;
    return 1;
}

cell script::bigint_div_r(bigint_ptr_t op1, cell op2) {
    const auto res = std::div(*op1, static_cast<bigint_t>(op2));
    *op1 = res.rem;
    return 1;
}

cell script::bigint_div_r_bi(bigint_ptr_t op1, bigint_ptr_t op2) {
    const auto res = std::div(*op1, *op2);
    *op1 = res.rem;
    return 1;
}

cell script::bigint_abs(bigint_ptr_t op) {
    *op = std::abs(*op);
    return 1;
}

cell script::bigint_neg(bigint_ptr_t op) {
    *op = -(*op);
    return 1;
}

cell script::bigint_root(bigint_ptr_t op1, cell op2) {
    switch (op2) {
        case 0:
        case 1:
            break;
        case 2:
            *op1 = static_cast<bigint_t>(std::trunc(std::sqrt(*op1)));
            break;
        case 3:
            *op1 = static_cast<bigint_t>(std::trunc(std::cbrt(*op1)));
            break;
        default:
            *op1 = static_cast<bigint_t>(std::trunc(std::pow(*op1, 1.0 / static_cast<double>(op2))));
            break;
    }
    return 1;
}

cell script::bigint_pow(bigint_ptr_t op1, cell op2) {
    *op1 = static_cast<bigint_t>(std::pow(*op1, static_cast<double>(op2)));
    return 1;
}

cell script::bigint_cmp(bigint_ptr_t op1, cell op2) {
    if (*op1 > static_cast<bigint_t>(op2)) return 1;
    else if (*op1 < static_cast<bigint_t>(op2)) return -1;
    return 0;
}

cell script::bigint_cmp_bi(bigint_ptr_t op1, bigint_ptr_t op2) {
    if (*op1 > *op2) return 1;
    else if (*op1 < *op2) return -1;
    return 0;
}

cell script::bigint_cmpabs(bigint_ptr_t op1, cell op2) {
    if (std::abs(*op1) > std::abs(static_cast<bigint_t>(op2))) return 1;
    else if (std::abs(*op1) < std::abs(static_cast<bigint_t>(op2))) return -1;
    return 0;
}

cell script::bigint_cmpabs_bi(bigint_ptr_t op1, bigint_ptr_t op2) {
    if (std::abs(*op1) > std::abs(*op2)) return 1;
    else if (std::abs(*op1) < std::abs(*op2)) return -1;
    return 0;
}

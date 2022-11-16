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

#include "plugin.h"

#define REGISTER_NATIVE(name) RegisterNative<&script::name>(#name)
#define REGISTER_NATIVE_EXPANDED(name) RegisterNative<&script::name, false>(#name)

bool plugin::OnLoad() {
  REGISTER_NATIVE(bigint_create);
  REGISTER_NATIVE(bigint_create_bi);
  REGISTER_NATIVE(bigint_create_str);
  REGISTER_NATIVE(bigint_destroy);
  REGISTER_NATIVE(bigint_set);
  REGISTER_NATIVE(bigint_set_bi);
  REGISTER_NATIVE(bigint_set_str);
  REGISTER_NATIVE(bigint_get);
  REGISTER_NATIVE(bigint_get_str);
  REGISTER_NATIVE(bigint_fits_cell);
  REGISTER_NATIVE(bigint_fits_ucell);
  REGISTER_NATIVE(bigint_is_odd);
  REGISTER_NATIVE(bigint_is_even);
  REGISTER_NATIVE(bigint_add);
  REGISTER_NATIVE(bigint_add_bi);
  REGISTER_NATIVE(bigint_sub);
  REGISTER_NATIVE(bigint_sub_bi);
  REGISTER_NATIVE(bigint_mul);
  REGISTER_NATIVE(bigint_mul_bi);
  REGISTER_NATIVE(bigint_div_q);
  REGISTER_NATIVE(bigint_div_q_bi);
  REGISTER_NATIVE(bigint_div_r);
  REGISTER_NATIVE(bigint_div_r_bi);
  REGISTER_NATIVE(bigint_abs);
  REGISTER_NATIVE(bigint_neg);
  REGISTER_NATIVE(bigint_root);
  REGISTER_NATIVE(bigint_pow);
  REGISTER_NATIVE(bigint_cmp);
  REGISTER_NATIVE(bigint_cmp_bi);
  REGISTER_NATIVE(bigint_cmpabs);
  REGISTER_NATIVE(bigint_cmpabs_bi);

  return true;
}

#undef REGISTER_NATIVE_EXPANDED
#undef REGISTER_NATIVE

const char *plugin::Name() {
  return "YAPJ";
}

int plugin::Version() {
  return PAWN_BIGINT_VERSION;
}

/*
 * Copyright (c) 2012-2015, Nic McDonald
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * - Neither the name of prim nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef BITS_BITS_H_
#error "do not include this file, use the .h instead"
#else  // BITS_BITS_H_

#include <cassert>

namespace bits {

template <typename T>
T pow2(T _uint) {
  assert(_uint < (sizeof(T) * 8));
  return (T)1 << _uint;
}

template <typename T>
bool isPow2(T _uint) {
  return (_uint & (_uint - (T)1)) == 0;
}

template <typename T>
T floorLog2(T _uint) {
  T r = 0;
  while (_uint >>= (T)1) {
    r++;
  }
  return r;
}

template <typename T>
T ceilLog2(T _uint) {
  // top end bail out
  T e = sizeof(T) * 8;
  if (_uint >= ((T)1 << (e - 1))) {
    return e;
  }

  // all but the highest case
  e = 0;
  while (((T)1 << e) < _uint) {
    e++;
  }
  return e;
}

}  // namespace bits

#endif  // BITS_BITS_H_

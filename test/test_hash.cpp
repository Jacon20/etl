/******************************************************************************
The MIT License(MIT)

Embedded Template Library.

Copyright(c) 2014 jwellbelove

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#include <UnitTest++/UnitTest++.h>

#include <iterator>
#include <string>
#include <vector>
#include <stdint.h>

#include "../hash.h"

namespace
{
  SUITE(test_hash)
  {
    //*************************************************************************
    TEST(test_hash_bool)
    {
      size_t hash = etl::hash<bool>()(false);
      CHECK_EQUAL(0, hash);

      hash = etl::hash<bool>()(true);
      CHECK_EQUAL(1, hash);
    }

    //*************************************************************************
    TEST(test_hash_char)
    {
      size_t hash = etl::hash<char>()((char)(0x5A));

      CHECK_EQUAL(0x5A, hash);
    }

    //*************************************************************************
    TEST(test_hash_signed_char)
    {
      size_t hash = etl::hash<signed char>()((signed char)(0x5A));

      CHECK_EQUAL(0x5A, hash);
    }

    //*************************************************************************
    TEST(test_hash_unsigned_char)
    {
      size_t hash = etl::hash<unsigned char>()((unsigned char)(0x5A));

      CHECK_EQUAL(0x5A, hash);
    }

    //*************************************************************************
    TEST(test_hash_short)
    {
      size_t hash = etl::hash<short>()((short)(0x5AA5));

      CHECK_EQUAL(0x5AA5, hash);
    }

    //*************************************************************************
    TEST(test_hash_unsigned_short)
    {
      size_t hash = etl::hash<unsigned short>()((unsigned short)(0x5AA5));

      CHECK_EQUAL(0x5AA5, hash);
    }

    //*************************************************************************
    TEST(test_hash_int)
    {
      size_t hash = etl::hash<int>()((int)(0x5AA555AA));

      CHECK_EQUAL(0x5AA555AA, hash);
    }

    //*************************************************************************
    TEST(test_hash_unsigned_int)
    {
      size_t hash = etl::hash<unsigned int>()((unsigned int)(0x5AA555AA));

      CHECK_EQUAL(0x5AA555AA, hash);
    }

    //*************************************************************************
    TEST(test_hash_long)
    {
      size_t hash = etl::hash<long>()((long)(0x5AA555AA));

      CHECK_EQUAL(0x5AA555AA, hash);
    }

    //*************************************************************************
    TEST(test_hash_unsigned_long)
    {
      size_t hash = etl::hash<unsigned long>()((unsigned long)(0x5AA555AA));

      CHECK_EQUAL(0x5AA555AA, hash);
    }

    //*************************************************************************
    TEST(test_hash_long_long)
    {
      size_t hash = etl::hash<long long>()((long long)(0x5AA555AA3CC333CC));

      CHECK_EQUAL(0xEC6A8D69, hash);
    }

    //*************************************************************************
    TEST(test_hash_unsigned_long_long)
    {
      size_t hash = etl::hash<unsigned long long>()((unsigned long long)(0x5AA555AA3CC333CC));

      CHECK_EQUAL(0xEC6A8D69, hash);
    }

    //*************************************************************************
    TEST(test_hash_float)
    {
      size_t hash = etl::hash<float>()((float)(1.2345));

      CHECK_EQUAL(0x3F9E0419, hash);
    }

    //*************************************************************************
    TEST(test_hash_double)
    {
      size_t hash = etl::hash<double>()((double)(1.2345));

      CHECK_EQUAL(0x86FBF224, hash);
    }

    //*************************************************************************
    TEST(test_hash_pointer)
    {
      int i;
      size_t hash = etl::hash<int*>()(&i);

      CHECK_EQUAL(size_t(&i), hash);
    }
  };
}


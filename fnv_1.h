///\file

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

#ifndef __ETL_FNV_1__
#define __ETL_FNV_1__

#include <stdint.h>

#include "static_assert.h"
#include "type_traits.h"
#include "endian.h"

///\defgroup fnv_1 FNV-1 & FNV-1a 32 & 64 bit hash calculations
///\ingroup maths

namespace etl
{
  //***************************************************************************
  /// Calculates the fnv_1_64 hash.
  ///\tparam ENDIANNESS The endianness of the calculation for input types larger than uint8_t. Default = endian::little.
  ///\ingroup fnv_1_64
  //***************************************************************************
  template <const int ENDIANNESS = endian::little>
  class fnv_1_64
  {
  public:

    typedef uint64_t value_type;

    //*************************************************************************
    /// Default constructor.
    //*************************************************************************
    fnv_1_64()
    {
      reset();
    }

    //*************************************************************************
    /// Constructor from range.
    /// \param begin Start of the range.
    /// \param end   End of the range.
    //*************************************************************************
    template<typename TIterator>
    fnv_1_64(TIterator begin, const TIterator end)
    {
      reset();
      add(begin, end);
    }

    //*************************************************************************
    /// Resets the CRC to the initial state.
    //*************************************************************************
    void reset()
    {
      hash = OFFSET_BASIS;
    }

    //*************************************************************************
    /// \param value The value to add to the fnv_1_64.
    //*************************************************************************
    template<typename TValue>
    void add(TValue value)
    {
      STATIC_ASSERT(is_integral<TValue>::value, "Non-integral parameter");

      if (ENDIANNESS == endian::little)
      {
        for (int i = 0; i < sizeof(TValue); ++i)
        {
          add(uint8_t((value >> (i * 8)) & 0xFF));
        }
      }
      else
      {
        for (int i = sizeof(TValue) - 1; i >= 0; --i)
        {
          add(uint8_t((value >> (i * 8)) & 0xFF));
        }
      }
    }

    //*************************************************************************
    /// \param value The char to add to the fnv_1_64.
    //*************************************************************************
    void add(uint8_t value)
    {
      hash *= PRIME;
      hash ^= value;
    }

    //*************************************************************************
    /// \param begin Start of the range.
    /// \param end   End of the range.
    /// \return The fnv_1_64 result.
    //*************************************************************************
    template<typename TIterator>
    void add(TIterator begin, const TIterator end)
    {
      while (begin != end)
      {
        add(*begin++);
      }
    }

    //*************************************************************************
    /// Gets the fnv_1_64 value.
    //*************************************************************************
    value_type value() const
    {
      return hash;
    }

    //*************************************************************************
    /// \param value The value to add to the fnv_1_64.
    //*************************************************************************
    template<typename TValue>
    fnv_1_64<ENDIANNESS>& operator +=(TValue value)
    {
      add(value);

      return *this;
    }

    //*************************************************************************
    /// Conversion operator to value_type.
    //*************************************************************************
    operator value_type () const
    {
      return hash;
    }

  private:

    value_type hash;

    static const uint64_t OFFSET_BASIS = 0xCBF29CE484222325;
    static const uint64_t PRIME        = 0x00000100000001b3;
  };

  //***************************************************************************
  /// Calculates the fnv_1a_64 hash.
  ///\tparam ENDIANNESS The endianness of the calculation for input types larger than uint8_t. Default = endian::little.
  ///\ingroup fnv_1a_64
  //***************************************************************************
  template <const int ENDIANNESS = endian::little>
  class fnv_1a_64
  {
  public:

    typedef uint64_t value_type;

    //*************************************************************************
    /// Default constructor.
    //*************************************************************************
    fnv_1a_64()
    {
      reset();
    }

    //*************************************************************************
    /// Constructor from range.
    /// \param begin Start of the range.
    /// \param end   End of the range.
    //*************************************************************************
    template<typename TIterator>
    fnv_1a_64(TIterator begin, const TIterator end)
    {
      reset();
      add(begin, end);
    }

    //*************************************************************************
    /// Resets the CRC to the initial state.
    //*************************************************************************
    void reset()
    {
      hash = OFFSET_BASIS;
    }

    //*************************************************************************
    /// \param value The value to add to the fnv_1a_64.
    //*************************************************************************
    template<typename TValue>
    void add(TValue value)
    {
      STATIC_ASSERT(is_integral<TValue>::value, "Non-integral parameter");

      if (ENDIANNESS == endian::little)
      {
        for (int i = 0; i < sizeof(TValue); ++i)
        {
          add(uint8_t((value >> (i * 8)) & 0xFF));
        }
      }
      else
      {
        for (int i = sizeof(TValue) - 1; i >= 0; --i)
        {
          add(uint8_t((value >> (i * 8)) & 0xFF));
        }
      }
    }

    //*************************************************************************
    /// \param value The char to add to the fnv_1a_64.
    //*************************************************************************
    void add(uint8_t value)
    {
      hash ^= value;
      hash *= PRIME;
    }

    //*************************************************************************
    /// \param begin Start of the range.
    /// \param end   End of the range.
    //*************************************************************************
    template<typename TIterator>
    void add(TIterator begin, const TIterator end)
    {
      while (begin != end)
      {
        add(*begin++);
      }
    }

    //*************************************************************************
    /// Gets the fnv_1a_64 value.
    //*************************************************************************
    value_type value() const
    {
      return hash;
    }

    //*************************************************************************
    /// \param value The value to add to the fnv_1a_64.
    //*************************************************************************
    template<typename TValue>
    fnv_1a_64<ENDIANNESS>& operator +=(TValue value)
    {
      add(value);

      return *this;
    }

    //*************************************************************************
    /// Conversion operator to value_type.
    //*************************************************************************
    operator value_type () const
    {
      return hash;
    }

  private:

    value_type hash;

    static const uint64_t OFFSET_BASIS = 0xCBF29CE484222325;
    static const uint64_t PRIME        = 0x00000100000001b3;
  };

  //***************************************************************************
  /// Calculates the fnv_1_32 hash.
  ///\tparam ENDIANNESS The endianness of the calculation for input types larger than uint8_t. Default = endian::little.
  ///\ingroup fnv_1_32
  //***************************************************************************
  template <const int ENDIANNESS = endian::little>
  class fnv_1_32
  {
  public:

    typedef uint32_t value_type;

    //*************************************************************************
    /// Default constructor.
    //*************************************************************************
    fnv_1_32()
    {
      reset();
    }

    //*************************************************************************
    /// Constructor from range.
    /// \param begin Start of the range.
    /// \param end   End of the range.
    //*************************************************************************
    template<typename TIterator>
    fnv_1_32(TIterator begin, const TIterator end)
    {
      reset();
      add(begin, end);
    }

    //*************************************************************************
    /// Resets the CRC to the initial state.
    //*************************************************************************
    void reset()
    {
      hash = OFFSET_BASIS;
    }

    //*************************************************************************
    /// \param value The value to add to the fnv_1_32.
    //*************************************************************************
    template<typename TValue>
    void add(TValue value)
    {
      STATIC_ASSERT(is_integral<TValue>::value, "Non-integral parameter");

      if (ENDIANNESS == endian::little)
      {
        for (int i = 0; i < sizeof(TValue); ++i)
        {
          add(uint8_t((value >> (i * 8)) & 0xFF));
        }
      }
      else
      {
        for (int i = sizeof(TValue) - 1; i >= 0; --i)
        {
          add(uint8_t((value >> (i * 8)) & 0xFF));
        }
      }
    }

    //*************************************************************************
    /// \param value The char to add to the fnv_1_32.
    //*************************************************************************
    void add(uint8_t value)
    {
      hash *= PRIME;
      hash ^= value;
    }

    //*************************************************************************
    /// \param begin Start of the range.
    /// \param end   End of the range.
    //*************************************************************************
    template<typename TIterator>
    void add(TIterator begin, const TIterator end)
    {
      while (begin != end)
      {
        add(*begin++);
      }
    }

    //*************************************************************************
    /// Gets the fnv_1_32 value.
    //*************************************************************************
    value_type value() const
    {
      return hash;
    }

    //*************************************************************************
    /// \param value The value to add to the fnv_1_32.
    //*************************************************************************
    template<typename TValue>
    fnv_1_32<ENDIANNESS>& operator +=(TValue value)
    {
      add(value);

      return *this;
    }

    //*************************************************************************
    /// Conversion operator to value_type.
    //*************************************************************************
    operator value_type () const
    {
      return hash;
    }

  private:

    value_type hash;

    static const uint32_t OFFSET_BASIS = 0x811C9DC5;
    static const uint32_t PRIME        = 0x01000193;
  };

  //***************************************************************************
  /// Calculates the fnv_1a_32 hash.
  ///\tparam ENDIANNESS The endianness of the calculation for input types larger than uint8_t. Default = endian::little.
  ///\ingroup fnv_1a_32
  //***************************************************************************
  template <const int ENDIANNESS = endian::little>
  class fnv_1a_32
  {
  public:

    typedef uint32_t value_type;

    //*************************************************************************
    /// Default constructor.
    //*************************************************************************
    fnv_1a_32()
    {
      reset();
    }

    //*************************************************************************
    /// Constructor from range.
    /// \param begin Start of the range.
    /// \param end   End of the range.
    //*************************************************************************
    template<typename TIterator>
    fnv_1a_32(TIterator begin, const TIterator end)
    {
      reset();
      add(begin, end);
    }

    //*************************************************************************
    /// Resets the CRC to the initial state.
    //*************************************************************************
    void reset()
    {
      hash = OFFSET_BASIS;
    }

    //*************************************************************************
    /// \param value The value to add to the fnv_1a_32.
    //*************************************************************************
    template<typename TValue>
    void add(TValue value)
    {
      STATIC_ASSERT(is_integral<TValue>::value, "Non-integral parameter");

      if (ENDIANNESS == endian::little)
      {
        for (int i = 0; i < sizeof(TValue); ++i)
        {
          add(uint8_t((value >> (i * 8)) & 0xFF));
        }
      }
      else
      {
        for (int i = sizeof(TValue) - 1; i >= 0; --i)
        {
          add(uint8_t((value >> (i * 8)) & 0xFF));
        }
      }
    }

    //*************************************************************************
    /// \param value The char to add to the fnv_1a_32.
    //*************************************************************************
    void add(uint8_t value)
    {
      hash ^= value;
      hash *= PRIME;
    }

    //*************************************************************************
    /// \param begin Start of the range.
    /// \param end   End of the range.
    //*************************************************************************
    template<typename TIterator>
    void add(TIterator begin, const TIterator end)
    {
      while (begin != end)
      {
        add(*begin++);
      }
    }

    //*************************************************************************
    /// Gets the fnv_1a_32 value.
    //*************************************************************************
    value_type value() const
    {
      return hash;
    }

    //*************************************************************************
    /// \param value The value to add to the fnv_1a_32.
    //*************************************************************************
    template<typename TValue>
    fnv_1a_32<ENDIANNESS>& operator +=(TValue value)
    {
      add(value);

      return *this;
    }

    //*************************************************************************
    /// Conversion operator to value_type.
    //*************************************************************************
    operator value_type () const
    {
      return hash;
    }

  private:

    value_type hash;

    static const uint32_t OFFSET_BASIS = 0x811C9DC5;
    static const uint32_t PRIME        = 0x01000193;
  };
}

#endif

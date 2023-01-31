////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <math/preamble.hpp>
#include <math/Vector1.hpp>

namespace yq {

    /*! \brief One dimensional multivector
    */
    template <typename T>
    struct Multivector1 {
        
        //! Captures the template parameter
        using component_type    = T;
    
        //! Scalar
        unity_t<T>  a;
        
        //! X
        T           x;
        
        //! Defaulted equality
        constexpr bool operator==(const Multivector1&) const noexcept = default;

        constexpr Multivector1() noexcept = default;
        constexpr Multivector1(T _a, T _x) noexcept : a(_a), x(_x) {}
        constexpr Multivector1(T _a, const Vector1<T>& v) noexcept : a(_a), x(v.x) {}
        constexpr Multivector1(all_t, T v) noexcept : a(v), x(v) {}
        consteval Multivector1(nan_t) noexcept : Multivector1(ALL, nan_v<T>) {}
        consteval Multivector1(one_t) noexcept : Multivector1(ALL, one_v<T>) {}
        consteval Multivector1(zero_t) noexcept : Multivector1(ALL, zero_v<T>) {}
        
        constexpr Multivector1 operator+() const noexcept;
        constexpr Multivector1 operator-() const noexcept;
        
        constexpr Multivector1 operator+(T  b) const noexcept;
        Multivector1& operator+=(T  b) noexcept;
        constexpr Multivector1 operator+(const Multivector1&  b) const noexcept;
        Multivector1& operator+=(const Multivector1& b) noexcept;
        constexpr Multivector1 operator+(const Vector1<T>&  b) const noexcept;
        Multivector1& operator+=(const Vector1<T>& b) noexcept;
        constexpr Multivector1 operator-(T  b) const noexcept;
        Multivector1& operator-=(T  b) noexcept;
        constexpr Multivector1 operator-(const Multivector1&  b) const noexcept;
        Multivector1& operator-=(const Multivector1& b) noexcept;
        constexpr Multivector1 operator-(const Vector1<T>&  b) const noexcept;
        Multivector1& operator-=(const Vector1<T>& b) noexcept;
        
        template <typename U>
        requires trait::is_arithmetic_v<U>
        constexpr Multivector1<product_t<T,U>> operator*(U b) const noexcept;
        
        template <typename U>
        requires (trait::is_arithmetic_v<U> && trait::self_mul_v<T,U>)
        Multivector1& operator*=(U b) noexcept;

        template <typename U>
        constexpr Multivector1<product_t<T,U>> operator*(const Multivector1<U>& b) const noexcept;

        template <typename U>
        requires trait::self_mul_v<T,U>
        Multivector1<T>& operator*=(const Multivector1<U>& b) noexcept;
        
        template <typename U>
        constexpr Multivector1<product_t<T,U>> operator*(const Vector1<U>& b) const noexcept;
        
        template <typename U>
        requires trait::self_mul_v<T,U>
        Multivector1<T>& operator*=(const Vector1<U>& b) noexcept;

        template <typename U>
        constexpr product_t<T,U>   operator INNER(const Multivector1<U>&b)  const noexcept;

        template <typename U>
        constexpr product_t<T,U>   operator INNER(const Vector1<U>&b) const noexcept;

        template <typename U>
        requires trait::is_arithmetic_v<U>
        constexpr Multivector1<quotient_t<T,U>> operator/(U b) const noexcept;

        template <typename U>
        requires (trait::is_arithmetic_v<U> && trait::self_div_v<T,U>)
        Multivector1<T>& operator/=(U b) noexcept;

        constexpr Vector1<T>  vector() const noexcept;
    };

    YQ_IEEE754_1(Multivector1)

//  --------------------------------------------------------
//  COMPOSITION

    YQ_NAN_1(Multivector1, Multivector1<T>{nan_v<unity_t<T>>, nan_v<T>})
    YQ_ZERO_1(Multivector1, Multivector1<T>{zero_v<unity_t<T>>, zero_v<T>})
    
//  --------------------------------------------------------
//  GETTERS

    //! Extracts the vector part
    template <typename T>
    constexpr Vector1<T> vector(const Multivector1<T>& a) noexcept;

//  --------------------------------------------------------
//  BASIC FUNCTIONS

    YQ_IS_NAN_1(Multivector1, is_nan(v.a) || is_nan(v.x) )
    YQ_IS_FINITE_1(Multivector1, is_finite(v.a) && is_finite(v.x))

//  --------------------------------------------------------
//  --------------------------------------------------------
    
    //! Adds left scalar with right multivector
    template <typename T>
    constexpr Multivector1<T> operator+(T a, const Multivector1<T>& b) noexcept;

    template <typename T>
    constexpr Multivector1<T> operator-(T a, const Multivector1<T>& b) noexcept;

    template <typename T, typename U>
    requires trait::is_arithmetic_v<T>
    constexpr Multivector1<product_t<T,U>> operator*(T a, const Multivector1<U>&b) noexcept;


}

YQ_TYPE_DECLARE(Multivector1D)
YQ_TYPE_DECLARE(Multivector1F)

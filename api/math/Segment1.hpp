////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////
#pragma once

#define YQ_MATH_SEGMENT1_HPP 1

#include <math/preamble.hpp>
#include <math/Vector1.hpp>

namespace yq {
    /*! \brief Data for a segment
    
        \note Can be the vertex themselves, or other data.
    */
    template <typename T>
    struct Segment1 {
    
        //! Capture the template parameter
        using component_type    = T;
        
        Vector1<T>   a, b;
        
        constexpr Segment1() noexcept = default;
        constexpr Segment1(const Vector1<T>& _a, const Vector1<T>& _b) : a(_a), b(_b) {}
        template <typename=void> requires has_nan_v<T>
        constexpr Segment1(nan_t) : Segment1( Vector1<T>(NAN), Vector1<T>(NAN)) {}
        constexpr Segment1(zero_t) : Segment1( Vector1<T>(ZERO), Vector1<T>(ZERO)) {}
        
        template <typename U>
        requires std::is_nothrow_convertible_v<T,U>
        explicit constexpr operator Segment1<U>() const noexcept
        {
            return { (Vector1<U>) a, (Vector1<U>) b };
        }
        
        template <typename U>
        requires (std::is_convertible_v<T,U> && !std::is_nothrow_convertible_v<T,U>)
        explicit constexpr operator Segment1<U>() const 
        {
            return { (Vector1<U>) a, (Vector1<U>) b };
        }

        //! Defaulted equality operator
        constexpr bool operator==(const Segment1&) const noexcept = default;
        
        constexpr operator SegmentData<Vector1<T>>() const noexcept;
        
        constexpr Segment1      operator+() const noexcept;
        constexpr Segment1      operator-() const noexcept;
        
        
        Segment1                operator+(const Vector1<T>&) const noexcept;
        Segment1                operator-(const Vector1<T>&) const noexcept;
        
        Segment1&               operator+=(const Vector1<T>&) noexcept;
        Segment1&               operator-=(const Vector1<T>&) noexcept;
        
        template <typename U>
        requires is_arithmetic_v<U>
        constexpr Segment1<product_t<T,U>>    operator*(U) const noexcept;
        
        template <typename U>
        requires (is_arithmetic_v<U> && self_mul_v<T,U>)
        Segment1<T>&                operator*=(U)  noexcept;
        

        template <typename U>
        Segment1<product_t<T,U>>    operator*(const Tensor11<U>&) const noexcept;

        template <typename U>
        Segment2<product_t<T,U>>    operator*(const Tensor12<U>&) const noexcept;

        template <typename U>
        Segment3<product_t<T,U>>    operator*(const Tensor13<U>&) const noexcept;

        template <typename U>
        Segment4<product_t<T,U>>    operator*(const Tensor14<U>&) const noexcept;
        
        template <typename U>
        requires self_mul_v<T,U>
        Segment1&                   operator*=(const Tensor11<U>&) noexcept;

        template <typename U>
        requires is_arithmetic_v<U>
        constexpr Segment1<quotient_t<T,U>>   operator/(U) const noexcept;
        
        template <typename U>
        requires (is_arithmetic_v<U> && self_div_v<T,U>)
        Segment1<T>&                operator/=(U)  noexcept;

        constexpr AxBox1<T>     bounds() const noexcept;
        
        //! Net displacement
        constexpr Vector1<T>  delta() const noexcept;

        //! Computes the fraction along the segment for given X value
        Expect<unity_t<T>>   fraction_x(T, T ep=zero_v<T>) const noexcept;

        //! Length of the segment
        T   length() const;

        //! Square of the length
        constexpr square_t<T> length²() const noexcept;
        
        //! Segment mid-point
        Vector1<T>  midpoint() const;
        
        /*! \brief Computes a point along the segment based on a fractional position
        
            \param[in]  f   Fractional point
        */
        template <typename=void>
        requires has_ieee754_v<T>
        constexpr Vector1<T>     point(ieee754_t<T> f) const noexcept;
    };

    YQ_INTEGER_1(Segment1)
    YQ_IS_INTEGER_1(Segment1)
    YQ_IEEE754_1(Segment1)

//  --------------------------------------------------------
//  COMPOSITION

    /*! \brief Creates a segment from two points
    */
    template <typename T>
    constexpr Segment1<T> segment(const Vector1<T>& a, const Vector1<T>& b) noexcept
    {
        return Segment1<T>( a, b );
    }

    YQ_NAN_1(Segment1, Segment1<T>(NAN));
    YQ_ZERO_1(Segment1, Segment1<T>(ZERO));

//  --------------------------------------------------------
//  --------------------------------------------------------

    YQ_IS_FINITE_1( Segment1, is_finite(v.a) && is_finite(v.b))
    YQ_IS_NAN_1(Segment1, is_nan(v.a) || is_nan(v.b))
    
    template <typename T, typename U>
    requires is_arithmetic_v<T,U>
    constexpr Segment1<product_t<T,U>> operator*(T, const Segment1<T>&) noexcept;

    /*! \brief Creates an axially aligned bounding box from a segment
    */
    template <typename T>
    constexpr AxBox1<T>   aabb(const Segment1<T>& seg) noexcept;


    /*! \brief Computes the length of the segment
    */
    template <typename T>
    T       length(const Segment1<T>& seg);
    
    /*! \brief Computes the midpoint of the segment
    */
    template <typename T>
    constexpr Vector1<T>     midpoint(const Segment1<T>& seg) noexcept;

    /*! \brief Computes a point along the segment based on a fractional position
    
        \param[in]  seg Segment
        \param[in]  f   Fractional point
    */
    template <typename T>
    requires has_ieee754_v<T>
    constexpr Vector1<T>     point(const Segment1<T>& seg, ieee754_t<T> f) noexcept;

}
YQ_TYPE_DECLARE(yq::Segment1D)
YQ_TYPE_DECLARE(yq::Segment1F)
YQ_TYPE_DECLARE(yq::Segment1I)
YQ_TYPE_DECLARE(yq::Segment1U)


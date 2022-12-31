////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#define YQ__API__MATH__VECTOR_4__HPP 1
#include <math/preamble.hpp>
#include <math/Units.hpp>
#include <math/trig.hpp>

namespace yq {

    template <typename T> constexpr Vector4<T> operator-(const Vector4<T>& a, const Vector4<T>& b) noexcept;
    
    /*! \brief Vector of 4 dimensions
    
        This is a 4 dimensional cartesian vector of the given type.
        \tparam[T]  Data type to be used, recommended to be arithmetic in nature
    */
    template <typename T>
    struct Vector4 {
        //! Component data type argument to this structure (ie, template parameter T)
        using component_type = T;
        
        /*! \brief Creates a unit-vector in the x-dimension.
        */
        static consteval Vector4 unit_x() noexcept;
        /*! \brief Creates a unit-vector in the y-dimension.
        */
        static consteval Vector4 unit_y() noexcept;
        /*! \brief Creates a unit-vector in the z-dimension.
        */
        static consteval Vector4 unit_z() noexcept;
        /*! \brief Creates a unit-vector in the w-dimension.
        */
        static consteval Vector4 unit_w() noexcept;

        T       x;
        T       y;
        T       z;
        T       w;;
        
        //! Equality operator (using default)
        constexpr bool operator==(const Vector4&) const noexcept = default;
        
        //! Affirmation (positive) operator
        constexpr Vector4 operator+() const noexcept
        {
            return *this;
        }

        //! Negation
        constexpr Vector4 operator-() const noexcept
        {
            return {-x,-y,-z,-w};
        }

        //! Normalization
        Vector4<quotient_t<T,T>> operator~() const
        {
            auto l = one_v<T>/length();
            return {x/l, y/l, z/l, w/l};
        }

        //! Conversion to GLM library
        constexpr operator glm::vec<4, T, glm::defaultp>() const noexcept
        {
            return { x, y, z, w };
        }

        constexpr Vector4 operator+(const Vector4& b) const noexcept
        {
            return {x+b.x, y+b.y, z+b.z, w+b.w};
        }

        Vector4& operator+=(const Vector4& b) noexcept
        {
            x += b.x;
            y += b.y;
            z += b.z;
            w += b.w;
            return *this;
        }

        constexpr Vector4 operator-(const Vector4& b) const noexcept
        {
            return {x-b.x, y-b.y, z-b.z, w-b.w};
        }
        
        Vector4& operator-=(const Vector4& b) noexcept
        {
            x -= b.x;
            y -= b.y;
            z -= b.z;
            w -= b.w;
            return *this;
        }

        //! TRUE if every component of a is less than b
        constexpr bool operator<<(const Vector4& b) const noexcept
        {
            return (x<b.x) && (y<b.y) && (z<b.z) && (w<b.w);
        }

        //! TRUE if every component of a is less than b
        constexpr bool operator<<(T b) const noexcept
        {
            return (x<b) && (y<b) && (z<b) && (w<b);
        }

        //! TRUE if every component of a is less than b
        friend constexpr bool operator<<(T a, const Vector4& b) noexcept
        {
            return (a<b.x) && (a<b.y) && (a<b.z) && (a<b.w);
        }

        //! TRUE if every component of a is less than (or equal to) b
        constexpr bool operator<<=(const Vector4& b) const noexcept
        {
            return (x<=b.x) && (y<=b.y) && (z<=b.z) && (w<=b.w);
        }

        //! TRUE if every component of a is less than (or equal to) b
        constexpr bool operator<<=(T b) const noexcept
        {
            return (x<=b) && (y<=b) && (z<=b) && (w<=b);
        }

        //! TRUE if every component of a is less than (or equal to) b
        friend constexpr bool operator<<=(T a, const Vector4& b) noexcept
        {
            return (a<=b.x) && (a<=b.y) && (a<=b.z) && (a<=b.w);
        }

        //! TRUE if every component of a is greater than b
        constexpr bool operator>>(const Vector4& b) const noexcept
        {
            return (x>b.x) && (y>b.y) && (z>b.z) && (w>b.w);
        }

        //! TRUE if every component of a is greater than b
        constexpr bool operator>>(T b) const noexcept
        {
            return (x>b) && (y>b) && (z>b) && (w>b);
        }

        //! TRUE if every component of a is greater than b
        friend constexpr bool operator>>(T a, const Vector4& b) noexcept
        {
            return (a>b.x) && (a>b.y) && (a>b.z) && (a>b.w);
        }

        //! TRUE if every component of a is greater or equal to b
        constexpr bool operator>>=(const Vector4& b) const noexcept
        {
            return (x>=b.x) && (y>=b.y) && (z>=b.z) && (w>=b.w);
        }

        template <typename R>
        bool close(const Vector4& expected, const R& compare)
        {
            return compare((*this-expected).length(), expected.length());
        }

        constexpr T             cmax() const noexcept
        {
            return max(max(x, y), max(z, w));
        }

        constexpr T             cmin() const noexcept
        {
            return min(min(x, y), min(z, w));
        }

        constexpr fourth_t<T>   cproduct() const noexcept
        {
            return x*y*z*w;
        }

        constexpr T             csum() const noexcept
        {
            return x + y + z + w;
        }

        constexpr Vector4   eabs() const noexcept
        {
            return { abs(x), abs(y), abs(z), abs(w) };
        }

        //! Element by element division
        template <typename U>
        constexpr Vector4<quotient_t<T,U>>  ediv(const Vector4&b) const noexcept
        {
            return {x/b.x, y/b.y, z/b.z, w/b.w};
        }

        constexpr Vector4   emax(const Vector4<T>&b) const noexcept
        {
            return {max(x, b.x) && max(y, b.y) && max(z, b.z) && max(w, b.w)};
        }
        
        constexpr Vector4   emin(const Vector4<T>&b) const noexcept
        {
            return {min(x, b.x) && min(y, b.y) && min(z, b.z) && min(w, b.w)};
        }

        //! Element by element multiplication
        template <typename U>
        constexpr Vector4<product_t<T,U>>   emul(const Vector4&b) const noexcept
        {
            return {x*b.x, y*b.y, z*b.z, w*b.w};
        }

        /*! \brief Square of the vector's length
        
            This returns the SQUARE of the given vector's length.
        */
        constexpr square_t<T> length²() const noexcept
        {
            return x*x + y*y + z*z + w*w;
        }    

        /*! \brief Length of the vector
            
            This returns the length of the given vector.
        */
        T    length() const
        {
            if constexpr (trait::has_sqrt_v<T>)
                return sqrt(length²());
            return {};
        }
    };
    
    YQ_IEEE754_1(Vector4)
    

//  --------------------------------------------------------
//  COMPOSITION

    /*! \brief Creates a 4 dimensional vector
    
        Helper function to create a 4 dimensional cartesian vector where the component type is deduced from
        the first argument.
    */
    template <typename T>
    constexpr Vector4<T> vector(T x, std::type_identity_t<T> y, std::type_identity_t<T> z, std::type_identity_t<T> w) noexcept
    {
        return {x,y,z,w};
    }
    
    template <typename T, glm::qualifier Q>
    constexpr Vector4<T> vector(const glm::vec<4,T,Q>& v) noexcept
    {
        return { v.x, v.y, v.z, v.w };
    }

    template <typename T>
    consteval Vector4<T> Vector4<T>::unit_x() noexcept
    {
        return {one_v<T>,zero_v<T>,zero_v<T>,zero_v<T>};
    }

    template <typename T>
    consteval Vector4<T> Vector4<T>::unit_y() noexcept
    {
        return {zero_v<T>,one_v<T>,zero_v<T>,zero_v<T>};
    }

    template <typename T>
    consteval Vector4<T> Vector4<T>::unit_z() noexcept
    {
        return {zero_v<T>,zero_v<T>,one_v<T>,zero_v<T>};
    }

    template <typename T>
    consteval Vector4<T> Vector4<T>::unit_w() noexcept
    {
        return {zero_v<T>,zero_v<T>,zero_v<T>,one_v<T>};
    }

    constexpr Vector4D operator "" _x4(unsigned long long int v) noexcept
    {
        return {(double) v, 0., 0., 0.};
    }

    constexpr Vector4D operator "" _x4(long double v) noexcept
    {
        return {(double) v, 0., 0., 0.};
    }

    constexpr Vector4D operator "" _y4(unsigned long long int v) noexcept
    {
        return {0., (double) v, 0., 0.};
    }

    constexpr Vector4D operator "" _y4(long double v) noexcept
    {
        return {0., (double) v, 0., 0.};
    }

    constexpr Vector4D operator "" _z4(unsigned long long int v) noexcept
    {
        return {0., 0., (double) v, 0.};
    }

    constexpr Vector4D operator "" _z4(long double v) noexcept
    {
        return {0., 0., (double) v, 0.};
    }

    constexpr Vector4D operator "" _w4(unsigned long long int v) noexcept
    {
        return {0., 0., 0., (double) v};
    }

    constexpr Vector4D operator "" _w4(long double v) noexcept
    {
        return {0., 0., 0., (double) v};
    }

    YQ_NAN_1(Vector4, Vector4<T>{nan_v<T>, nan_v<T>, nan_v<T>, nan_v<T>})
    YQ_ONE_1(Vector4, Vector4<T>{one_v<T>, one_v<T>, one_v<T>, one_v<T>})
    YQ_ZERO_1(Vector4, Vector4<T>{zero_v<T>, zero_v<T>, zero_v<T>, zero_v<T>})
    
//  --------------------------------------------------------
//  BASIC FUNCTIONS

    YQ_IS_NAN_1(Vector4, is_nan(v.x) || is_nan(v.y) || is_nan(v.z) || is_nan(v.w))
    YQ_IS_FINITE_1(Vector4, is_finite(v.x) && is_finite(v.y) && is_finite(v.z) && is_finite(v.w))

    /*! \brief Square of the vector's length
    
        This returns the SQUARE of the given vector's length.
    */
    template <typename T>
    constexpr square_t<T> length²(const Vector4<T>& a) noexcept
    {
        return a.length²();
    }    

    /*! \brief Length of the vector
        
        This returns the length of the given vector.
    */
    template <typename T>
    auto    length(const Vector4<T>& a)
    {
        return a.length();
    }

//  --------------------------------------------------------
//  MULTIPLICATION

    template <typename T, typename U>
    requires (std::is_arithmetic_v<T>)
    constexpr Vector4<product_t<T,U>> operator*(T a, const Vector4<U>&b) noexcept
    {
        return {a*b.x, a*b.y, a*b.z, a*b.w};
    }
    
    template <typename T, typename U>
    requires (std::is_arithmetic_v<U>)
    constexpr Vector4<product_t<T,U>> operator*(const Vector4<T>& a, U b) noexcept
    {
        return {a.x*b, a.y*b, a.z*b, a.w*b};
    }

    template <typename T, typename U>
    requires (std::is_arithmetic_v<U> && trait::self_mul_v<T,U>)
    Vector4<T>& operator*=(Vector4<T>& a, T b) noexcept
    {
        a.x *= b;
        a.y *= b;
        a.z *= b;
        a.w *= b;
        return a;
    }

    template <typename T, typename U>
    constexpr Vector4<product_t<T,U>>    mul_elem(const Vector4<T>&a, const Vector4<T>&b) noexcept
    {
        return a.emul(b);
    }
    
//  --------------------------------------------------------
//  DIVISION

    template <typename T, typename U>
    requires (std::is_arithmetic_v<T>)
    constexpr  Vector4<quotient_t<T,U>> operator/(T a, const  Vector4<U>&b) noexcept
    {
        return (a*b) / length2(b);
    }

    template <typename T, typename U>
    requires (std::is_arithmetic_v<U>)
    constexpr  Vector4<quotient_t<T,U>> operator/(const  Vector4<T>& a, U b) noexcept
    {
        return {a.x / b, a.y / b, a.z / b, a.w / b};
    }
    
    template <typename T, typename U>
    requires (std::is_arithmetic_v<U> && trait::self_div_v<T,U>)
    Vector4<T>& operator/=(Vector4<T>& a, U b) noexcept
    {
        a.x /= b;
        a.y /= b;
        a.z /= b;
        a.w /= b;
        return a;
    }
    
    template <typename T, typename U>
    constexpr Vector4<quotient_t<T,U>>    div_elem(const Vector4<T>&a, const Vector4<T>&b) noexcept
    {
        return a.ediv(b);
    }

//  --------------------------------------------------------
//  POWERS

    template <typename T>
    constexpr square_t<T> operator^(const Vector4<T>& a,two_t) noexcept
    {
        return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
    }    

//  --------------------------------------------------------
//  DOT PRODUCT

    template <typename T, typename U>
    constexpr product_t<T,U> operator DOT (const Vector4<T>& a, const Vector4<U>&b) noexcept
    {
        return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
    }

//  --------------------------------------------------------
//  INNER PRODUCT

    template <typename T, typename U>
    constexpr product_t<T,U> operator INNER (const Vector4<T>& a, const Vector4<U>&b) noexcept
    {
        return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
    }

//  --------------------------------------------------------
//  OUTER PRODUCT


//  --------------------------------------------------------
//  CROSS PRODUCT


///  --------------------------------------------------------
//  OTIMES PRODUCT

//  --------------------------------------------------------
//  PROJECTIONS

//  --------------------------------------------------------
//  ADVANCED FUNCTIONS

    template <typename T>
    constexpr Vector4<T>   abs_elem(const Vector4<T>&a) noexcept
    {
        return a.eabs();
    }

    //! TRUE if every component of a is greater than b
    template <typename T>
    constexpr bool        all_greater(const Vector4<T>& a, const Vector4<T>&b) noexcept
    {
        return a >> b;
    }

    //! TRUE if every component of a is greater or equal to b
    template <typename T>
    constexpr bool        all_greater_equal(const Vector4<T>& a, const Vector4<T>&b) noexcept
    {
        return a >>= b;
    }
    
    //! TRUE if every component of a is less than b
    template <typename T>
    constexpr bool        all_less(const Vector4<T>& a, const Vector4<T>&b) noexcept
    {
        return a << b;
    }

    //! TRUE if every component of a is less than (or equal to) b
    template <typename T>
    constexpr bool        all_less_equal(const Vector4<T>& a, const Vector4<T>&b) noexcept
    {
        return a <<= b;
    }

    template <typename T>
    requires (std::is_floating_point_v<T> && trait::has_sqrt_v<T>)
    Radian       angle(const Vector4<T>&a, const Vector4<T>& b)
    {
        return acos( std::clamp<T>( (a*b)/(length(a)*length(b)), -one_v<T>, one_v<T>));
    }
    
    template <typename T, typename DIM1, typename DIM2>
    requires (std::is_floating_point_v<T> && trait::has_sqrt_v<T>)
    Radian       angle(const Vector4<MKS<T,DIM1>>&a, const Vector4<MKS<T,DIM2>>& b)
    {
        using one_t = MKS<T,dim::None>;
        return acos( std::clamp<one_t>( (a*b)/(length(a)*length(b)), -one_v<T>, one_v<T>));
    }

    template <typename T>
    constexpr T             component_max(const Vector4<T>&a) noexcept
    {
        return a.cmax();
    }

    template <typename T>
    constexpr T             component_min(const Vector4<T>&a) noexcept
    {
        return a.cmin();
    }

    template <typename T>
    constexpr fourth_t<T>     component_product(const Vector4<T>& a) noexcept
    {
        return a.cproduct();
    }

    template <typename T>
    constexpr T   component_sum(const Vector4<T>& a) noexcept
    {
        return a.csum();
    }

    template <typename T, typename R>
    bool is_close(const R& compare, const Vector4<T>& actual, const Vector4<T>& expected)
    {
        return compare(length(actual-expected), length(expected));
    }
    
    template <typename T, typename R>
    bool is_close(const R& compare, const Vector4<T>& actual, std::type_identity_t<T> x, std::type_identity_t<T> y, std::type_identity_t<T> z,std::type_identity_t<T>w)
    {
        return is_close(compare, actual, Vector4<T>{x, y, z, w} );
    }

    
    template <typename T>
    constexpr Vector4<T>   max_elem(const Vector4<T>&a, const Vector4<T>&b) noexcept
    {
        return a.emax(b);
    }
    
    template <typename T>
    constexpr Vector4<T>   min_elem(const Vector4<T>&a, const Vector4<T>&b) noexcept
    {
        return a.emin(b);
    }

    /*! \brief Mid-way divide two vectors
    */
    template <typename T>
    constexpr T     midvector(const Vector4<T>& a, const Vector4<T>& b=Vector4<T>{}) noexcept
    {
        if constexpr (has_ieee754_v<T>)
            return ieee754_t<T>(0.5)*(a+b);
        else if constexpr (std::is_integral_v<T>)
            return (a+b) / T(2);
        else
            return {};
    }
}

YQ_TYPE_DECLARE(yq::Vector4D)
YQ_TYPE_DECLARE(yq::Vector4F)
YQ_TYPE_DECLARE(yq::Vector4I)
YQ_TYPE_DECLARE(yq::Vector4U)


////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/math/preamble.hpp>
#include <yq/coord/Coord3.hpp>

namespace yq {
    YQ_NAN_1(Coord3, Coord3<T>(ALL, nan_v<T> ))
    YQ_IS_NAN_1(Coord3, is_nan(v.i) || is_nan(v.j) || is_nan(v.k))
    YQ_IS_FINITE_1(Coord3, is_finite(v.i) && is_finite(v.j) && is_finite(v.k))
    YQ_ZERO_1(Coord3, Coord3<T>( ZERO ))
}

////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/meta/InfoBinder.hpp>

namespace yq {
    YQ_ENUM( CalendarType, ,
        None        = 0,
        Julian,
        Gregorian
    )
}
YQ_TYPE_DECLARE(yq::CalendarType)

////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq { 
    template <typename> class Ref;
}

namespace yq::post {
    class Event;
    using EventPtr      = Ref<Event>;
    using EventCPtr     = Ref<const Event>;
}

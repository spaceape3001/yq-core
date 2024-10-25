////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Reply.hpp>
#include <string>
#include <string_view>

namespace yq::post {

    //! Test post type that carries a string 
    class StringReply : public Reply {
        YQ_OBJECT_DECLARE(StringReply, Reply)
    public:
    
        using text_t    = std::variant<std::monostate, const char*, std::string_view, std::string>;
        
        using Reply::Param;
        
        StringReply(const RequestCPtr&, std::string&&, const Param& p = {});
        StringReply(const RequestCPtr&, const char*, const Param& p = {});
        StringReply(const RequestCPtr&, std::string_view, const Param& p = {});
        ~StringReply(){}
    
        const std::string&    text() const { return m_text; }
    
    private:
        std::string     m_text;
    };
}

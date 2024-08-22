////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/errors.hpp>
#include <0/basic/Stack.hpp>
#include <0/math/expr/Instruction.hpp>

namespace yq::expr {
    class DuplicateInstruction : public Instruction {
    public:
        DuplicateInstruction(const string_t s);
        ~DuplicateInstruction(){}
        
        virtual std::error_code     execute(any_stack_t&values, Context&) const override;
        
        virtual result_t   result() const override;
        virtual result_t    result(std::span<const TypeInfo*>) const;

        uint16_t            pop_count() const override { return 0; }
        uint16_t            push_count() const override { return 1; }
    };
}

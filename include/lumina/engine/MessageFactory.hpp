#pragma once

#include <memory>

#include "./Message.hpp"

namespace lumina
{
    class MessageFactory
    {
    private:
        
    public:
        virtual ~MessageFactory() = default;
        std::shared_ptr<Message> createMessage();
    };
    
} // namespace lumina

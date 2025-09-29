#pragma once
#include <string>
#include <stdexcept>

namespace Protocol
{
    enum class MsgType
    {
        Ping,
        Pong
    };

    inline std::string encode(MsgType type)
    {
        switch (type)
        {
        case MsgType::Ping: return "PING";
        case MsgType::Pong: return "PONG";
        default: throw std::runtime_error("UnknownMsgType");
            
        }
    }

    inline MsgType decode(const std::string& data)
    {
        if(data == "PING") return MsgType::Ping;
        if(data=="PONG") return MsgType::Pong;
        throw std::runtime_error("UnknownMessage"+ data);
    }


};
#pragma once
#include "Message.hpp"

void read_update_msg(Message& msg);

namespace __serial {
    void update_msg(Message& msg, uint8_t data);
}
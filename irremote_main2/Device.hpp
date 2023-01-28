#pragma once
#include "Message.hpp"

class Device {
public:
    // コンストラクタ
    Device() = default;
    Device(const Device&) = delete;
    // コピー代入演算子
    Device& operator=(const Device&) = delete;
    // デストラクタ
    virtual ~Device() = default;
private:
    virtual void update(Message& msg) = 0;
};
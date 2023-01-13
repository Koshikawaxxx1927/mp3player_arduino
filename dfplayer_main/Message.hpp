#pragma once

typedef struct extends {
    enum class Type {
        Play,
    } type;
    union {
        int data;
    };
} Message;
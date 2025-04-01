#define _CRT_SECURE_NO_WARNINGS
#include "JsonValue.h"
#include <cstring>

JsonValue::~JsonValue() {}

void NullValue::print(std::ostream& out) {
    out << "null";
}

NumberValue::NumberValue(int nr) : value(nr) {}

void NumberValue::print(std::ostream& out) {
    out << value;
}

BoolValue::BoolValue(bool nr) : value(nr) {}

void BoolValue::print(std::ostream& out) {
    out << (value ? "true" : "false");
}

StringValue::StringValue(const char* a) {
    value = new char[strlen(a) + 1];
    strcpy(value, a);
}

StringValue::~StringValue() {
    delete[] value;
}

void StringValue::print(std::ostream& out) {
    out << "\"" << value << "\"";
}

ArrayValue::ArrayValue() : v(nullptr), size(0) {}

ArrayValue::~ArrayValue() {
    for (unsigned long long i = 0; i < size; ++i) {
        delete v[i];
    }
    delete[] v;
}

void ArrayValue::add(JsonValue* J) {
    JsonValue** w = new JsonValue * [size + 1];
    for (unsigned long long i = 0; i < size; ++i) {
        w[i] = v[i];
    }
    w[size] = J;
    delete[] v;
    v = w;
    size++;
}

void ArrayValue::print(std::ostream& out) {
    out << "[";
    for (unsigned long long i = 0; i < size; ++i) {
        if (i > 0) out << ", ";
        v[i]->print(out);
    }
    out << "]";
}


void Pair::add(const char* a, JsonValue* b) {
    str = new char[strlen(a) + 1];
    strcpy(str, a);
    value = b;
}

ObjectValue::ObjectValue() : v(nullptr), size(0) {}

ObjectValue::~ObjectValue() {
    for (unsigned long long i = 0; i < size; ++i) {
        delete v[i].value;
    }
    delete[] v;
}

void ObjectValue::add(const char* str, JsonValue* value) {
    Pair* p = new Pair[size + 1];
    for (unsigned long long i = 0; i < size; ++i) {
        p[i] = v[i];
    }
    p[size].add(str, value);
    delete[] v;
    v = p;
    size++;
}

void ObjectValue::print(std::ostream& out) {
    out << "{";
    for (unsigned long long i = 0; i < size; ++i) {
        if (i > 0) out << ", ";
        out << "\"" << v[i].str << "\": ";
        v[i].value->print(out);
    }
    out << "}";
}

#pragma once
#include <ostream>
class JsonValue {
public:
    virtual ~JsonValue() = 0;

    virtual void print(std::ostream& out) = 0;
};

class NullValue : public JsonValue {
public:
    void print(std::ostream& out) override;
};

class NumberValue : public JsonValue {
private:
    int value;
public:
    NumberValue(int);
    void print(std::ostream& out) override;
};

class BoolValue : public JsonValue {
    bool value;
public:
    BoolValue(bool);
    void print(std::ostream& out) override;
};

class StringValue : public JsonValue {
private:
    char* value;
public:
    StringValue(const char*);
    ~StringValue();
    void print(std::ostream& out) override;
};

class ArrayValue : public JsonValue {
private:
    JsonValue** v;
    unsigned long long size;
public:
    ArrayValue();
    ~ArrayValue();
    void add(JsonValue*);
    void print(std::ostream& out) override;
    operator unsigned() const { return size; }
};


class Pair {
public:
    char* str;
    JsonValue* value;
    void add(const char* a, JsonValue* b);
};

class ObjectValue : public JsonValue {
private:
    Pair* v;
    unsigned long long size;
public:
    ObjectValue();
    ~ObjectValue();
    void add(const char *, JsonValue*);
    void print(std::ostream& out) override;
    operator unsigned() const { return size; }
};

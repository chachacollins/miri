#ifndef OBJECT_H
#define OBJECT_H
#include "object.h"
#include "value.h"

#define OBJ_TYPE(value)        (AS_OBJ(value)->type)
#define IS_STRING(value)       is_ObjType(value, OBJ_STRING)
#define AS_STRING(value)       ((ObjString*)AS_OBJ(value))
#define AS_CSTRING(value)      (((ObjString*)AS_OBJ(value))->chars)

typedef enum
{
    OBJ_STRING,
}ObjType;

struct Obj
{
    ObjType type;
};

struct ObjString
{
    Obj obj;
    char *chars;
    int length;
};

static inline bool is_ObjType(Value value, ObjType type) 
{
  return IS_OBJ(value) && AS_OBJ(value)->type == type;
}

ObjString *copy_string(const char *chars, int length);
ObjString *take_string(char *chars, int length);
void print_object(Value value);
#endif

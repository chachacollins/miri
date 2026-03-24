#ifndef VALUE_H
#define VALUE_H

typedef enum
{
    VAL_BOOL,
    VAL_NIL,
    VAL_NUMBER,
} ValueType;

typedef struct
{
    ValueType type;
    union
    {
        bool boolean;
        double number;
    } as;
} Value;

#define BOOL_VAL(value)   ((Value){VAL_BOOL, {.boolean = value}})
#define NIL_VAL           ((Value){VAL_NIL, {.number = 0}})
#define NUMBER_VAL(value) ((Value){VAL_NUMBER, {.number = value}})
#define AS_BOOL(value)    ((value).as.boolean)
#define AS_NUMBER(value)  ((value).as.number)
#define IS_BOOL(value)    ((value).type == VAL_BOOL)
#define IS_NIL(value)     ((value).type == VAL_NIL)
#define IS_NUMBER(value)  ((value).type == VAL_NUMBER)

typedef struct
{
    Value *values;
    int count;
    int capacity;
} ValueArray;

bool values_equal(Value a, Value b);
void init_ValueArray(ValueArray *array);
void write_ValueArray(ValueArray *array, Value value);
void free_ValueArray(ValueArray *array);
void print_value(Value value);
#endif

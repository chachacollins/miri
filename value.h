#ifndef VALUE_H
#define VALUE_H

typedef double Value;

typedef struct
{
    Value *values;
    int count;
    int capacity;
} ValueArray;

void init_ValueArray(ValueArray *array);
void write_ValueArray(ValueArray *array, Value value);
void free_ValueArray(ValueArray *array);
void print_value(Value value);
#endif

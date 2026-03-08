#ifndef CHUNK_H
#define CHUNK_H
#include "common.h"
#include "value.h"

typedef enum
{
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

typedef struct
{
    uint8_t *code;
    ValueArray constants;
    int count;
    int capacity;
} Chunk;

void init_chunk(Chunk *chunk);
void write_chunk(Chunk *chunk, uint8_t byte);
void free_chunk(Chunk *chunk);
int add_constant(Chunk *chunk, Value value);

#endif

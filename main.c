#include <assert.h>
#include "common.h"
#include "chunk.h"
#include "debug.h"
#include <stdio.h>
#ifdef READLINE
#include <readline/readline.h>
#include <readline/history.h>
#endif
#include <stdlib.h>
#include "vm.h"

static void repl(void)
{
    char buffer[1024] = {0};
    char *line = buffer;
    for(;;)
    {
#ifdef READLINE
        line = readline("> ");
        assert(line);
#else
        printf("> ");
        fflush(stdout);
        if(!fgets(line, sizeof(buffer), stdin))
        {
            printf("\n");
            break;
        }
#endif
        interpret(line);

#ifdef READLINE
        free(line);
#endif
    }
}

static char *read_file(const char* filepath)
{
    FILE *file = fopen(filepath, "rb");
    if(!file)
    {
        perror("ERROR: ");
        exit(EXIT_FAILURE);
    }
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(file_size + 1);
    assert(buffer);
    size_t bytes_read = fread(buffer, sizeof(char), file_size, file);
    assert(bytes_read == file_size);
    buffer[bytes_read] = '\0';
    fclose(file);
    return buffer;
}

static void run_file(const char *filepath)
{
    char *source = read_file(filepath);
    InterpretResult result = interpret(source);
    free(source);
    if (result == INTERPRET_COMPILE_ERROR) exit(EXIT_FAILURE);
    if (result == INTERPRET_RUNTIME_ERROR) exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    init_vm();
    if(argc == 1)
    {
        repl();
    }
    else if(argc == 2)
    {
        run_file(argv[1]);
    }
    else
    {
        fprintf(stderr, "USAGE: miri [path]\n");
        return EXIT_FAILURE;
    }
    free_vm();
    return EXIT_SUCCESS;
}

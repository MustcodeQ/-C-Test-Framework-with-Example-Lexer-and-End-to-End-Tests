//-------------------------------------------------------- 1. Test Framework-----------------------------------------------------------------

#include <stdio.h>

#define ASSERT(condition) do { \
    if (!(condition)) { \
        printf("%s:%d: Assertion failed: %s\n", __FILE__, __LINE__, #condition); \
        return 0; \
    } \
} while (0)

#define RUN_TEST(test) do { \
    if (test()) { \
        printf("%s passed.\n", #test); \
    } else { \
        printf("%s failed.\n", #test); \
    } \
} while (0)

int main() {
    // Add calls to RUN_TEST for each test function here
    // Example: RUN_TEST(test_lexer);
    return 0;
}


// ------------------------------------------------------ Example Unit Test: Lexer--------------------------------------------------------------

#include <string.h>

// Hypothetical lexer function and token structure
typedef enum {
    TOKEN_INT,
    TOKEN_PLUS,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    const char *value;
} Token;

Token* lexer(const char *source);

// Example lexer implementation (to be replaced with the real one)
Token* lexer(const char *source) {
    static Token tokens[3];
    if (strcmp(source, "1+1") == 0) {
        tokens[0] = (Token){TOKEN_INT, "1"};
        tokens[1] = (Token){TOKEN_PLUS, "+"};
        tokens[2] = (Token){TOKEN_INT, "1"};
        tokens[3] = (Token){TOKEN_EOF, NULL};
        return tokens;
    }
    tokens[0] = (Token){TOKEN_EOF, NULL};
    return tokens;
}

// Lexer test function
int test_lexer() {
    Token *tokens = lexer("1+1");
    ASSERT(tokens[0].type == TOKEN_INT);
    ASSERT(strcmp(tokens[0].value, "1") == 0);
    ASSERT(tokens[1].type == TOKEN_PLUS);
    ASSERT(strcmp(tokens[1].value, "+") == 0);
    ASSERT(tokens[2].type == TOKEN_INT);
    ASSERT(strcmp(tokens[2].value, "1") == 0);
    ASSERT(tokens[3].type == TOKEN_EOF);
    return 1;
}

int main() {
    RUN_TEST(test_lexer);
    return 0;
}
// ------------------------------------------------------ 3. Example End-to-End Test --------------------------------------------------------------
// Hypothetical compile function and execution function
int compile(const char *source, const char *output_filename);
int execute(const char *filename);

// Example compile function (to be replaced with the real one)
int compile(const char *source, const char *output_filename) {
    FILE *file = fopen(output_filename, "w");
    if (!file) return 0;
    fprintf(file, "echo %s", source); // Mock compilation
    fclose(file);
    return 1;
}

// Example execute function (to be replaced with the real one)
int execute(const char *filename) {
    char command[256];
    snprintf(command, sizeof(command), "/bin/sh %s", filename);
    return system(command);
}

// End-to-end test function
int test_end_to_end() {
    const char *source = "Hello, World!";
    const char *output_filename = "output.sh";
    ASSERT(compile(source, output_filename));
    ASSERT(execute(output_filename) == 0);
    return 1;
}

int main() {
    RUN_TEST(test_lexer);
    RUN_TEST(test_end_to_end);
    return 0;
}
/*

Lexer Test: We simulate a lexer function that tokenizes the string "1+1".
 The test function test_lexer checks that the lexer correctly identifies
  the tokens.
End-to-End Test: We simulate a simple compiler that writes a shell script
 to echo the source string. The test function test_end_to_end compiles the
  source code and executes the resulting script, checking for successful
   execution.
This framework can be extended with more tests and more detailed implementations
 of the compiler components as needed.

*/



















































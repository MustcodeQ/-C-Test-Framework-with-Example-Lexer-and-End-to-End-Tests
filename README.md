Test Framework for C/C++ Code
This repository contains a simple test framework for C/C++ code. It includes examples of unit tests and an end-to-end test. You can use this framework to validate your code and ensure correctness.

1. Test Framework
The test framework provides macros for writing and running tests. Here are the key components:

ASSERT(condition): A macro that checks whether the given condition is true. If not, it prints an assertion failure message and returns 0.
RUN_TEST(test): A macro that runs a test function. If the test passes, it prints a success message; otherwise, it prints a failure message.
To add your own test functions, modify the main() function by calling RUN_TEST for each test you want to run.

Example Unit Test: Lexer
The example unit test demonstrates how to test a hypothetical lexer function. The lexer tokenizes the string “1+1” into integer and plus tokens. The test function test_lexer verifies that the lexer produces the expected tokens.

Example End-to-End Test
The end-to-end test simulates a simple compiler. It includes two functions:

compile(const char *source, const char *output_filename): A mock compile function that writes a shell script (in this case, echoing the source string) to the specified output file.
execute(const char *filename): A mock execution function that runs the generated shell script.
The test_end_to_end function compiles the source code and executes the resulting script. It checks for successful execution.

Feel free to extend this framework with additional tests and more detailed implementations of the compiler components as needed.

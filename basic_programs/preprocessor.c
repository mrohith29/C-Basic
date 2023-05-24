#include <stdio.h>

#define PI 3.1415   // Define a constant
#define MAX(a, b) ((a) > (b) ? (a) : (b))   // Define a macro

#undef PI    // Undefine the constant PI

#ifdef DEBUG   // Check if DEBUG is defined
    #define DEBUG_MSG "Debugging is enabled.\n"
#else
    #define DEBUG_MSG "Debugging is disabled.\n"
#endif

#ifndef VERSION   // Check if VERSION is not defined
    #define VERSION "1.0.0"
#endif

int main() {
    printf("MAX(10, 20) = %d\n", MAX(10, 20));   // Call the macro
    printf("%s", DEBUG_MSG);   // Print the message based on DEBUG definition
    printf("VERSION = %s\n", VERSION);   // Print the version number
    return 0;
}

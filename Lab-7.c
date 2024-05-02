/*
1. **Algorithm Design**: Core to programming logic is designing clear, step-by-step algorithms to solve problems efficiently.

2. **Sequence**: Understanding the order of operations is fundamental as programs execute instructions sequentially.

3. **Selection Structures**: Employing if statements and switches allows the program to make decisions based on conditions.

4. **Iteration (Loops)**: Looping mechanisms enable the automation of repetitive tasks and processing of data collections.

5. **Modularity**: Breaking down programs into smaller, modular components enhances readability, maintainability, and reusability.

6. **Data Structures**: Choosing appropriate data structures (arrays, lists, etc.) is crucial for efficient data organization and manipulation.

7. **Error Handling**: Anticipating and handling errors gracefully ensures the robustness and reliability of the program.

8. **Optimization**: Optimizing algorithms and minimizing resource usage improves the efficiency and performance of the program.

9. **Testing and Debugging**: Thorough testing and debugging are essential for identifying and fixing errors in the code.

10. **Documentation and Comments**: Clear documentation and comments enhance code readability, understandability, and maintainability, facilitating collaboration among developers.

*/
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Enter an operator: ");
    scanf(" %s", str); // Removed the size limit from scanf, as %s automatically handles string termination

    // Check for invalid characters
    if ((str[0] >= 'A' && str[0] <= 'Z') || (str[0] >= 'a' && str[0] <= 'z') || (str[0] >= '0' && str[0] <= '9') ||
        (str[0] == '@') || (str[0] == '#') || (str[0] == '$') || (str[0] == '&') || (str[0] == '*') ||
        (str[0] == ',') || (str[0] == '.')) {
        printf("Invalid Operator\n");
        return 0; // Terminating the program if the operator is invalid
    }

    printf("Valid Operator\n");

    // Check for Unary Operator
    if (strcmp(str, "++") == 0 || strcmp(str, "--") == 0) {
        printf("Unary Operator\n");
    }
    // Check for Arithmetic Operator
    else if (strcmp(str, "+") == 0 || strcmp(str, "-") == 0 || strcmp(str, "*") == 0 ||
             strcmp(str, "/") == 0 || strcmp(str, "%") == 0) {
        printf("Arithmetic Operator\n");
    }
    // Check for Relational Operator
    else if (strcmp(str, "<") == 0 || strcmp(str, "<=") == 0 || strcmp(str, ">") == 0 ||
             strcmp(str, ">=") == 0 || strcmp(str, "==") == 0 || strcmp(str, "!=") == 0) {
        printf("Relational Operator\n");
    }
    // Check for Logical Operator
    else if (strcmp(str, "&&") == 0 || strcmp(str, "||") == 0 || strcmp(str, "!") == 0) {
        printf("Logical Operator\n");
    }
    // Check for Bitwise (Binary) Operator
    else if (strcmp(str, "&") == 0 || strcmp(str, "|") == 0 || strcmp(str, "^") == 0 ||
             strcmp(str, "<<") == 0 || strcmp(str, ">>") == 0) {
        printf("Bitwise (Binary) Operator\n");
    }
    // Check for Assignment Operator
    else if (strcmp(str, "=") == 0 || strcmp(str, "+=") == 0 || strcmp(str, "-=") == 0 ||
             strcmp(str, "*=") == 0 || strcmp(str, "/=") == 0 || strcmp(str, "%=") == 0) {
        printf("Assignment Operator\n");
    }
    // Check for Ternary Operator
    else if (strcmp(str, "?;") == 0) {
        printf("Ternary Operator\n");
    }
    else {
        printf("Operator not recognized\n");
    }

    return 0;
}

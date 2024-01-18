#include "monty.h"

void handle_err(int errorcode, ...) {
    va_list args;
    va_start(args, errorcode);

    switch (errorcode) {
        case 1:
            fprintf(stderr, "USAGE: monty file\n");
            break;
        case 2:
            fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
            break;
        case 3:
            fprintf(stderr, "L%d: unknown instruction %s\n", va_arg(args, int), va_arg(args, char *));
            break;
        case 4:
            fprintf(stderr, "Error: malloc failed\n");
            break;
        case 5:
            fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
            break;
        default:
            break;
    }

    freestacknodes();
    exit(EXIT_FAILURE);
}

void extra_err(int errorcode, ...) {
    va_list args;
    va_start(args, errorcode);

    switch (errorcode) {
        case 6:
            fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
            break;
        case 7:
            fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
            break;
        case 8:
            fprintf(stderr, "L%d: can't %s, stack too short\n", va_arg(args, int), va_arg(args, char *));
            break;
        case 9:
            fprintf(stderr, "L%d: division by zero\n", va_arg(args, int));
            break;
        default:
            break;
    }

    freestacknodes();
    exit(EXIT_FAILURE);
}

void str_err(int errorcode, ...) {
    va_list args;
    va_start(args, errorcode);

    int line_num = va_arg(args, int);

    switch (errorcode) {
        case 10:
            fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
            break;
        case 11:
            fprintf(stderr, "L%d: can't pchar, stack empty\n", line_um);
            break;
        default:
            break;
    }

    freestacknodes();
    exit(EXIT_FAILURE);
}

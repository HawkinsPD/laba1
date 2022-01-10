#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int isNum(char string[]) {
    char digits[] ="0123456789.-";
    int flag = 1;
    int flag2;
    
    for (int i = 0; i < strlen(string); i++) {
        flag2 = 0;
        for (int j = 0; j < strlen(digits); j++) {
            if (string[i] == digits[j]) {
                flag2 = 1;
            }
        }
        flag *= flag2;
    }
    return flag;
}


int isOperator(char string[]) {
    char digits[] ="+-*/";
    int flag = 1;
    int flag2;
    
    for (int i = 0; i < strlen(string); i++) {
        flag2 = 0;
        for (int j = 0; j < strlen(digits); j++) {
            if (string[i] == digits[j]) {
                flag2 = 1;
            }
        }
        flag *= flag2;
    }

    return flag;
}


void noArgs() {
    printf("No args, enter -h\n");
}

void help() {
    printf("Enter -t to get data type size\n"
           "Enter -c to get a simple calc(ex.: 2 + 2)\n"
           "Enter -x as end argument to get hexadecimal output\n"
           "Enter -o as end argument to get octal output\n");
}

void table() {
    printf("char: %8lu \n", sizeof(char));
    printf("int: %9lu \n", sizeof(int));
    printf("float: %7lu \n", sizeof(float));
    printf("double: %6lu \n", sizeof(double));
    printf("long int: %4lu \n", sizeof(long int));
    printf("long double: %1lu \n", sizeof(long double));
    printf("long long int: %3lu \n", sizeof(long long));
    printf("short: %7lu \n", sizeof(short));
}

float calc(int a,int b ,char* operator) {
    float result;
    if (strcmp(operator, "+") == 0) {
        result = a + b;
    } else if (strcmp(operator, "-") == 0) {
        result = a - b;
    } else if (strcmp(operator, "*") == 0) {
        result = a * b;
    } else if (strcmp(operator, "/") == 0) {
        if (b == 0) {
            printf("Can't divide by 0\n");
            return (0);
        } else {
            result = a / b;
        }
    }

    return result;
}


int main(int argc, char *argv[]) {
    float num1 = atoi(argv[2]);
    float num2 = atoi(argv[4]);
    char operator = *argv[3];
    
    if (argc == 1) {
        noArgs();
    } else if (argc == 2) {
        if (strcmp(argv[1], "-h") == 0) {
            help();
        } else if (strcmp(argv[1], "-t") == 0) {
            table();
        }
    } else if (argc == 5 && strcmp(argv[1], "-c") == 0 && isNum(argv[2]) && isNum(argv[4]) && isOperator(argv[3])) {
        printf("%f", calc(num1, num2, &operator));
    } else if (argc == 6 && strcmp(argv[1], "-c") == 0 && isNum(argv[2]) && isNum(argv[4]) && isOperator(argv[3])) {
        if (strcmp(argv[5], "-x") == 0) {
            printf("%X", (int)calc(num1, num2, &operator));
        } else if (strcmp(argv[5], "-o") == 0) {
            printf("%o", (int)calc(num1, num2, &operator));
        }
    } else {
        printf("Error! Enter -h\n");
    }
}

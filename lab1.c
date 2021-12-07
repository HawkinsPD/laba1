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


void NoArgs() {
    printf("No args, enter -h\n");
}

void Help() {
    printf("Enter -t to get data type size\n"
           "Enter -c to get a simple calc(ex.: 2 + 2)\n"
           "Enter -x as end argument to get hexadecimal output\n"
           "Enter -o as end argument to get octal output\n");
}

void Table() {
    printf("char: %8lu \n", sizeof(char));
    printf("int: %9lu \n", sizeof(int));
    printf("float: %7lu \n", sizeof(float));
    printf("double: %6lu \n", sizeof(double));
    printf("long int: %4lu \n", sizeof(long int));
    printf("long double: %1lu \n", sizeof(long double));
    printf("long long int: %3lu \n", sizeof(long long));
    printf("short: %7lu \n", sizeof(short));
}

void Calc(int a,int b ,char operator) {
    int result;
    if ( strcmp(&operator, "+") == 0 ) {
        result = a + b;
    }
    else if( strcmp(&operator, "-") == 0 ) {
        result = a - b;
    }
    else if( strcmp(&operator, "*") == 0 ) {
        result = a * b;
    }
    else if( strcmp(&operator, "/") == 0 ) {
        if ( b == 0 ) {
            printf("Can't divide by 0\n");
            return;
        }
        else{
            result = a / b;
        }
        
        
    }
    printf("%d", result);
}


void Hex() {
    printf("%p",Calc);
}


void Octal() {
    printf("%o",Calc);
}


int main(int argc, char *argv[]) {
    
    if (argc == 1) {
        NoArgs();
    }
 
    else if (argc == 2) {
        if (strcmp(argv[1], "-h") == 0) {
            Help();
        }
        else if (strcmp(argv[1], "-t") == 0) {
            Table();
        }
    }


    else if (argc == 5 && strcmp(argv[1], "-c") == 0 && isNum(argv[2]) && isNum(argv[4]) && isOperator(argv[3])) {
        int num1 = *argv[2];
        int num2 = *argv[4];
        char operator = *argv[3];
        Calc(num1, num2, operator);
    }
    
    else if (argc == 6 && strcmp(argv[1], "-c") == 0 && isNum(argv[2]) && isNum(argv[4]) && isOperator(argv[3])) {
        if ( strcmp(argv[5], "-x") == 0) {
            Hex();
        }
        else if (strcmp(argv[5], "-o") == 0) {
            Octal();
        }
    }
    
    else{
        printf("Error! Enter -h\n");
    }

}

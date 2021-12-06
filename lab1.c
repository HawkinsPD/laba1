#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int isNum(char string[]) {
    char digits[] ="0123456789.-";
    unsigned long long flag = 1;
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
    unsigned long long flag = 1;
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




int main(int argc, char *argv[]) {

    // printf("%d\n", argc);

    // printf("%s\n", argv[1]);

    // for (int i = 0; i < argc; ++i) {
    //     printf('arg %s\n', argv[i]);
    // }
    


    if (argc == 1) {
        printf("No args\n");
    }

    else if (strcmp(argv[1], "-h") == 0 ) {
        printf("\tLaboratory work #1\n"
               "-t -- print table of variable sizes\n"
               "-c -- perform a simple arithmetic operation\n");
    }
    
    else if (strcmp(argv[1], "-t") == 0 ) {
        printf("table\n");
    }
    
    else if (strcmp(argv[1], "-c") == 0 ) {
        if (argc == 5 && isNum(argv[2]) && isNum(argv[4]) && isOperator(argv[3])) {
            int a = *argv[2];
            int b = *argv[4];
            int result;
            char operator = *argv[3];
            
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
                if ( b != 0 ) {
                    result = a / b;
                }else
                    printf("can't divide by 0\n");
            }
                printf("%d",result);
    }

    return 0;
    }}

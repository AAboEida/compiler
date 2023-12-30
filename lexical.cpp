#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <iostream>
#include<conio.h>

using namespace std;
#define size 100

int i = 0;
char s[5];
/* Function declaration*/
void S();
void A();
void B();
void disp();
void error();

int main() 
{
    char code[size];
    printf("Enter code : ");
    fgets(code, sizeof(code), stdin);

    int r = 0;
    int length = strlen(code);
    char k_word[25];

    

    while (r < length) {
        // Check for comments (single line comments starting with "//")
        if (code[r] == '/' && code[r + 1] == '/') {
            printf("Comment: ");
            while (code[r] != '\n' && r < length) {
                putchar(code[r]);
                r++;
            }
            putchar('\n');
        }

        // Check for operators
        else if (code[r] == '+' || code[r] == '-' || code[r] == '*' || code[r] == '/' ||
                 code[r] == '%' || code[r] == '=' || code[r] == '<' || code[r] == '>' ||
                 code[r] == '&' || code[r] == '!') {
            printf("Operator: %c\n", code[r]);
        }

        // Check for special characters (excluding spaces, tabs, and newlines)
        else if (!isalnum(code[r]) && code[r] != ' ' && code[r] != '\n') {
            printf("Special Character: %c\n", code[r]);
        }

        //check for constants(including numbers only )
        else if (isdigit(code[r]))
        {
            printf("Numeric Constant: %c\n", code[r]);
        }
        

        // Extract and check for keywords or identifiers
        else if (isalpha(code[r])) {
            int w = 0;
            while (isalnum(code[r]) || code[r] == '_') {
                k_word[w++] = code[r++];
            }
            k_word[w] = '\0';

            // List of example keywords
            char keywords[10][10] = {"if", "else", "while", "for", "int", "float", "char","double","switch", "return"};
            int isKeyword = 0;
            for (int k = 0; k < 10; k++) {
                if (strcmp(k_word, keywords[k]) == 0) {
                    isKeyword = 1;
                    break;
                }
            }


            if (isKeyword) {
                printf("Keyword: %s\n", k_word);
            } else {
                printf("Identifier: %s\n", k_word);
            }

            
            r=r-1;
        }

        r=r+1;         
    }

    cout << "Given grammar is " << endl;
    cout << "S -> aBb/ccA" << endl;
    cout << "A -> b/c" << endl;
    cout << "B -> a/b" << endl;
    cout << "Enter your string" << endl;
    cin >> s;
    S();
    if (s[i] == NULL)
        cout << "string is valid" << endl;
    else
        cout << "string is invalid" << endl;
    getch();

    return 0;
}

void S()
{
    if (s[i] == 'a')
    {
        i++;
        B();
        if (s[i] == 'b')
            i++;
        else
            error();
    }
    else if (s[i] == 'c')
    {
        i++;
        if (s[i] == 'c')
        {
            i++;
            A();
        }
        else
            error();
    }
}
void A() // function definition
{
    if (s[i] == 'b' || s[i] == 'c')
        i++;
    else
        error();
}
void B() // function definition
{
    if (s[i] == 'a' || s[i] == 'b')
        i++;
    else
        error();
}
void error()
{
    cout << "string is invalid" << endl;
    getch();
}
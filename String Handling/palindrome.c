#include <stdio.h>

int palindrome(char str[]) {
    int size, i;
    for (size = 0; str[size] != '\0'; size++);
    char temp[size + 1]; 

    for (i = 0; i < size; i++) {
        temp[i] = str[size - 1 - i]; 
    }
    temp[i] = '\0';

    for (i = 0; i < size; i++) {
        if (str[i] != temp[i]) {
            return 0;
        }
    }

    return 1; 
}

void main() {
    char str[50];
    printf("Enter the string: ");
    scanf("%s", str);

    if (palindrome(str)) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }
}
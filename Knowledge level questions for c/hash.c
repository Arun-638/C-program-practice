#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define sizet 100
#define sizew 50

struct Node {
    char word[sizew];
    struct Node *next;
};

struct Node *hashTable[sizet];

unsigned int hash(char *word) {
    unsigned int sum = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        sum += tolower(word[i]);
    }

    return sum % sizet;
}


void insertWord(char *word) {
    unsigned int index = hash(word);

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); //for chaining
    strcpy(newNode->word, word);
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

int isWord(char *word) {
    unsigned int index = hash(word);
    struct Node *temp = hashTable[index];

    while (temp != NULL) {
        if (strcmp(temp->word, word) == 0) {
            return 1; // word found
        }
        temp = temp->next;
    }
    return 0; // word not found
}
void suggestCorrections(char *word) {
    printf("Suggestions for \"%s\":\n", word);
    char temp[sizew];

    for (int i = 0; i < strlen(word); i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            strcpy(temp, word);
            temp[i] = c; 
            if (isWord(temp) && strcmp(temp, word) != 0) {
                printf("  %s\n", temp);
            }
        }
    }
}
int main() {
    char *dictionary[] = { //for testing
        "hello", "help", "hell", "hero", "her", "world",
        "cold", "gold", "good", "go", "god", "hold"
    };
    int dictSize = sizeof(dictionary) / sizeof(dictionary[0]);

    for (int i = 0; i < dictSize; i++) {
        insertWord(dictionary[i]);
    }

    char word[sizew];
    printf("Enter a word to check: ");
    scanf("%s", word);

    if (isWord(word)) {
        printf(" \"%s\" is a valid word!\n", word);
    } else {
        printf(" \"%s\" is not found in the dictionary.\n", word);
        suggestCorrections(word);
    }

    return 0;
}


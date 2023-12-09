/* Without using strtok */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to split a string into words without using strtok
char **splitStringWithoutStrtok(const char *input, int *wordCount) {
    char **words = NULL;
    int count = 0;
    int start = 0;
    int end = 0;
    int inWord = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n') {
            if (inWord) {
                inWord = 0;
                end = i;
                int wordLength = end - start;
                char *word = (char *)malloc(wordLength + 1);
                if (!word) {
                    perror("Memory allocation error");
                    free(words);
                    return NULL;
                }
                strncpy(word, &input[start], wordLength);
                word[wordLength] = '\0';
                words = (char **)realloc(words, (count + 1) * sizeof(char *));
                if (!words) {
                    perror("Memory allocation error");
                    free(word);
                    return NULL;
                }
                words[count] = word;
                count++;
            }
        } else {
            if (!inWord) {
                inWord = 1;
                start = i;
            }
        }
    }

    if (inWord) {
        end = strlen(input);
        int wordLength = end - start;
        char *word = (char *)malloc(wordLength + 1);
        if (!word) {
            perror("Memory allocation error");
            free(words);
            return NULL;
        }
        strncpy(word, &input[start], wordLength);
        word[wordLength] = '\0';
        words = (char **)realloc(words, (count + 1) * sizeof(char *));
        if (!words) {
            perror("Memory allocation error");
            free(word);
            return NULL;
        }
        words[count] = word;
        count++;
    }

    if (wordCount) {
        *wordCount = count;
    }

    return words;
}

int main(int argc, char **av) {
    if (argc != 2) {
        printf("Usage: %s \"input_string\"\n", av[0]);
        return 1;
    }

    const char *input = av[1];
    int wordCount = 0;

    char **words = splitStringWithoutStrtok(input, &wordCount);

    if (words) {
        printf("Words in the string:\n");
        for (int i = 0; i < wordCount; i++) {
            printf("Word %d: %s\n", i + 1, words[i]);
            free(words[i]);
        }
        free(words);
    }

    return 0;
}

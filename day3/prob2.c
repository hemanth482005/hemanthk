#include <stdio.h>
#include <string.h>

void findPatternOccurrences(char dna[], char pattern[]) {
    int dnaLength = strlen(dna);
    int patternLength = strlen(pattern);
    int count = 0;

    for (int i = 0; i <= dnaLength - patternLength; i++) {
        if (strncmp(&dna[i], pattern, patternLength) == 0) {
            count++;
        }
    }

    printf("Pattern found %d time(s) in the DNA sequence.\n", count);
}

int main() {
    char dna[100], pattern[100];

    printf("Enter DNA Sequence: ");
    scanf("%s", dna);

    printf("Enter pattern to search: ");
    scanf("%s", pattern);

    findPatternOccurrences(dna, pattern);

    return 0;
}

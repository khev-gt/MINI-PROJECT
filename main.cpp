#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[40];
    int score;
    int missions;
} Team;

int ensureCapacity(Team **teams, int *capacity, int required) {
    if (required <= *capacity) {
        return 1;
    }

    int newCapacity;

    if (*capacity == 0) {
        newCapacity = 2;
    } else {
        newCapacity = *capacity * 2;
    }

    Team *temp = (Team *)realloc(*teams, newCapacity * sizeof(Team));

    if (temp == NULL) {
    return 0;
    }
    *teams = temp;
    *capacity = newCapacity;

    return 1;
}

void cleanup(Team **teams, int *size, int *capacity) {
    free(*teams);
    *teams = NULL;
    *size = 0;
    *capacity = 0;
}

int main() {
    Team *teams = NULL;
    int size = 0;
    int capacity = 0;

    printf("Before: size = %d, capacity = %d\n", size, capacity);

    if (ensureCapacity(&teams, &capacity, 1)) {
        printf("After first allocation: size = %d, capacity = %d\n", size, capacity);
    }
    if (ensureCapacity(&teams, &capacity, 3)) {
        printf("After requesting 3 teams: size = %d, capacity = %d\n", size, capacity);
    }
    cleanup(&teams, &size, &capacity);

    printf("After cleanup: size = %d, capacity = %d, teams = %p\n", size, capacity, (void *)teams);
    return 0;
}
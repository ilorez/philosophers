
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct personne {
    char *name;
    int age;
} t_perssone;

#define NAME_COUNT 5

const char *random_names[NAME_COUNT] = {"Alice", "Bob", "Charlie", "David", "Eve"};

int main() {
    t_perssone **persones;
    int count = 5;

    // Seed random number generator
    srand(time(NULL));

    // Allocate memory for the array of pointers
    persones = (t_perssone **)malloc(count * sizeof(t_perssone *));
    if (!persones) {
        perror("Memory allocation failed");
        return 1;
    }

    // Allocate memory for each structure and assign random values
    for (int i = 0; i < count; i++) {
        persones[i] = (t_perssone *)malloc(sizeof(t_perssone));
        if (!persones[i]) {
            perror("Memory allocation failed");
            return 1;
        }
        // Assign random name and age
        persones[i]->name = (char *)random_names[rand() % NAME_COUNT];
        persones[i]->age = rand() % 50 + 18; // Age between 18 and 67
    }

    // Print the array
    for (int i = 0; i < count; i++) {
        printf("Person %d: Name = %s, Age = %d\n", i + 1, persones[i]->name, persones[i]->age);
    }

    // Free allocated memory
    for (int i = 0; i < count; i++) {
        free(persones[i]);
    }
    free(persones);

    return 0;
}

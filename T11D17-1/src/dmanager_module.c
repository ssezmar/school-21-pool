#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(door_t* doors);

void sort_doors(door_t* doors, int count);

void print_doors(door_t* doors, int count);

int main() {
    door_t doors[DOORS_COUNT];

    initialize_doors(doors);

    sort_doors(doors, DOORS_COUNT);

    print_doors(doors, DOORS_COUNT);

    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(door_t* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort_doors(door_t* doors, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (doors[j].id > doors[j + 1].id) {
                door_t temp = doors[j];
                doors[j] = doors[j + 1];
                doors[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        doors[i].status = 0;
    }
}

void print_doors(door_t* doors, int count) {
    for (int i = 0; i < count; i++) {
        printf("%d, %d", doors[i].id, doors[i].status);
        if (i != count - 1) printf("\n");
    }
}
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char name[50];
    int age;
    char destination[50];
} Passenger;

void addPassenger(Passenger passengers[], int *count, char name[], int age, char destination[]) {
    strcpy(passengers[*count].name, name);
    passengers[*count].age = age;
    strcpy(passengers[*count].destination, destination);
    (*count)++;
}

void sortPassengers(Passenger passengers[], int count) {
    Passenger temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(passengers[i].destination, passengers[j].destination) > 0) {
                temp = passengers[i];
                passengers[i] = passengers[j];
                passengers[j] = temp;
            }
        }
    }
}

void searchPassenger(Passenger passengers[], int count, char destination[]) {
    int found = 0;
    printf("Passengers traveling to %s: ", destination);
    for (int i = 0; i < count; i++) {
        if (strcmp(passengers[i].destination, destination) == 0) {
            printf("%s ", passengers[i].name);
            found = 1;
        }
    }
    if (!found) {
        printf("No passengers found for %s", destination);
    }
    printf("\n");
}

void displayPassengers(Passenger passengers[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s - %s\n", passengers[i].name, passengers[i].destination);
    }
}

int main() {
    Passenger passengers[MAX];
    int count = 0, n, age;
    char name[50], destination[50];
    
    printf("Enter number of passengers: ");
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        printf("Passenger %d: ", i + 1);
        scanf("%[^,], %d, %[^]", name, &age, destination);
        getchar();
        addPassenger(passengers, &count, name, age, destination);
    }
    
    sortPassengers(passengers, count);
    
    printf("\nSorted List (by destination):\n");
    displayPassengers(passengers, count);
    
    printf("\nEnter destination to search: ");
    scanf("%s", destination);
    searchPassenger(passengers, count, destination);
    
    return 0;
}

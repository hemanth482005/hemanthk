#include <stdio.h>

#define MAX_AMBULANCES 100

// Function to perform selection sort on distances
void selectionSort(int distances[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (distances[j] < distances[minIndex]) {
                minIndex = j; // Update minIndex if a smaller distance is found
            }
        }
        // Swap the found minimum distance with the first element
        if (minIndex != i) {
            int temp = distances[i];
            distances[i] = distances[minIndex];
            distances[minIndex] = temp;
        }
    }
}

int main() {
    int distances[MAX_AMBULANCES];
    int n;

    // Input number of ambulances
    printf("Enter number of ambulances: ");
    scanf("%d", &n);

    // Input distances for each ambulance
    printf("Enter distances (in km) for each ambulance:\n");
    for (int i = 0; i < n; i++) {
        printf("Ambulance %d: ", i + 1);
        scanf("%d", &distances[i]);
    }

    // Sort distances using selection sort
    selectionSort(distances, n);

    // Display sorted distances
    printf("\nSorted Distances:\n");
    for (int i = 0; i < n; i++) {
        printf("%d km\n", distances[i]);
    }

    // Assign the nearest ambulance
    printf("Nearest Ambulance Assigned: Distance %d km\n", distances[0]);

    return 0;
}

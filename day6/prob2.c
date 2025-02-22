#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int price;
} Product;

// Function to compare two products for sorting
int compare(const void *a, const void *b) {
    Product *productA = (Product *)a;
    Product *productB = (Product *)b;
    return productA->price - productB->price; // Ascending order
}

// Function to perform binary search
int binarySearch(Product products[], int size, const char *name) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(products[mid].name, name);
        if (cmp == 0) {
            return mid; // Found
        } else if (cmp < 0) {
            left = mid + 1; // Search right
        } else {
            right = mid - 1; // Search left
        }
    }
    return -1; // Not found
}

// Function to display the cheapest and most expensive products
void displayCheapestAndMostExpensive(Product products[], int size) {
    if (size > 0) {
        printf("Cheapest Product: %s (Price: %d)\n", products[0].name, products[0].price);
        printf("Most Expensive Product: %s (Price: %d)\n", products[size - 1].name, products[size - 1].price);
    }
}

int main() {
    Product products[MAX_PRODUCTS];
    int n;

    // Input number of products
    printf("Enter number of products: ");
    scanf("%d", &n);

    // Input product records
    for (int i = 0; i < n; i++) {
        printf("Enter Product Name and Price for product %d: ", i + 1);
        scanf("%s %d", products[i].name, &products[i].price);
    }

    // Sort products by price in ascending order
    qsort(products, n, sizeof(Product), compare);

    // Display sorted products
    printf("\nSorted by Price:\n");
    for (int i = 0; i < n; i++) {
        printf("%s (%d)\n", products[i].name, products[i].price);
    }

    // Search for a product by name
    char productName[50];
    printf("\nEnter Product Name to search: ");
    scanf("%s", productName);
    int index = binarySearch(products, n, productName);
    if (index != -1) {
        printf("Found: %s (Price: %d)\n", products[index].name, products[index].price);
    } else {
        printf("Product '%s' not found.\n", productName);
    }

    // Display cheapest and most expensive products
    displayCheapestAndMostExpensive(products, n);

    return 0;
}

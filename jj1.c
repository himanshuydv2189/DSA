#include <stdio.h>
#include <stdlib.h>
int linearSearch(int arr[], int size, int key);
void insertElement(int arr[], int *size, int pos, int element);
void deleteElement(int arr[], int *size, int pos);
void reverseArray(int arr[], int size);
void updateArray(int arr[], int size);

int main() {
    int choice, size, pos, element, key;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Linear search for an element\n");
        printf("2. Insert an element at specified position\n");
        printf("3. Delete an element from specified position\n");
        printf("4. Reverse the array\n");
        printf("5. Update the array\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to search: ");
                scanf("%d", &key);
                pos = linearSearch(arr, size, key);
                if (pos != -1)
                    printf("Element found at index %d.\n", pos);
                else
                    printf("Element not found.\n");
                break;
            case 2:
                printf("Enter the position to insert the element: ");
                scanf("%d", &pos);
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                insertElement(arr, &size, pos, element);
                break;
            case 3:
                printf("Enter the position to delete the element: ");
                scanf("%d", &pos);
                deleteElement(arr, &size, pos);
                break;
            case 4:
                reverseArray(arr, size);
                printf("Array reversed successfully.\n");
                break;
            case 5:
                updateArray(arr, size);
                printf("Array updated successfully.\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    free(arr);
    return 0;
}

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key)
            return i; 
    }
    return -1; 
}

void insertElement(int arr[], int *size, int pos, int element) {
    if (pos < 0 || pos > *size) {
        printf("Invalid position.\n");
        return;
    }

    (*size)++;
    for (int i = *size - 1; i > pos; --i) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
}

void deleteElement(int arr[], int *size, int pos) {
    if (pos < 0 || pos >= *size) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = pos; i < *size - 1; ++i) {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

void updateArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0) { 
            arr[i] += 5;
        } else { 
            arr[i] *= 2;
        }
    }
}

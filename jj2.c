#include<stdio.h>
#define MAX_SIZE 100
int linearSearch(int arr[], int size, int key);
void insertElement(int arr[], int *size, int position, int key);
void deleteElement(int arr[], int *size, int position);
void reverseArray(int arr[], int size);
void updateArray(int arr[], int size);
void displayArray(int arr[], int size);

int main(){
        int arr[MAX_SIZE];
    int size, choice, key, position;

    printf("Enter the size of the array (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid size entered.\n");
        return 1; 
    }
    
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    

    do{
        printf("enter 1 for linear search of an element\n");
        printf("enter 2 for inserting an element at specified position\n");
        printf("enter 3 for deleting an element from the specified position\n");
        printf("enter 4 for reversing the array\n");
        printf("enter 5 for updating the array ,multiplying the odd indexed elements by 2 and adding 5 to all the elements at even index\n");
        printf("enter 6 to exit the program");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("enter element to search");
            scanf("%d",&key);
            position = linearSearch(arr, size, key);
                if (position != -1)
                    printf("Element %d found at index %d.\n", key, position);
                else
                    printf("Element %d not found in the array.\n", key);
                break;
            case 2:
                printf("Enter the position to insert the element: ");
                scanf("%d", &position);
                printf("Enter the element to insert: ");
                scanf("%d", &key);
                insertElement(arr, &size, position, key);
                break;
            case 3:
                printf("Enter the position to delete the element: ");
                scanf("%d", &position);
                deleteElement(arr, &size, position);
                break;
            case 4:
                reverseArray(arr, size);
                break;
            case 5:
                updateArray(arr, size);
                break;



            case 6:
            printf("Exiting program.\n");
            break;
            default:
            printf("Invalid choice. Please enter again.\n");
        }
    }while (choice != 6);

   displayArray(arr,size);


    return 0;
}

int linearSearch(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return i;
        }
        return -1;
    }
}
void insertElement(int arr[], int *size, int position, int key) {
    if (*size >= MAX_SIZE) {
        printf("Array is full, cannot insert element.\n");
        return;
    }

    if (position < 0 || position > *size) {
        printf("Invalid position to insert element.\n");
        return;
    }

    for (int i = *size; i>position; i--) {
        arr[i] = arr[i-1]; 
    }

    arr[position] = key;
    (*size)++;
    printf("Element inserted successfully.\n");
}


void deleteElement(int arr[], int *size, int position) {
    if (position < 0 || position >= *size) {
        printf("Invalid position to delete element.\n");
        return;
    }

    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1]; 
    }

    (*size)--;
    printf("Element deleted successfully.\n");
}


void reverseArray(int arr[], int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
    printf("Array reversed successfully.\n");
}


void updateArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            arr[i] =arr[i]+5;
        } else {
            arr[i] =arr[i]*2;
        }
    }
    printf("Array updated successfully.\n");
}
void displayArray(int arr[], int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }}

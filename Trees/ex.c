#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

typedef struct
{
    int rollNo;
    char name[30];
    int marks;
} Student;

Student original[MAX] = {
    {108, "Gaurav Drall", 87},
    {109, "Utkarsh Pasahan", 92},
    {110, "NIKHIL TIWARI", 75},
    {111, "Riya badalia", 88},
    {112, "Ibrahim Ahmad", 63},
    {114, "Akshat Singh", 95},
    {115, "AKSHIT SHARMA", 70},
    {116, "Prajjwal Kumar Shah", 82},
    {117, "Harleen Kaur", 55},
    {118, "Piyush", 91},
    {119, "MD ARMAN", 78},
    {120, "Priya yadav", 66},
    {121, "Yogita", 84},
    {122, "Vaibhav", 59},
    {123, "Aditya Singh", 97},
    {124, "Jatin sehrawat", 73},
    {125, "MOHD ASIM", 81},
    {126, "Rohan Sarao", 68},
    {127, "Prince Lohia", 90},
    {128, "Rohit Kasotia", 77}};

int n = 20;
Student arr[MAX];

void copyOriginal(void)
{
    for (int i = 0; i < n; i++)
        arr[i] = original[i];
}

void displayRecords(Student a[], int size)
{
    printf("\n%-6s %-22s %s\n", "Roll", "Name", "Marks");
    printf("-----------------------------------------------\n");
    for (int i = 0; i < size; i++)
        printf("%-6d %-22s %d\n", a[i].rollNo, a[i].name, a[i].marks);
    printf("\n");
}

void swap(Student *a, Student *b)
{
    Student t = *a;
    *a = *b;
    *b = t;
}

int partition(Student a[], int low, int high)
{
    int pivot = a[high].marks;
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (a[j].marks <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}

void quickSort(Student a[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

void merge(Student a[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Student L[MAX], R[MAX];
    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i].marks <= R[j].marks)
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];
}

void mergeSort(Student a[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

void heapify(Student a[], int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && a[left].marks > a[largest].marks)
        largest = left;
    if (right < size && a[right].marks > a[largest].marks)
        largest = right;
    if (largest != i)
    {
        swap(&a[i], &a[largest]);
        heapify(a, size, largest);
    }
}

void heapSort(Student a[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(a, size, i);
    for (int i = size - 1; i > 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

void binarySearch(Student a[], int size, int key)
{
    int low = 0, high = size - 1, found = 0;
    printf("\nBinary Search for marks = %d:\n\n", key);
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid].marks == key)
        {
            int start = mid, end = mid;
            while (start > 0 && a[start - 1].marks == key)
                start--;
            while (end < size - 1 && a[end + 1].marks == key)
                end++;
            for (int i = start; i <= end; i++)
                printf(" Roll: %-4d Name: %-22s Marks: %d\n",
                       a[i].rollNo, a[i].name, a[i].marks);
            found = 1;
            break;
        }
        else if (a[mid].marks < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if (!found)
        printf(" No record found with marks = %d.\n", key);
}

int main(void)
{
    int choice, searchKey;

    printf("\nStudent Record Sorting System\n\n");
    printf("Select Sorting Algorithm:\n");
    printf(" 1. Quick Sort\n");
    printf(" 2. Merge Sort\n");
    printf(" 3. Heap Sort\n");
    printf("Enter choice (1/2/3): ");
    scanf("%d", &choice);

    copyOriginal();
    printf("\nOriginal Records:");
    displayRecords(arr, n);

    switch (choice)
    {
    case 1:
        quickSort(arr, 0, n - 1);
        printf("Sorted using Quick Sort:\n");
        break;
    case 2:
        mergeSort(arr, 0, n - 1);
        printf("Sorted using Merge Sort:\n");
        break;
    case 3:
        heapSort(arr, n);
        printf("Sorted using Heap Sort:\n");
        break;
    default:
        printf("Invalid choice. Exiting.\n");
        return 1;
    }

    displayRecords(arr, n);

    printf("\nEnter marks value to search: ");
    scanf("%d", &searchKey);
    binarySearch(arr, n, searchKey);

    return 0;
}

/*
Asymptotic Notations: Big O, Big Omega and Big Theta

Asymptotic notation gives us an idea about how good a given algorithm is compared to some other algorithm.

Now let's look at the mathematical definition of 'order of.' Primarily there are three types of widely used asymptotic notations.

1. Big oh notation ( O )
2. Big omega notation ( Ω )
3. Big theta notation ( θ ) – Widely used one

Big oh notation ( O ):
    Big oh notation is used to describe an asymptotic upper bound.
    Mathematically, if f(n) describes the running time of an algorithm; f(n) is O(g(n)) if and only if there exist positive constants c and n° such that:

    0 ≤ f(n) ≤ c g(n)        for all n ≥ n°. 

    Here, n is the input size, and g(n) is any complexity function, for, e.g. n, n2, etc. (It is used to give upper bound on a function)
    If a function is O(n), it is automatically O(n2) as well! Because it satisfies the equation given above.

Big Omega Notation ( Ω ):
    Just like O notation provides an asymptotic upper bound, Ω notation provides an asymptotic lower bound. 
    Let f(n) define the running time of an algorithm; f(n) is said to be Ω (g(n)) if and only if there exist positive constants  c and n° such that:

    0 ≤ c g(n) ≤ f(n)        for all n ≥ n°. 

    It is used to give the lower bound on a function.

    If a function is Ω (n2) it is automatically Ω (n) as well since it satisfies the above equation.

Big theta notation ( θ ):
    Let f(n) define the running time of an algorithm.
    F(n) is said to be θ (g(n)) if f(n) is O (g(n)) and f(n) is Ω (g(n)) both. 
    Mathematically,

    0 ≤ f(n) ≤ c1 g(n)        for all n ≥ n°. 
                                                } for sufficiently large value of n
    0 ≤ c2 g(n) ≤ f(n)        for all n ≥ n°. 
                    ||
                    Merging both the equations, we get:
    0 ≤ c2 g(n) ≤ f(n) ≤ c1 g(n)        for all n ≥ n°.

    The equation simply means that there exist positive constants c1 and c2 such that f(n) is sandwiched between c2 g(n) and c1 g(n). 

Which one of these to use?
    Big theta provides a better picture of a given algorithm's run time, which is why most interviewers expect you to answer in terms of Big theta when they ask "order of" questions. And what you provide as the answer in Big theta, is already a Big oh and a Big omega. It is recommended for this reason.

 Quick Quiz: Prove that n2+n+1 is O(n3), Ω(n2), and θ(n2) using respective definitions.


Hint: You can approach this both graphically, making some rough graphs and mathematically, finding valid constants c1 and c2.

Increasing order of common runtimes:
Below mentioned are some common runtimes which you will come across in your coding career.

O(1) < O(log n) < O(n) < O(n log n) < O(n2) < O(n3) < O(2^n) < O(n!) <O(n^x)
^                                                                       ^
|                                                                       |    
Better                                                              Worse
            Common Runtimes from better to worse
                ----------------------------->
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// O(1) - Constant time
int constant_time(int arr[], int size) {
    return arr[0];
}

// O(log n) - Logarithmic time (binary search)
int logarithmic_time(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// O(n) - Linear time
int linear_time(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// O(n log n) - Linearithmic time (quicksort)
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

// O(n^2) - Quadratic time
void quadratic_time(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", arr[i] * arr[j]);
        }
        printf("\n");
    }
}

int main() {
    int size = 1000;
    int* arr = (int*)malloc(size * sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000;
    }

    // Demonstrating different time complexities
    printf("Constant time: %d\n", constant_time(arr, size));
    printf("Logarithmic time: %d\n", logarithmic_time(arr, size, 500));
    printf("Linear time: %d\n", linear_time(arr, size, 500));
    quicksort(arr, 0, size - 1);
    printf("Linearithmic time: Sorted array\n");
    quadratic_time(arr, 10);  // Using smaller size for quadratic example

    free(arr);
    return 0;
}

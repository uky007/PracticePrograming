#include <cstdio>
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 10;

vector<int> numbers = {3, 2, 5, 1, 6, 7, 9, 8, 4, 0};
int count = 0;

vector<int> bubblesort(vector<int> numbers) {

    for (int i = 0; i < numbers.size() - 1; i++) {
        for (int j = numbers.size() - 1; j > i; j--) {
            if (numbers[j] < numbers[j - 1]) {
                int swap = numbers[j];
                numbers[j] = numbers[j - 1];
                numbers[j - 1] = swap;
                for (int k = 0; k < numbers.size(); k++) {
                    printf("%d ", numbers[k]);
                }
                cout << endl;
            }
            count++;
        }
    }

    return numbers;
}

int main() {

    vector<int> sorted_numbers(MAX_SIZE);
    printf("Before sort:\n");

    for (int i = 0; i < numbers.size(); i++) {
        printf("%d ", numbers[i]);
    }
    cout << endl;
    cout << "====================" << endl;

    sorted_numbers = bubblesort(numbers);


    printf("After sort:\n");

    for (int i = 0; i < sorted_numbers.size(); i++) {
        printf("%d ", sorted_numbers[i]);
    }
    cout << endl;
    cout << "====================" << endl;

    printf("Order(%d) = %d\n", MAX_SIZE, count);

    return 0;
}

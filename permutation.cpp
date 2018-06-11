// Waylon Peng, Period 1
// May312018
// Lab: Combinations and Permutations
// Prints all the permutations of a set of numbers. Implements Heap's algorithm.

#include <iostream>
#include <utility>
using namespace std;

void print_permutations(int in[], int n, int size)
{
    if (n == 1) // recursive end case. if n hits beginning of array, permutation is complete; output
    {
        for (int i = 0; i < size; i++)
        {
            cout << in[i] << " ";
        }
        cout << endl;
    }
    else 
    {
        for (int i = 0; i < n; i++) { // for every length in the segment being currently inspected
            print_permutations(in, n - 1, size); // recursive call
            if (n % 2 == 0) { // if the length of the segment is even, swap the first and last elements in the length
                swap(in[0], in[n - 1]);
            }
            else { // otherwise swap the ith element and the last element
                swap(in[i], in[n - 1]);
            }
        } // for loop restarts
        }
    }

int main()
{
    int yes[4] = {1, 2, 3, 4};
    print_permutations(yes, 4, 4); 
}

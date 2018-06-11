// A simple program that computes the square root of a number
#include <iostream>
#include <cstdlib>
#include <unordered_set>

using namespace std;

int main (int argc, char *argv[])
{
  int num = 0;
  int* p1 = &num;
  int* p2 = &num;
  unordered_set<int*> set;

  set.insert(p1);

  cout << set.count(p2);
}
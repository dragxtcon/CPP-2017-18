// Waylon Peng, Period 1
// 5Dec2017
// Lab 7a: Sort2 (7.1)
// Sorts the two parameters to the function.

void sort2(double* p, double* n) {
	if (*p > *n) { //if parameters out of order
		double* temp = p; //swap their values
		p = n;
		n = temp;
	}
}
//Purpose: Finds the median given two non-empty, sorted arrays without merging
//Date: 4/12/2020

//Libraries
#include <iostream>

//Namespaces
using std::cout;
using std::cin;
using std::endl;

//Functions

int min(int a, int b) {
	//Check if either are NULL
	if (a == NULL || b == NULL) {
		if (a == NULL) return b;
		else return a;
	}
	else
	{
		if (a <= b) return a;
		else return b;
	}
	
}

int max(int a, int b) {
	//Check if either are NULL
	if (a == NULL || b == NULL) {
		if (a == NULL) return b;
		else return a;
	}
	else
	{
		if (a >= b) return a;
		else return b;
	}
}



float getMedian(int start, int stop, int sizeA, int sizeB, int A[], int B[]) {
	int midA, midB, A_L, A_R, B_L, B_R;

	//Find mids
	midA = (start + stop) / 2;
	midB = (sizeA + sizeB + 1) / 2 - midA;

	//Set indeces :: Check if in bounds
	if (midA - 1 < 0 || midA - 1 > sizeA - 1) A_L = NULL;
	else	A_L = A[midA - 1];

	if (midA < 0 || midA > sizeA - 1) A_R = NULL;
	else	A_R = A[midA];
	
	if (midB - 1 < 0 || midB - 1 > sizeB - 1) B_L = NULL;
	else	B_L = B[midB - 1];
	
	if (midB < 0 || midB > sizeB - 1) B_R = NULL;
	else	B_R = B[midB];

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//Nothing NULL
	if (A_L != NULL && A_R != NULL && B_L != NULL && B_R != NULL) {
		
		//If all left <= all right
		if (A_L <= B_R && B_L <= A_R) {
			//even or odd
			if ((sizeA + sizeB) % 2 == 0) {
				//Even
				return (max(A_L, B_L) + min(A_R, B_R)) / 2.0;
			}
			else {
				//Odd
				return max(A_L, B_L);
			}
		}
		//All left !<= all right
		else {
			//check forward or backward
			if (A_L > B_R) {
				//move split left
				if(midA + 1 > stop) return getMedian(midA - 1, stop + 1, sizeA, sizeB, A, B);
				return getMedian(midA - 1, stop, sizeA, sizeB, A, B);
			}
			else
			{
				//move split right
				//check for midA+1 > stop
				if (midA + 1 > stop) return getMedian(midA + 1, stop + 1, sizeA, sizeB, A, B);
				return getMedian(midA + 1, stop, sizeA, sizeB, A, B);
			}
		}
		
	}

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	else if (A_L == NULL || B_R == NULL) {
		//Check B_L < A_R
		if (B_L <= A_R) {
			//even or odd
			if ((sizeA + sizeB) % 2 == 0) {
				//EVEN
				return (max(A_L, B_L) + min(A_R, B_R)) / 2.0;
			}
			else {
				//ODD
				return max(A_L, B_L);
			}
		}
		else {
			if(midA + 1 > stop) return getMedian(midA + 1, stop + 1, sizeA, sizeB, A, B);
			else return getMedian(midA + 1, stop, sizeA, sizeB, A, B);
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	else if (B_L == NULL || A_R == NULL) {
		//Check A_L < B_R
		if (A_L <= B_R) {
			//even or odd
			if ((sizeA + sizeB) % 2 == 0) {
				//EVEN
				return (max(A_L, B_L) + min(A_R, B_R)) / 2.0;
			}
			else
			{
				//ODD
				return max(A_L, B_L);
			}
		}
		else
		{
			//move split right
			//check for midA+1 > stop
			if (midA + 1 > stop) return getMedian(midA - 1, stop + 1, sizeA, sizeB, A, B);
			return getMedian(midA - 1, stop, sizeA, sizeB, A, B);
		}
	}
}




//Driver
int main() {
	//Initialize final
	float Median;

	//Initialize Arrays

	int A[] = {1, 3, 5, 8, 12, 13,51, 52, 61, 70};
	int B[] = {2, 3, 5, 7,10,11,12,13,19,25,33};
	
	//Get Sizes
	int sizeA = sizeof(A)/sizeof(A[0]);
	int sizeB = sizeof(B)/sizeof(B[0]);

	if (sizeA <= sizeB) {
		//Call Median Function
		Median = getMedian(0, sizeA - 1, sizeA, sizeB, A, B);
	}
	else {
		//Call Median Function
		Median = getMedian(0, sizeB - 1, sizeB, sizeA, B, A);
	}

	cout << "Median = " << Median << endl;
	
	system("pause");
	return 0;
}
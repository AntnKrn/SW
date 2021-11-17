#include <iostream>

using namespace std;

int* creatArray(int size) {
	int* arr = new int[size];
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 21 - 5;
		cout << arr[i] << " ";
	}
	return arr;
}

void elementPossition() {
	int size, number;
	cout << "Enter size of array ";cin >> size;
	int* arr = creatArray(size);
	cout << "Enter elemet ";cin >> number;
	for (int i = 0; i < size; i++) {
		if(arr[i] == number) {
			cout << "Position of the element is " << i << endl;
			break;
		}
	}
	delete[] arr;
}

void differenceBtPrevius() {
    int size, z = 0;
    cout << "Enter size of array ";
    cin >> size;
    int* arr = creatArray(size);
    cout << "answer: ";
    for (int i = 2; i < size; i++) {
        if (arr[i] < (arr[i - 2] - arr[i - 1])) cout << arr[i] << " ";
        else z++;
    }
    if (z == size - 2) {
        cout << "There are no such elements";
    }
    delete[] arr;
}

void subsequence() {
    int size, max_length = 1, current_length = 1;
    cout << "Enter size of array ";
    cin >> size;
    int* arr = creatArray(size);
    for (int i = 1; i < size; i++) {
        if (arr[i] == arr[i - 1] and arr[i] == arr[i + 1]) {
            current_length++;
        }
        else if (arr[i] == arr[i - 1] and arr[i] != arr[i + 1]) {
            current_length++;
            if (current_length > max_length) {
                max_length = current_length;
            }
            current_length = 1;
        }
    }
    cout << "max length: " << max_length;
    delete[] arr;
}

int** creatMatrix(int rows, int columns) {
    srand(time(NULL));
    int** matrix = new int* [rows];

    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[columns];
        for (int j = 0; j < columns; j++)
        {
            matrix[i][j] = rand() % 21 - 10;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (matrix[i][j] >= 0) cout << " ";
            cout << matrix[i][j] << "  ";
        }
        cout << endl << endl;
    }
    return matrix;
}

void transportation() {
    int rows, columns;
    int** matrix = creatMatrix(rows,columns);
    cout << "Main diagonal transport: " << endl;
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (matrix[j][i] >= 0) cout << " ";
            cout << matrix[j][i] << "  ";
        }
        cout << endl << endl;
    }
    cout << "Off-diagonal transport: " << endl;
    for (int i = columns - 1; i > -1; i--)
    {
        for (int j = rows - 1; j > -1; j--)
        {
            if (matrix[j][i] >= 0) cout << " ";
            cout << matrix[j][i] << "  ";
        }
        cout << endl << endl;
    }
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int number;

    cout << "Task number (from 1 to 4) ?" << endl;   cin >> number;
    switch (number) {
    case 1: elementPossition();
        break;
    case 2: differenceBtPrevius();
        break;
    case 3: subsequence();
        break;
    case 4: transportation();
        break;
    default: cout << "Error.Enter number from 1 to 4" << endl; 
    }
    return 0;
    
}
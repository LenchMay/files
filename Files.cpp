#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
	ifstream in("input.txt");
	int** m; // Двумерный динамический массив

	int rows, cols;
	in >> rows >> cols;

	m = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		m[i] = new int[cols];
		in >> m[i][0];
		for (int k = 1; k < cols; ++k)
		{
			char comma;
			in >> comma >> m[i][k];
		}
	}
	in.close();

	double mean = 0;
	int max = m[0][0];
	int min = m[0][0];
	for (int i = 0; i < rows; i++) {
		for (int k = 0; k < cols; k++)
		{
			mean += m[i][k];
			if (m[i][k] > max) {
				max = m[i][k];
			}
			if (m[i][k] < min) {
				min = m[i][k];
			}
		}
	}
	mean /= (rows * cols);

	ofstream t1("out_row.txt");
	
	for (int i = 0; i < rows; i++) {
		int counter = 0;
		do {
			for (int k = 0; k < cols-1; k++){
				if (m[i][k] > m[i][k + 1]) {
					int temp = m[i][k];
					m[i][k] = m[i][k + 1];
					m[i][k + 1] = temp;
				}
			} 
			counter++;
		} while (counter < cols);
	}
	t1 << "max = " << max << "\nmin = " << min << "\nmean = " << mean << "\n";

	for (int i = 0; i < rows; i++) {
		for (int k = 0; k < cols; k++)
		{
			t1 << m[i][k] << " ";
		}
		t1 << "\n";
	}

	ifstream in2("input.txt");
	int** mas; // Двумерный динамический массив

	in2 >> rows >> cols;

	mas = new int* [rows];
	for (int i = 0; i < rows; ++i)
	{
		mas[i] = new int[cols];
		in2 >> mas[i][0];
		for (int k = 1; k < cols; ++k)
		{
			char comma;
			in2 >> comma >> mas[i][k];
		}
	}
	in2.close();

	for (int k = 0; k < cols; k++) {
		int counter = 0;
		do {
			for (int i = 0; i < rows - 1; i++) {
				if (mas[i][k] < mas[i + 1][k]) {
					int temp = mas[i][k];
					mas[i][k] = mas[i + 1][k];
					mas[i + 1][k] = temp;
				}
			}
			counter++;
		} while (counter < rows);
	}

	ofstream t2("out_col.txt");

	t2 << "max = " << max << "\nmin = " << min << "\nmean = " << mean << "\n";
	for (int i = 0; i < rows; i++) {
		for (int k = 0; k < cols; k++)
		{
			t2 << mas[i][k] << " ";
		}
		t2 << "\n";
	}

	return 0;
}
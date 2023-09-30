#include <Windows.h>
#include <iostream>
#include <random>
#include "MatrixOperation.h"

void printMatrix(double* matrix, int rows, int cols)
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << *(matrix + i * cols + j) << ' ';
		}
		std::cout << '\n';
	}
}

double GetRandomValue()
{
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_real_distribution<double> distr(1, 10);
	return distr(eng);
}

void GetRandomMatrix(double* dst, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			*(dst + i * cols + j) = GetRandomValue();
	return;
}

int main()
{
	LARGE_INTEGER f, t1, t2;
	double time1, time2;
	QueryPerformanceFrequency(&f);
	printf_s("frequency: %I64x Hz\n", f);

	double dst = 0;
	double* src1 = new double[9000000];
	double* src2 = new double[9000000];

	GetRandomMatrix((double*)src1, 3000, 3000);
	GetRandomMatrix((double*)src2, 3000, 3000);

	std::cout << "running!\n";


	// operation omp
	QueryPerformanceCounter(&t1);
	
	QueryPerformanceCounter(&t2);
	time1 = 1000000 * (double)(t2.QuadPart - t1.QuadPart) / (double)f.QuadPart;
	std::cout << "takes time:" << time1 << "us\n";

	// operation no omp
	QueryPerformanceCounter(&t1);
	
	QueryPerformanceCounter(&t2);
	time2 = 1000000 * (double)(t2.QuadPart - t1.QuadPart) / (double)f.QuadPart;
	std::cout << "takes time:" << time2 << "us\n";

	std::cout << "time2 - time1: " << time2 - time1 << '\n';
	std::cout << "time2 / time1: " << time2 / time1 << '\n';
	// printMatrix((double*)dst, 100, 100);

}


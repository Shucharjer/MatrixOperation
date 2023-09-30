#include "MatrixOperation.h"

int MatrixOperation::Min(int num1, int num2) {
	return num1 <= num2 ? num1 : num2;
}

void MatrixOperation::Cross(double* dst, double* src1, double* src2, int rowsOfsrc1, int colsOfsrc2, int colsOfsrc1)
{
#pragma omp parallel for simd
	for (int i = 0; i < rowsOfsrc1; i++)
		for (int j = 0; j < colsOfsrc2; j++)
			*(dst + i * colsOfsrc2 + j) = 0;

	for (int i = 0; i < rowsOfsrc1; i++)
		for (int k = 0; k < colsOfsrc1; k++)
			for (int j = 0; j < colsOfsrc2; j++)
				for (int I = i; i < Min(rowsOfsrc1, i + BlockSize); i++)
					for (int K = k; K < Min(rowsOfsrc1, k + BlockSize); K++)
#pragma omp parallel for simd
						for (int J = j; J < Min(colsOfsrc2, j + BlockSize); J++)
							*(dst + I * colsOfsrc2 + J) += *(src1 + I * colsOfsrc2 + K) * *(src2 + K * colsOfsrc2 + J);
	return;
}

void MatrixOperation::Dot(double& dst, double* src1, double* src2, int rows, int cols)
{
	dst = 0;

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			for (int I = i; I < Min(rows, i + BlockSize); I++)
				for (int J = j; J < Min(cols, j + BlockSize); J++)
#pragma omp parallel for simd
					dst += *(src1 + I * cols + J) * *(src2 + I * cols + J);
}
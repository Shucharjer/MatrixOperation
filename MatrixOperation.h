#pragma once

static int BlockSize = 8;

namespace MatrixOperation
{
	int Min(int num1, int num2);
	// ���
	void Cross(double* dst, double* src1, double* src2, int rowsOfsrc1, int colsOfsrc2, int colsOfsrc1);
	// ���
	void Dot(double& dst,double* src1, double* src2, int rows, int cols);
	// ת��
	void Transpose(double* dst, double* src, int rows, int cols);
	// ��
	void Trace();
	// ��
	void Rank();
	// ����ʽ
	void Det();
	// ��
	void Inv();
	// α��
	void PInv();
	// ��ƽ
	void Flatten();
	// ����ֵ����������
	void Eig();
}
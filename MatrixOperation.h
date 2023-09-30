#pragma once

static int BlockSize = 8;

namespace MatrixOperation
{
	int Min(int num1, int num2);
	// 叉乘
	void Cross(double* dst, double* src1, double* src2, int rowsOfsrc1, int colsOfsrc2, int colsOfsrc1);
	// 点乘
	void Dot(double& dst,double* src1, double* src2, int rows, int cols);
	// 转置
	void Transpose(double* dst, double* src, int rows, int cols);
	// 迹
	void Trace();
	// 秩
	void Rank();
	// 行列式
	void Det();
	// 逆
	void Inv();
	// 伪逆
	void PInv();
	// 扁平
	void Flatten();
	// 特征值和特征向量
	void Eig();
}
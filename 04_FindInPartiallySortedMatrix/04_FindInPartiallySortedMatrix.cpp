// 04_FindInPartiallySortedMatrix.cpp : 定义控制台应用程序的入口点。
// 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

bool Find(vector<vector<int>> &matrix,int rows,int cols,int number){
	bool found = false;

	if(&matrix != nullptr && cols > 0 && rows > 0){
		int col = 0;
		int row = rows - 1;
		while (col<cols && row>=0)
		{
			if (matrix[row][col] == number)
			{
				found = true;
				break;
			}else if (matrix[row][col] < number)
			{
				col++;
			}else{
				row--;
			}
		}
	}

	return found;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int rows,cols,number;
	while (cin>>rows>>cols>>number)
	{
		vector<vector<int>> matrix(rows,vector<int>(cols));
		for(int i=0;i<rows;++i)
			for(int j=0;j<cols;++j)
				cin>>matrix[i][j];

		if(Find(matrix,rows,cols,number))
			cout<<"Found."<<endl;
		else
			cout<<"Not Found."<<endl;
	}

	return 0;
}


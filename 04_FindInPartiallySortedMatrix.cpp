// 04_FindInPartiallySortedMatrix.cpp : �������̨Ӧ�ó������ڵ㡣
// ��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
// �����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������

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


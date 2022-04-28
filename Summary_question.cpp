#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include < time.h >
#include <iostream>
using namespace std;

class Algebraic_structure {
public:
	virtual float abs_oper() { return 0; };

};

class Real_number : public Algebraic_structure {
public:
	float num;
	void    mult_oper(float num) {this->num *= num; }
	void    plus_oper(float num) {this->num += num; }
	void   minus_oper(float num) {this->num -= num; }
	void  divide_oper(float num) {this->num /= num; }
	float abs_oper();
	Real_number( float num) { this->num = num; }
};

float Real_number::abs_oper()
{
	cout << "The absolute value of the number is ";
	if ( this->num < 0)
		return	this->num *= -1;
	else
		return this->num;
};

class matrix_str : public Algebraic_structure {
public:
	  float matrix[3][3];
	  matrix_str();
	  float** user_array();
	  void plus_oper (float** array);
	  void minus_oper(float** array);
	  void mult_oper (float** array);
	  float abs_oper();
	  void display_array();
};
matrix_str::matrix_str()
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Please enter 3 numbers in the row number " << i + 1 << "\n";
		for (int j = 0; j < 3; j++)
			cin >> matrix[i][j];
	}
};
void matrix_str::display_array()
{
	cout << "\n";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << matrix[i][j] << " ";
		cout << "\n";

	}
};
float** matrix_str::user_array()
{
	int i, j, a;
	int lines, columns;
	cout << "\nHow many lines are in the matrix\n ";
	cin >> lines;

	cout << "\nHow many columns are in the matrix\n ";
	cin >> columns;
	float** array = new float* [lines + 1];
	array[0] = new float[2];
	for (i = 1; i < lines + 1; i++)
	{
		array[i] = new float[columns];
	}
	for (i = 1; i < lines + 1; i++)
	{
		cout << "enter " << columns << " numbers for line number " << i << "\n";
		for (j = 0; j < columns; j++)
		{
			cin >> a;
			array[i][j] = a;
		}
		array[0][0] = lines;
		array[0][1] = columns;
	}
	return array;
}
void matrix_str::plus_oper(float** array)
{
	{
		int i, j;
		if ((array[0][0] == 3) && (array[0][1] == 3))                        //array[0][0] is the number of rows ,array[0][1] is the number of columns (matrix user)//
		{
			for (i = 1; i < 4; i++)
			{
				for (j = 0; j < 3; j++)
					matrix[i - 1][j] += array[i][j];
			}
			this->display_array();
		}
		else
			cout << "Sorry, It is not possible to perform a plus operation on this matrix";
	}
	delete[] *array;
	delete[]  array;
}

void matrix_str::minus_oper(float** array)
{
	{
	
		if ((array[0][0] == 3) && (array[0][1] == 3))                      //array[0][0] is the number of rows ,array[0][1] is the number of columns (matrix user)//
		{
			for (int i = 1; i < 4; i++)
			{
				for (int j = 0; j < 3; j++)
					matrix[i - 1][j] -= array[i][j];
			}
			this->display_array();
		}
		else
			cout << " Sorry, It is not possible to perform a minus operation on this matrix";
	}
	delete[] *array;
	delete[]  array;
}
void matrix_str::mult_oper(float** array)
{
	int i,j,x;
	int a= array[0][1];
	float** matrix_result;
	if (array[0][0] == 3)                                                //array[0][0] is the number of rows ,array[0][1] is the number of columns (matrix user)//
	{
		float** matrix_result = new float* [3];
		for (i = 0; i < 3; i++)
		{
			matrix_result[i] = new float[a];
		}
		for (x = 0; x < 3; x++)
		{
			matrix_result[x][i] = 0;
			for (i = 0; i < a; i++)
			{
				matrix_result[x][i] = 0;
				for (j = 0; j < 3; j++)
					matrix_result[x][i] += (matrix[x][j] * array[j + 1][i]);
			}
		}
		for (int i = 0; i < 3; i++)
			{
			for (int j = 0; j < a; j++)
				cout << matrix_result[i][j] << " ";
		     	cout << "\n";
	     	}
		delete[]  *matrix_result;
		delete[]  matrix_result;
	}
		else
			cout << " Sorry, It is not possible to perform a multiple operation on this matrix";
	delete[]  *array;
	delete[]  array;
}
float matrix_str::abs_oper()
{
	cout <<"The determinant of the matrix is ";
	return  (matrix[0][0] * (matrix[1][1] * matrix[2][2]) - (matrix[1][2] * matrix[2][1])) - (matrix[0][1] * ((matrix[1][0] * matrix[2][2]) - (matrix[1][2] * matrix[2][0]))) + matrix[0][2] * ((matrix[1][0] * matrix[2][1]) - (matrix[1][1] * matrix[2][0]));
}

class complex_number : public Algebraic_structure {
public:
	float real_number;
	float imaginary_number;
	complex_number  (float real_num, float im_num) { real_number = real_num; imaginary_number = im_num; }
	void   plus_oper(float real_num, float im_num);
	void  minus_oper(float real_num, float im_num);
	void   mult_oper(float real_num, float im_num,int display_result);
	void divide_oper(float real_num, float im_num);
	float   abs_oper();
	void display_comp_num();
};
void complex_number::display_comp_num()
{
	cout << "\nthe complex number is ";
	if (imaginary_number == 0)
		cout << real_number;
	if(imaginary_number<0)
		cout  << real_number <<  imaginary_number << "i";
	else
		cout  <<  real_number << "+" << imaginary_number << "i";
}
void  complex_number::plus_oper(float real, float imag)
{
	
	real_number += real;
	imaginary_number += imag;
	this->display_comp_num();
}
void  complex_number::minus_oper(float real, float imag)
{
	real_number -= real;
	imaginary_number -= imag;
	this->display_comp_num();
}
void  complex_number::mult_oper(float real, float imag, int display_result)
{
	float temp = real_number;
	real_number = (real_number * real) + (imaginary_number * imag * (-1));
	imaginary_number = (temp * imag) + (imaginary_number * real);
	if ( display_result)
	this->display_comp_num();
}
void  complex_number::divide_oper(float real, float imag)
{
	float temp = real_number;
	float attach_num = (imag * -1);
	this->mult_oper(real, attach_num,0);                                                 //0 ->In order not to display the result of mult..//
	real_number /= pow(real, 2)+ pow(imag,2);
	imaginary_number /= (real * real) + (imag * imag);
	this->display_comp_num();
}
float  complex_number::abs_oper()
{
	cout << "The size of the complex number is ";
	return sqrt(pow(real_number, 2) + pow(imaginary_number, 2));
}
void main()
{
	Algebraic_structure* index[5];
	Real_number a(5), b(-7);
	complex_number aa(5,-2), bb(-3,7) ;
	matrix_str aaa;
	index[0] = &a; 	index[1] = &aa; index[2] = &aaa; index[3] = &bb; index[4] = &b;
	for (int i = 0; i <5; i++)
	{
		cout << "\n";
		cout << index[i]->abs_oper();
	};
	aa.plus_oper(3,3);
	aa.divide_oper(6, -2);
	aaa.plus_oper(aaa.user_array());
	aaa.mult_oper(aaa.user_array());

	
	

	
	
	

	
}

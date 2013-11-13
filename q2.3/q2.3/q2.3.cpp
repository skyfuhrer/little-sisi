// q2.3.cpp : �������̨Ӧ�ó������ڵ㡣
//������λ���⣬�������ַ������飬�Ӽ������淨

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define SHIFTMAX 100
#define SHIFT 3

char test[10] = "abcdefghi";

void BlockShift(char *A,int shift);
void AcrobaticsShift(char *A,int shift);
void ReverseShift(char *A,int shift);
void Reverse(char *A,int len);



int _tmain(int argc, _TCHAR* argv[])
{
	//BlockShift(test,SHIFT);
	ReverseShift(test,SHIFT);
	printf("%s\n",test);
	system("pause");
	return 0;
}

//����strcpy��strcat���ַ��������һ��λ'\0'������
void BlockShift(char *A,int shift)
{
	char *temp = (char *)malloc(sizeof(shift+1));
	if(temp != NULL)
	{
		char *r = temp;
		char *g = A;
		for(int i = 1;i<=shift;i++)
		{
			*r++ = *g++;
		}
		*r = '\0';
		strcpy(A,g);
		strcat(A,temp);
	}
}

//�иĽ�֮����for(int i = 0;i<shift;i++)������i<gcd(n,shift)��������֤���ظ�����
//
void AcrobaticsShift(char *A,int shift)
{
	char temp;
	//int num = sizeof(A);//ָ���СΪ4
	int num = strlen(A);
	int j = 0;
	for(int i = 0;i<shift;i++)
	{
		temp = A[i];
		j = i ;
		while(1)
		{
			int k = j + SHIFT;
			if(k >= num)
				k -=num;
			if(k == i)
				break;
			A[j] = A[k];
			j = k;
		}
		A[j] = temp;
	}
}

void ReverseShift(char *A,int shift)
{
	char *temp = A + shift;
	int num = strlen(A);
	Reverse(A,shift);
	Reverse(temp,(num-shift));
	Reverse(A,num);
}

void Reverse(char *str,int len)
{ 
    char temp;   
    for(int i = 0; i < len / 2; i++ )   
    {   
		// ����ǰ��������Ӧλ�õ��ַ�   
        temp = *(str + i);   
        *(str + i) = *(str + len - 1 - i);   
        *(str + len - 1 - i) = temp;   
    }   
}

/*******************************************************************

Copyright(c) 2016, Harry He

All rights reserved.



Distributed under the BSD license.

(See accompanying file LICENSE.txt at

https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)

*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================


// ������3��һ�����ҳ��������ظ�������
// ��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
// Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
// ��ô��Ӧ��������ظ�������2����3��

#include <cstdio>


// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
//        duplication: (���) �����е�һ���ظ�������
// ����ֵ:             
//        true  - ������Ч�����������д����ظ�������
//        false - ������Ч������������û���ظ�������

//bool duplicate(int numbers[], int length, int* duplication)
//{
//	if (numbers == nullptr || length <= 0)
//		return false;
//
//	for (int i = 0; i < length; ++i)
//	{
//		if (numbers[i] < 0 || numbers[i] > length - 1)
//			return false;
//	}
//
//	for (int i = 0; i < length; ++i)
//	{
//		while (numbers[i] != i)
//		{
//			if (numbers[i] == numbers[numbers[i]])
//			{
//				*duplication = numbers[i];
//				return true;
//			}
//
//			//����numbers[i]��numbers[numbers[i]]���������ַŵ�������λ��             
//			int temp = numbers[i];
//			numbers[i] = numbers[temp];
//			numbers[temp] = temp;
//		}
//	}
//
//	return false;
//}

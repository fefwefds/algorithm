#include "stdio.h"
#include "math.h"


//��Ҫ�յ����� 
void Straight_Line_Interpolation(int x, int y);


int main(void)
{
	Straight_Line_Interpolation(59, 2);
}

//ֱ�߲�㷨 
//��Ҫ�յ����� 
void Straight_Line_Interpolation(int x, int y)
{
	//��ǰ������
	int draw[2] = { 35,38 };

	//E:�յ��ж� 
	//F:ƫ����� 
	//i:��ǰ�岹����������Ҫ����E�� 

	int E, F, i;
	E = abs(x-draw[0]) + abs(y-draw[1]);
	F = 0;

	//ѭ����������E������
	for (i = 0; i < E; i++)
	{

		//���ж�ƫ��F����������X����Y
		if (F >= 0)
		{
			//�ٸ����ж��յ�X,Y���ĸ����ޣ������������
			if (x > draw[0]) { draw[0]++; }
			else if (x < draw[0]) { draw[0]--; }

			//���㱾�β������µ�ƫ��F 
			F = F - abs(y-draw[1]);
			printf("(%d,%d)\r\n", draw[0], draw[1]);
		}

		//���ж�ƫ��F����������X����Y
		else if (F < 0)
		{
			//�ٸ����ж��յ�X,Y���ĸ����ޣ������������
			if (y > draw[1]) { draw[1]++; }
			else if (y < draw[1]) { draw[1]--; }

			//���㱾�β������µ�ƫ��F 
			F = F + abs(x-draw[0]);
			printf("(%d,%d)\r\n", draw[0], draw[1]);

		}
	}
}

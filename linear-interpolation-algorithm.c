#include "stdio.h"
#include "math.h"


//需要终点坐标差补 
void Straight_Line_Interpolation(int x, int y);


int main(void)
{
	Straight_Line_Interpolation(59, 2);
}

//直线差补算法 
//需要终点坐标差补 
void Straight_Line_Interpolation(int x, int y)
{
	//当前点坐标
	int draw[2] = { 35,38 };

	//E:终点判断 
	//F:偏差计算 
	//i:当前插补步数（最终要等于E） 

	int E, F, i;
	E = abs(x-draw[0]) + abs(y-draw[1]);
	F = 0;

	//循环次数就是E决定的
	for (i = 0; i < E; i++)
	{

		//先判断偏差F，决定进给X还是Y
		if (F >= 0)
		{
			//再根据判断终点X,Y在哪个象限，决定进给情况
			if (x > draw[0]) { draw[0]++; }
			else if (x < draw[0]) { draw[0]--; }

			//计算本次产生的新的偏差F 
			F = F - abs(y-draw[1]);
			printf("(%d,%d)\r\n", draw[0], draw[1]);
		}

		//先判断偏差F，决定进给X还是Y
		else if (F < 0)
		{
			//再根据判断终点X,Y在哪个象限，决定进给情况
			if (y > draw[1]) { draw[1]++; }
			else if (y < draw[1]) { draw[1]--; }

			//计算本次产生的新的偏差F 
			F = F + abs(x-draw[0]);
			printf("(%d,%d)\r\n", draw[0], draw[1]);

		}
	}
}

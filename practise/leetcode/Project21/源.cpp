#define _CRT_SECURE_NO_WARNINGS 1
//求结点数为n的二叉树的深度
int depth(int n)
{
	assert(n >= 0);

	if (n > 0)
	{
		int m = 2;
		int hight = 1;
		while (m < n + 1)
		{
			m *= 2;
			hight++;
		}
		return hight;
	}
	else
	{
		return 0;
	}
}

//打印堆
void HeapPrint(HP* php)
{
	assert(php);
	//按照物理结构进行打印
	int i = 0;
	for (i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
	//按照树形结构进行打印
	int h = depth(php->size);
	int N = (int)pow(2, h) - 1;//与该二叉树深度相同的满二叉树的结点总数
	int space = N - 1;//记录每一行前面的空格数
	int row = 1;//当前打印的行数
	int pos = 0;//待打印数据的下标
	while (1)
	{
		//打印前面的空格
		int i = 0;
		for (i = 0; i < space; i++)
		{
			printf(" ");
		}
		//打印数据和间距
		int count = (int)pow(2, row - 1);//每一行的数字个数
		while (count--)//打印一行
		{
			printf("%02d", php->a[pos++]);//打印数据
			if (pos >= php->size)//数据打印完毕
			{
				printf("\n");
				return;
			}
			int distance = (space + 1) * 2;//两个数之间的空格数
			while (distance--)//打印两个数之间的空格
			{
				printf(" ");
			}
		}
		printf("\n");
		row++;
		space = space / 2 - 1;
	}
}

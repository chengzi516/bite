#define _CRT_SECURE_NO_WARNINGS 1
//������Ϊn�Ķ����������
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

//��ӡ��
void HeapPrint(HP* php)
{
	assert(php);
	//��������ṹ���д�ӡ
	int i = 0;
	for (i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
	//�������νṹ���д�ӡ
	int h = depth(php->size);
	int N = (int)pow(2, h) - 1;//��ö����������ͬ�����������Ľ������
	int space = N - 1;//��¼ÿһ��ǰ��Ŀո���
	int row = 1;//��ǰ��ӡ������
	int pos = 0;//����ӡ���ݵ��±�
	while (1)
	{
		//��ӡǰ��Ŀո�
		int i = 0;
		for (i = 0; i < space; i++)
		{
			printf(" ");
		}
		//��ӡ���ݺͼ��
		int count = (int)pow(2, row - 1);//ÿһ�е����ָ���
		while (count--)//��ӡһ��
		{
			printf("%02d", php->a[pos++]);//��ӡ����
			if (pos >= php->size)//���ݴ�ӡ���
			{
				printf("\n");
				return;
			}
			int distance = (space + 1) * 2;//������֮��Ŀո���
			while (distance--)//��ӡ������֮��Ŀո�
			{
				printf(" ");
			}
		}
		printf("\n");
		row++;
		space = space / 2 - 1;
	}
}

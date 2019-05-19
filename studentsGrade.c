#include <stdio.h>
/*
	5�� �л����� �й�, �̸�, ����, ����, ���� ������ �а� ����, ����� ���Ͽ� ��� ���Ŀ� ���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	��, �迭, �ݺ���, �Լ�, ������ ���� �̿��ϰ� �Է¼�(������)���� ���
	�������> ����  �й�  �̸�  ����  ����  ����  ���  �׷���
*/
float c_avg(int *sp);
void c_rank(float *ap, int *rp);
void sort(int *rp);
void star(float *ap, char **gp);

int s[5] = { 0, 1, 2, 3, 4 };

void main()
{
	char number[5][4], name[5][20];
	char *sub_name[3] = { "����", "����", "����" }, *graph[5] = { '\0' };
	int subject[5][3], rank[5] = { 0 }, i, j, srt;
	float avg[5];

	/*�Է�*/
	i = 0;
	while (i < 5)
	{
		printf("�й� : ");
		scanf("%s", number[i]);

		printf("�̸� : ");
		scanf("%s", name[i]);

		j = 0;
		while (j < 3)
		{
			printf("%s���� : ", sub_name[j]);
			scanf("%d", &subject[i][j]);
			j++;
		}
		i++;
	}

	/*��� �� ����*/
	i = 0;
	while (i < 5)
	{
		avg[i] = c_avg(subject[i]); // ��� ���
		rank[i] = 1; // rank �迭 ��� 1�� �ʱ�ȭ(�л����� 100���϶��� ���� ����� ���ÿ� 1�� �ʱ�ȭ�ϱⰡ ����ϱ�...)
		i++;
	}

	c_rank(avg, rank); // ���� ���
	sort(rank); // ������ �������� �������� ����
	star(avg, graph); // �׷��� ���

	/*���*/
	printf("����\t �й�\t �̸�\t ����\t ����\t ����\t ���\t �׷���\n");

	i = 0;
	while (i < 5)
	{
		srt = s[i];
		printf("%d\t %s\t %s\t", rank[srt], number[srt], name[srt]);

		j = 0;
		while (j < 3)
		{
			printf("%d\t", subject[srt][j]);
			j++;
		}
		printf("%.2f\t %s\n", avg[srt], graph[srt]);
		i++;
	}
}

float c_avg(int *sp)
{// ��� ���ϴ� �Լ�
	int i, sum = 0;
	float avg;

	i = 0;
	while (i < 3)
	{
		sum += *(sp + i);
		i++;
	}

	avg = sum / 3.;

	return avg;
}

void c_rank(float *ap, int *rp)
{// ���� ���ϴ� �Լ�
	int i, j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 5)
		{
			if (*(ap + i) < *(ap + j))
			{
				*(rp + i) += 1;
			}
			else if (*(ap + i) > *(ap + j))
			{
				*(rp + j) += 1;
			}
			j++;
		}
		i++;
	}
}

void sort(int *rp)
{// ������ �������� �������� �������ִ� �Լ�
	int i, j, tmp;
	extern int s[5];

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 5)
		{
			if (*(rp + i) > *(rp + j))
			{// ������ �������� �������� ����
				tmp = s[i];
				s[i] = s[j];
				s[j] = tmp;
			}
			j++;
		}
		i++;
	}

}

void star(float *ap, char **gp)
{// ��������� �������� �׷����� ��Ÿ���ִ� �Լ�
	int i;
	float avg;

	i = 0;
	while (i < 5)
	{
		avg = *(ap + i);
		switch ((int)avg / 10)
		{
		case 10:
			*(gp + i) = "**********";
			break;
		case 9:
			*(gp + i) = "*********";
			break;
		case 8:
			*(gp + i) = "********";
			break;
		case 7:
			*(gp + i) = "*******";
			break;
		case 6:
			*(gp + i) = "******";
			break;
		case 5:
			*(gp + i) = "*****";
			break;
		case 4:
			*(gp + i) = "****";
			break;
		case 3:
			*(gp + i) = "***";
			break;
		case 2:
			*(gp + i) = "**";
			break;
		default:
			*(gp + i) = "*";
		}
		i++;
	}
}
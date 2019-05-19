#include <stdio.h>
/*
	5명 학생들의 학번, 이름, 국어, 영어, 수학 점수를 읽고 석차, 평균을 구하여 출력 형식에 맞춰 결과를 출력하는 프로그램을 작성하시오.
	단, 배열, 반복문, 함수, 포인터 등을 이용하고 입력순(석차순)으로 출력
	출력형식> 석차  학번  이름  국어  영어  수학  평균  그래프
*/
float c_avg(int *sp);
void c_rank(float *ap, int *rp);
void sort(int *rp);
void star(float *ap, char **gp);

int s[5] = { 0, 1, 2, 3, 4 };

void main()
{
	char number[5][4], name[5][20];
	char *sub_name[3] = { "국어", "영어", "수학" }, *graph[5] = { '\0' };
	int subject[5][3], rank[5] = { 0 }, i, j, srt;
	float avg[5];

	/*입력*/
	i = 0;
	while (i < 5)
	{
		printf("학번 : ");
		scanf("%s", number[i]);

		printf("이름 : ");
		scanf("%s", name[i]);

		j = 0;
		while (j < 3)
		{
			printf("%s점수 : ", sub_name[j]);
			scanf("%d", &subject[i][j]);
			j++;
		}
		i++;
	}

	/*계산 및 정렬*/
	i = 0;
	while (i < 5)
	{
		avg[i] = c_avg(subject[i]); // 평균 계산
		rank[i] = 1; // rank 배열 모두 1로 초기화(학생수가 100명일때는 변수 선언과 동시에 1로 초기화하기가 힘드니까...)
		i++;
	}

	c_rank(avg, rank); // 석차 계산
	sort(rank); // 석차를 기준으로 오름차순 정렬
	star(avg, graph); // 그래프 계산

	/*출력*/
	printf("석차\t 학번\t 이름\t 국어\t 영어\t 수학\t 평균\t 그래프\n");

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
{// 평균 구하는 함수
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
{// 석차 구하는 함수
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
{// 석차를 기준으로 오름차순 정렬해주는 함수
	int i, j, tmp;
	extern int s[5];

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 5)
		{
			if (*(rp + i) > *(rp + j))
			{// 석차를 기준으로 오름차순 정렬
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
{// 평균점수를 기준으로 그래프를 나타내주는 함수
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
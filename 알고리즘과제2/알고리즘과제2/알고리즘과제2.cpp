#include<stdio.h>
#include<math.h>

void find_tour(int p, int level);
double distance(int x1, int y1, int x2, int y2);

typedef struct {
	int x;
	int y;
	int check_visit = 0;
} tour;

tour point[20];
int n;
int temp[20];
int tour_index[20];
double dis_min = 0, dis = 0;

int main() {

	FILE *fp;
	fopen_s(&fp, "input2.txt", "r");
	if (fp == NULL)
	{
		printf("test.txt 파일 오픈 불가\n");
		fclose(fp);
	}
	fscanf_s(fp, "%d", &n);	

	for (int i = 0; i < n; i++) {
		fscanf_s(fp, "%d", &point[i].x);
		fscanf_s(fp, "%d", &point[i].y);
	}
	fclose(fp);

	for (int p = 0; p < n; p++)
		find_tour(p, 0);
	printf("n = %d\n",n);
	for (int q = 0; q < n; q++)
		printf("%d %d\n", point[q].x, point[q].y);
	printf("%lf\n", dis_min);
	for(int j=n-1;j>=0;j--)
		printf("%d ", tour_index[j]);
	return 0;
}

void find_tour(int p, int level) {
	point[p].check_visit = 1;
	temp[level] = p;
	if (level == n-1)
	{
		for (int k = 0; k < n; k++)
		{
				dis += distance(point[temp[k]].x, point[temp[k]].y, point[temp[k + 1]].x, point[temp[k + 1]].y);
			if(k == n-1)
				dis += distance(point[temp[k]].x, point[temp[k]].y, point[temp[0]].x, point[temp[0]].y);
		}
		if (dis_min == 0)
			dis_min = dis;
		if (dis < dis_min) {
			dis_min = dis;
			for (int j = 0; j < n; j++)
				tour_index[j] = temp[j];
		}
		dis = 0;
	}
	for (int i = 0; i < n; i++) {
		if (point[i].check_visit == 1)
			continue;
		find_tour(i, level + 1);
	}
	point[p].check_visit = 0;
}

double distance(int x1, int y1, int x2, int y2)
{	
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}










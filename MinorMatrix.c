#include <stdio.h>
#include<time.h>
#define MAX 3
void matrisCreate(float matris[][MAX]);
void matrisPrint(float matris[][MAX]);
void minorMatrisFind(float matris[][MAX], float minorMatris[][MAX]);
float determinantFind(float matris[][MAX], int i, int j);
int main() {
	float matris[MAX][MAX], minorMatris[MAX][MAX];
	srand(time(NULL));
	system("cls");
	matrisCreate(matris);
	system("cls");
	matrisPrint(matris);
	minorMatrisFind(matris, minorMatris);
	
	
	return 0;
}

void matrisCreate(float matris[][MAX]){
	int i, j;
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			matris[i][j] = rand()%10;
		}
	}
}

void matrisPrint(float matris[][MAX]){
	int i, j;
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			printf("%f\t", matris[i][j]);
		}
		printf("\n\n");
	}
}

void minorMatrisFind(float matris[][MAX], float minorMatris[][MAX]){
	int i, j, k, l, counter=0;
	int numbers[MAX+1];
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			minorMatris[i][j] = determinantFind(matris, i, j);
		}
	}
	printf("\n");
	matrisPrint(minorMatris);
}


float determinantFind(float matris[][MAX], int i, int j){
	int k, l, x=0, y=0;
	float determinantMatris[MAX-1][MAX-1];
	float det=0;
	// i,j pozisyonundaki eleman için determinantý hesaplamak üzere kalan elemanlarý bulan döngü
		for(k=0;k<MAX;k++){
			for(l=0;l<MAX;l++){
				if(i!=k || j!=l){
				determinantMatris[x][y]	= matris[k][l];
				y++;
				if(y>MAX-1){
					y=0;
					x++;
				}
				if(x>MAX-1){
					x=0;
				}
				}
			}
		}
		det = determinantMatris[0][0]*determinantMatris[1][1] - determinantMatris[0][1]*determinantMatris[1][0];
}

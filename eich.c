/*
Eich Institut dingens
Hausaufgaben
*/

#include<stdio.h>
#include<math.h>

int main()
{
	float initialwerte[21][2] = {
		{0.0, 0.15},
		{0.1, 0.55},
		{0.2, 0.89},
		{0.3, 1.50},
		{0.4, 1.95},
		{0.5, 1.97},
		{0.6, 2.91},
		{0.7, 3.20},
		{0.8, 3.46},
		{0.9, 3.40},
		{1.0, 4.22},
		{1.1, 5.11},
		{1.2, 5.06},
		{1.3, 5.70},
		{1.4, 5.89},
		{1.5, 5.65},
		{1.6, 6.90},
		{1.7, 7.04},
		{1.8, 8.16},
		{1.9, 8.00},
		{2.0, 8.61}};

	int i, zeile;
	float Q, U0, Ui, Diff, Proz, maxProz;
	maxProz = 0.0;

	printf("Q[cubm/h]\tU0[V]\tUi[V]\tDiff[V]\t %%\n");
	for(i=0; i < 21; i++){
		Q = initialwerte[i][0];
		U0 = initialwerte[i][1];
		Ui = (4.7 * Q) + 0.13;
		Diff = U0 - Ui;
		Proz = (Diff * 100) / U0;
		absProz = Proz;
		
		if(absProz < 0){
			absProz = absProz * -1;
		}

		printf("%.2f\t\t%.2f\t%.2f\t%+.2f\t%+.2f\n", Q, U0, Ui, Diff, Proz);

		if(absProz > maxProz){
			maxProz = absProz;
			zeile = i + 1;
		}


	}
	printf("Maximale Abweichung: %.2f%% bei Messwert %d\n", maxProz, zeile);
	if(maxProz > 5.0){
		printf("Prüfung nicht bestanden\n");
	}else{
		printf("Prüfung bestanden!\n");
	}
}

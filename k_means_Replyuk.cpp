#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <stdbool.h>
#include <math.h>

float compute(float x1, float x2, float y1, float y2);
float compute_s(float a, float b);

const int max_iterations = 30;  	
	
int main()
{
	FILE *file = fopen("input2.txt", "r");
    
	srand (time(NULL));
	
	int k_points;
    printf("Points: ");
    scanf("%d", &k_points);
    
    int k_klasters;
    printf("Klasters: ");
    scanf("%d", &k_klasters);
    
    //int poitns[k_points][2];
    
    float **poitns = (float **)malloc(k_points*sizeof(float *));
    	for(int i = 0; i < k_points; i++) {
        	poitns[i] = (float *)malloc(2*sizeof(float));
    	}
    	
    	//nacitanie data zo subora
    while (!feof(file)) {
		for (int i = 0; i < k_points; i++){
			//printf("Point %d\n", i);
       		for (int j = 0; j < 2; j++){
           		fscanf(file, "%f", &poitns[i][j]);          		
           		//printf("%.0f ", poitns[i][j]);//vypis vstupu
			}
        //printf("\n");
    	}
	}	
	fclose(file);
   
    //int centers[k_klasters][2];
    float **centers = (float **)malloc(k_klasters*sizeof(float *));
    	for(int i = 0; i < k_klasters; i++) {
        	centers[i] = (float *)malloc(2*sizeof(float));
    	}
    	
    
    
    //randomny vyber centry klaasterov
    for(int i = 0; i < k_klasters;i++){
    	//int a[k_klasters][2];
    	int b = rand() % k_points;
    	//printf("B: %d ",b);
    	for(int j = 0; j<2;j++){
    		 centers[i][j] = poitns[b][j];
    		 //printf("F(rand): %.2f ",centers[i][j]);//vypis centrov
		}
		//printf("\n");
	}	
	
	int *ans2;
	ans2 = (int*)malloc(k_points * sizeof(int));
	
	//float answer[k_points][k_klasters];
	float **answer = (float **)malloc(k_points*sizeof(float *));
    for(int i = 0; i < k_points; i++) {
    answer[i] = (float *)malloc(k_klasters*sizeof(float));
  	}
			
			
///sam metod

	// vector 1 pre iteracie
	int *check1;
	check1 = (int*)malloc(k_points * sizeof(int));
	//vector 2 pre iteracie 
	int *check2;
	check2 = (int*)malloc(k_points * sizeof(int));
	
	int iter = 1;
	
	float **f = (float **)malloc(k_points*sizeof(float *));
    for(int i = 0; i < k_points; i++) {
    f[i] = (float *)malloc(k_klasters*sizeof(float));
  	}
  	

	while(1){
		
	int min = 0;
	
	for(int i = 0; i < k_points; i++){
		float k = 0;
		for(int j = 0; j < k_klasters; j++){
			f[i][j] = compute(poitns[i][0],centers[j][0],poitns[i][1],centers[j][1]);
			//printf("F: %.2f ",f[i][j]);
		}
		k = f[i][0];
		for(int j = 0; j < k_klasters; j++){
			if(f[i][j] < k){
				k = f[i][j];
				min = j;
		    }
		}
		centers[min][0] = compute_s(poitns[i][0],centers[min][0]);
		centers[min][1] = compute_s(poitns[i][1],centers[min][1]);
		//printf("\n");

	}
	

	//klastering
	
	for(int i = 0;i<k_points;i++){
		float s = 0;
		
		for(int j = 0;j<k_klasters;j++){
			answer[i][j] = compute(poitns[i][0],centers[j][0],poitns[i][1],centers[j][1]);
			printf("Answer %.2f ", answer[i][j]);
		}
		
		s = answer[i][0];
		int k_min = 0;
		for(int j = 0;j<k_klasters;j++){
			if(answer[i][j] < s){
				s = answer[i][j];
				k_min = j;
			}
		}
		
		 ans2[i] = k_min;
		 printf("ans2: %d\n", ans2[i]+1);
	}
		
	for (int i = 0; i < k_points; i++) {
		check1[i] = ans2[i];
	}
	
	int prov = 0;
	for(int i = 0; i < k_points; i++){
		if (check1[i] == check2[i]) {
			prov++;
		}			
	}	
	
	if(prov == k_points || iter >= max_iterations){
		printf("Iteration: %d\n", iter);
		break;
	}
	
	prov = 0;
	
	for (int i = 0; i < k_points; i++) {
	check2[i] = check1[i];
	}
	iter++;
    } 


//vysledok

	for (int i = 0; i < k_klasters; i++) {
		printf("Klaster %d: ", i+1);
		for(int j = 0; j < k_points; j++){
			if(i == ans2[j]){
				printf("%d ", j+1);
			}
		}
		printf("\n");
	}


// cistenie pameti
	for(int i = 0; i < k_points; i++) {
    	free(poitns[i]);
    }
    free(poitns);
    
    
   for(int i = 0; i < k_klasters; i++) {
    	free(centers[i]);
    }
    free(centers);
    
    
    for(int i = 0; i < k_points; i++) {
    	free(f[i]);
   }
    free(f);
    


  return 0;
}



float compute(float x1, float x2, float y1, float y2){
		return sqrt(pow((x2 - x1),2) + pow((y2 - y1), 2));
	}

float compute_s(float a, float b) {
		return (a + b) / 2;
	};

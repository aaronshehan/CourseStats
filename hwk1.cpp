#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "bubble.h"

	struct classStats{	//structure that holds mean, min, max, and median class grades, as well as the class name
		float mean;
		float min;
		float max;
		float median;
		char* name;
	}stats;
	
int main()
{


	student* stInfo[19]; 	//array of student pointers, stores student name, grades, and grade average
	int i; // variable for for loops

	for (i = 0; i < 19; i++){
		stInfo[i] = (student*) malloc(sizeof(student));	//allocates memory for each student
	}
	
	stats.name = (char*) malloc(12); //allocates memory for for class name
	scanf("%s", stats.name);

	for (i = 0; i < 19; i++){	//loop to allocate memory for each students first and last name, also reads in data to the student structure
			stInfo[i]->first = (char*) malloc(12);
			stInfo[i]->last = (char*) malloc(12);
			scanf("%s %s %d %d %d",stInfo[i]->first,stInfo[i]->last,&stInfo[i]->exam1,&stInfo[i]->exam2,&stInfo[i]->exam3);
	}

	stats.mean = 0; //member of classStats structure initialized to zero, holds class average

	for (i = 0; i < 19; i++){	//loops through student structure to calculate each students average
		stInfo[i]->mean = (stInfo[i]->exam1 + stInfo[i]->exam2 + stInfo[i]->exam3) / 3.0;
		stats.mean += stInfo[i]->mean;
	}

	bubble(stInfo,19);	//calls bubble sort function to sort students by grade average

	stats.min = stInfo[0]->mean;	//after sort, first member of array will be minimum value
	stats.max = stInfo[18]->mean;	//after sort, last member of array will be maximum value
	stats.median = stInfo[9]->mean;	//after sort, 9th member will always be the median


	printf("123456789012345678901234567890123456789012345678901234567890\n");
	printf("%s MEAN:  %.2f MIN:  %.2f MAX:  %.2f MEDIAN:  %.2f\n",stats.name, stats.mean/19, stats.min, stats.max, stats.median);
	
	for (i = 0; i < 19; i++){
		printf("%12s %11s  %.2f\n",stInfo[i]->first,stInfo[i]->last,stInfo[i]->mean);
	}
	
	




	free(stats.name);	//frees memory of class name
	
	for(i = 0; i < 19; i++){	//frees memory for first, last name and for each structure
		free(stInfo[i]->first);
		free(stInfo[i]->last);
		free(stInfo[i]);
	} 

		
	
	

  return 0;
}

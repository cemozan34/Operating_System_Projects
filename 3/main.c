// Cem OZAN / 250201003 - Like in Homework 1, I wrote my code in CodeBlocks IDE(Windows) and then test my code in ORACLE VM VirtualBox's Ubuntu console. And cannot find any mistake.
//And my gcc version __STDC_VERSION__ : 201710L . I think this is C17. (But not sure)
// I find the __STDC_VERSION__ value using "gcc -dM -E - < /dev/null" command.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>

#define BUFFER_SIZE 1000
#define MAX_THREAD 4
#define BILLION 1E9
#define totalBookNumber 10

int countOccurrences(FILE *fptr, const char *word);
int wCount1;

typedef struct Words{ // Struct for storing names in it.
	char name[20];
}Word;

void* multi(void* arg)
{

	int* core = (int*)arg;
	char line[BUFFER_SIZE][BUFFER_SIZE];
	char fname[] = "englishstopwords.txt";
	FILE *ftr = NULL;
	int i = 0;

	char allBooks[][20] = {"book1.txt","book2.txt","book3.txt","book4.txt","book5.txt","book6.txt","book7.txt","book8.txt","book9.txt","book10.txt"};
	char recentBook1[20],recentBook2[20],recentBook3[20],recentBook4[20];
	ftr = fopen(fname, "r");
	while(fgets(line[i], BUFFER_SIZE, ftr)) // Loop that reads engslishstopwords.txt file and put the words in line array.
	{
		i++;
	}
    	FILE *fptr;

		for(int k = 0 ; k < 851 ; k++){ // Loop that computes and prints word counter in related files.


			Word word;
			strcpy(word.name,line[k]);
			if(MAX_THREAD == 1){
				for(int l = 0 ; l < totalBookNumber ; l++){
					strcpy(recentBook1,allBooks[l]);

					fptr = fopen(recentBook1, "r");
					if (fptr == NULL)
		    			{

					printf("Unable to open file.\n");
					printf("Please check you have read/write previleges.\n");
					exit(EXIT_FAILURE);
		    			}
		    			else{

		    			wCount1 = countOccurrences(fptr, word.name);
		    			printf("%s found in %s, %d times\n",word.name,recentBook1,wCount1);
		    			fclose(fptr);

		    			}
				}

			}

			if (MAX_THREAD == 2){
				if(*core == 0){

						for(int l = 0 ; l < (totalBookNumber/2) ; l++){
							strcpy(recentBook1,allBooks[l]);

							fptr = fopen(recentBook1, "r");
							if (fptr == NULL)
				    			{

							printf("Unable to open file.\n");
							printf("Please check you have read/write previleges.\n");
							exit(EXIT_FAILURE);
				    			}
				    			else{

				    			wCount1 = countOccurrences(fptr, word.name);
				    			printf("%s found in %s, %d times\n",word.name,recentBook1,wCount1);
				    			fclose(fptr);

		    					}
						}

				}

				else if(*core == 1){
						for(int l = (totalBookNumber/2) ; l < (totalBookNumber) ; l++){
							strcpy(recentBook2,allBooks[l]);

							fptr = fopen(recentBook2, "r");
							if (fptr == NULL)
				    			{

							printf("Unable to open file.\n");
							printf("Please check you have read/write previleges.\n");
							exit(EXIT_FAILURE);
				    			}
				    			else{

				    			wCount1 = countOccurrences(fptr, word.name);
				    			printf("%s found in %s, %d times\n",word.name,recentBook2,wCount1);
				    			fclose(fptr);

		    					}
						}

				}
			}


			if(MAX_THREAD == 4){
				if(*core == 0){
					for(int l = 0 ; l < (totalBookNumber/4) ; l++){
							strcpy(recentBook1,allBooks[l]);

							fptr = fopen(recentBook1, "r");
							if (fptr == NULL)
				    			{

							printf("Unable to open file.\n");
							printf("Please check you have read/write previleges.\n");
							exit(EXIT_FAILURE);
				    			}
				    			else{

				    			wCount1 = countOccurrences(fptr, word.name);
				    			printf("%s found in %s, %d times\n",word.name,recentBook1,wCount1);
				    			fclose(fptr);

		    					}
						}

				}
				if(*core == 1){
						for(int l = (totalBookNumber/4) ; l < (totalBookNumber/2) ; l++){
							strcpy(recentBook2,allBooks[l]);

							fptr = fopen(recentBook2, "r");
							if (fptr == NULL)
				    			{

							printf("Unable to open file.\n");
							printf("Please check you have read/write previleges.\n");
							exit(EXIT_FAILURE);
				    			}
				    			else{

				    			wCount1 = countOccurrences(fptr, word.name);
				    			printf("%s found in %s, %d times\n",word.name,recentBook2,wCount1);
				    			fclose(fptr);

		    					}
						}

				}
				if(*core == 2){
					for(int l = (totalBookNumber/2) ; l < ((totalBookNumber/4) * 3) + 1 ; l++){
							strcpy(recentBook3,allBooks[l]);

							fptr = fopen(recentBook3, "r");
							if (fptr == NULL)
				    			{

							printf("Unable to open file.\n");
							printf("Please check you have read/write previleges.\n");
							exit(EXIT_FAILURE);
				    			}
				    			else{

				    			wCount1 = countOccurrences(fptr, word.name);
				    			printf("%s found in %s, %d times\n",word.name,recentBook3,wCount1);
				    			fclose(fptr);

		    					}
						}

				}
				if(*core == 3){
					for(int l = ((totalBookNumber/4) * 3) + 1 ; l < totalBookNumber ; l++){
							strcpy(recentBook4,allBooks[l]);

							fptr = fopen(recentBook4, "r");
							if (fptr == NULL)
				    			{

							printf("Unable to open file.\n");
							printf("Please check you have read/write previleges.\n");
							exit(EXIT_FAILURE);
				    			}
				    			else{

				    			wCount1 = countOccurrences(fptr, word.name);
				    			printf("%s found in %s, %d times\n",word.name,recentBook4,wCount1);
				    			fclose(fptr);

		    					}
						}

				}
			}
		}
	pthread_exit(NULL);
}




int main(int argc, char* argv[])
{

	pthread_t threads[MAX_THREAD];
	struct timespec requestStart, requestEnd;
	clock_gettime(CLOCK_REALTIME, &requestStart);
    // Creating threads wrt MAX_THREAD
	for (int i = 0; i < MAX_THREAD; i++) {
		int* p = malloc(sizeof(int));
		*p=i;
		pthread_create(&threads[i], NULL, multi, p);
	}


	// joining all threads
	for (int i = 0; i < MAX_THREAD; i++){
		pthread_join(threads[i], NULL);
	}
	clock_gettime(CLOCK_REALTIME, &requestEnd);
	double accum = ( requestEnd.tv_sec - requestStart.tv_sec ) + ( requestEnd.tv_nsec - requestStart.tv_nsec ) / BILLION; // Calculating time spent
	printf("Total time spent %lf, for %d threads\n", accum, MAX_THREAD);
    return 0;
}



int countOccurrences(FILE *fptr, const char *word) // Function that calculates number of occurence a word in a file. For exampla, Not counted available word in able englishstopword occurence number.
{
    char str[BUFFER_SIZE];
    char *pos;

    int index, count;

    count = 0;

    // Read line from file till end of file.
    while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
    {
        index = 0;

        // Find next occurrence of word in str
        while ((pos = strstr(str + index, word)) != NULL )
        {
            // Index of word in str is
            // Memory address of pos - memory
            // address of str.
            index = (pos - str) + 1;

            count++;
        }
    }

    return count;
}


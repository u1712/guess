#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <readline/readline.h>
#include <string.h>
#include <unistd.h>

int main(void) {
	srand(time(NULL));
	
	printf("Welcome to the random number guessing game\n\tEnjoy!\n");

	char *max_str = readline("What's the maximum value?\n");
	int max = atoi(max_str);
	char *min_str = readline("What's the minimum value?\n");
	int min = atoi(min_str);

	double chances = 100.0 / (max - min + 1);

	if (max <= min) {
		printf("THE MINIMUM VALUE CAN'T BE MORE THAN(THE SAME AS) THE MAXIMUM\nget out\n");
		exit(1);
	}
	
	printf("Are you really sure?\nYour chances of winning are : %.2f%%!!\n", chances);
	char *answer = readline("(y/n): \n");
	if ((strcmp(answer, "y") == 0) || (strcmp(answer, "Y") == 0)) {
		int r = rand() % (max - min + 1) + min;
		char *usr_str = readline("Enter your guess: \n");
		int usr = atoi(usr_str);
		if (r == usr) {
			printf("you cheated right -_-\nnot cool\n");
		} else {
			printf("You WON ....... jk you lost what did you expect\nit was: %d\n", r);
		}
		free(usr_str);
	} else if ((strcmp(answer, "n") == 0) || (strcmp(answer, "N") == 0)) {
		printf("coward\n");	
	}
	free(max_str);
	free(min_str);
	free(answer);
	return 0;
}

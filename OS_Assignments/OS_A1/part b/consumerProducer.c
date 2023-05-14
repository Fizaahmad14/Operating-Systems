#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINE 2000
int countDigits(int number)  
{  
	int i = 0; 
	while(number!=0)  
    	{  
		number/=10;  
        	i++;  
	}  
    	return i;  
} 
int main(int argc, char* argv[])
{
	int read_1  = atoi(argv[1]);
	int write_1 = atoi(argv[3]);
	int read_2  = atoi(argv[4]);
	int write_2 = atoi(argv[2]);
	//closing write descriptor to read from pipe 1
	close(write_1);
	char recieved1[MAXLINE] ;
	//reading the message recieved from pipe 1
	printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><>IN CONSUMER PRODUCER PROGRAM(%d)\n",getpid());
	printf("\nRecieving....\n");
	read(read_1,recieved1,sizeof(recieved1));
	sleep(1);
	//displaying the recieved message
	printf("✂️-Contents recieved from producerConsumer program (%d)-*\n",getppid());
	printf("--------------------------------------------------------\n");
	printf(" >> Message from (%d): \n",getppid());
	printf("%s", recieved1);
	printf("--------------------------------------------------------\n");
			
	/*declaring and initializing variables to count
	characters, words, and lines in string*/
	int number_of_characters = 0;
	int number_of_words      = 0;
	int number_of_lines      = 0;
	int spaces               = 0;
	int i = 0;
	//traversing the whole recieved message
	while(recieved1[i] != '\0')
	{
		//count for number of characters 
		if(recieved1[i] != ' ' && recieved1[i] != '\n')
			number_of_characters++;
		//count for number of spaces
		if (recieved1[i] == ' ' )
			spaces++;	
		//count for number of lines	
		if(recieved1[i] == '\n')
			number_of_lines++;
		i++;
	}
	//numer of words will be the sum of spaces and lines
	number_of_words = spaces + number_of_lines;
	//if there's no end line then incrementing word count
	if(number_of_lines == 0)
		number_of_words+=1;
			
	//declaring and initalizing strings to concatenate
	char total_characters[MAXLINE] = "~~ Number of characters : ";
	char total_words[MAXLINE]      = "~~ Number of words      : ";
	char total_lines[MAXLINE]      = "~~ Number of lines      : ";
			
	/* char value of "number_of_characters"
	converting integer "number_of_characters" to char array(string)
	concatenating char value of "number_of_characters" with '\n' (to follow the format)
	concatenating again and again to store all string in one array */
	char charValue_1[countDigits(number_of_characters)];
	sprintf(charValue_1,"%d",number_of_characters);
	strcat(charValue_1,"\n");
	strcat(total_characters,charValue_1);
			
	/* char value of "number_of_words"
	converting integer "number_of_words" to char array(string)
	concatenating char value of "number_of_words" with '\n' (to follow the format)
	concatenating again and again to store all string in one array */
	char charValue_2[countDigits(number_of_words)];
	sprintf(charValue_2,"%d",number_of_words);	
	strcat(charValue_2,"\n");			
	strcat(total_words, charValue_2);
	strcat(total_characters,total_words);
			
	/* char value of "number_of_lines"
	   converting integer "number_of_lines" to char array(string)
	   concatenating char value of "number_of_lines" with '\n' (to follow the format)
	   concatenating again and again to store all string in one array */
	char charValue_3[countDigits(number_of_lines)];	
	sprintf(charValue_3,"%d",number_of_lines);			
	strcat(charValue_3,"\n");			
	strcat(total_lines,charValue_3);
	strcat(total_characters,total_lines);	
			
	printf("\nWriting results to 'theCount.txt' file... \n");
	sleep(1);
	FILE *file_pointer;
	//opening file "theCount.txt" to write to it"
	file_pointer  = fopen ("theCount.txt", "w");
		fputs(total_characters, file_pointer);
	fclose(file_pointer);
				
	//reading from file "theCount.txt" 
	file_pointer = fopen("theCount.txt", "r");
	//declaring arrays so that we can concatenate
	char all_in_one[MAXLINE] = "";
	char send2[MAXLINE] = "";
			
	printf(" _____________________________________\n");
	printf("|                                     |\n");
	printf("|--Contents of the File theCount.txt--|\n");
	printf("|_____________________________________|\n\n");
	//loop through each line of the file
	while(fgets(send2, sizeof(send2), file_pointer))
	{
		//storing all lines in one array "all_in_one" 
		strcat(all_in_one, send2);
		printf("%s",send2);
	}
	//closing file pointer
	fclose(file_pointer);
	printf("_______________________________________\n");
	//closing read descriptor to write on pipe 2
	close(read_2);
	printf("\nSending these contents....\n");
	sleep(1);
	write(write_2,all_in_one,sizeof(all_in_one));
	printf("✂️-Contents sent to producerConsumer program (%d)-*\n", getppid());
}

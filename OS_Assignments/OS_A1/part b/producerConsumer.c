/* Fiza Ahmad
   20I-0506
   OS-Lab (C)
   Assigment 1
   Part 2 */
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
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
int main()
{
	int file_descriptor_1[2];
	int file_descriptor_2[2];
	pipe(file_descriptor_1);
	pipe(file_descriptor_2);
	pid_t p = fork();
	if(p >= 0)
	{
		if( p == 0 )
		{
			sleep(2);
			//declaring cha
			char fd1_read_char[MAXLINE];
			char fd2_read_char[MAXLINE];
			char fd1_write_char[MAXLINE];
			char fd2_write_char[MAXLINE];
			
			int fd1_read  = file_descriptor_1[0];
			int fd1_write = file_descriptor_1[1];
			int fd2_write = file_descriptor_2[1];
			int fd2_read  = file_descriptor_2[0];
			
			sprintf(fd1_read_char,"%d",fd1_read);
			sprintf(fd2_read_char,"%d",fd2_read);
			sprintf(fd1_write_char,"%d",fd1_write);
			sprintf(fd2_write_char,"%d",fd2_write);
			char *list[] = {"d.out",fd1_read_char,fd2_write_char,fd1_write_char,fd2_read_char,NULL}; 
			
			execv("./consumerProducer",list);
			
			printf("fail\n"); //should not come
		}
		else
		{
			printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><>IN PRODUCER CONSUMER PROGRAM (%d)\n",getpid());
			printf(" _______________________________________\n");
			printf("|                                       |\n");
			printf("|--Contents of the File editSource.txt--|\n");
			printf("|_______________________________________|\n\n");
			FILE *file_pointer;
			//opening file "editSource.txt" to write to it"
			file_pointer  = fopen ("editSource.txt", "w");
				//writting to the file
				fputs("Source code\n", file_pointer);
				fputs("represents the part of\n", file_pointer);
				fputs("process that\n", file_pointer);
				fputs("contains the programming\n", file_pointer);
				fputs("languauge itself. You may\n", file_pointer);
				fputs("use a text editor to\n", file_pointer);
				fputs("write your source code file.\n", file_pointer);
        		fclose(file_pointer);
			//reading from the file "editSource.txt"
			file_pointer = fopen("editSource.txt", "r");
			char all_in_one[MAXLINE] = "";
			char send1[MAXLINE] = "";
			//loop through each line of the file
			while(fgets(send1, sizeof(send1), file_pointer))
			{
				//storing all lines in one array "all_in_one" 
				strcat(all_in_one, send1);
				printf("%s",send1);
			}
			printf("_________________________________________\n");
			//closing file pointer
			fclose(file_pointer);
			
			//closing read descriptor to write on pipe
			close(file_descriptor_1[0]);
			//writting the message red from file on pipe
			printf("\nSending these contents....\n");
			sleep(1);
			printf("✂️-Contents sent to consumerProducer program (%d)-*\n", p);
			write(file_descriptor_1[1],all_in_one,sizeof(all_in_one));
			wait(NULL);
			
			char recieved2[MAXLINE];
			read(file_descriptor_2[0],recieved2,sizeof(recieved2));
			printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><>IN PRODUCER COSUMER PROCESS (%d)\n",getpid());
			printf("\nRecieving....\n");
			sleep(1);
			printf("✂️-Contents recieved from consumerProducer program (%d)-*\n",p);
			printf("--------------------------------------------------------\n");
			printf(" >> Message from (%d):\n",p);
			printf("%s", recieved2);
			printf("--------------------------------------------------------\n");
		}
	}	
}


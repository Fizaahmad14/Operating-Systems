# Operating System Assignments

## OS_A1:

### part a:

#### T1:

A script that takes two parametric variables:
./script pattern_option number. 
Where, pattern_option = {left, right, full}, number = could be any positive integer

#### T2:

Write a script that displays a main menu and perform tasks based on the input value.Validinput values =. {1,2,3,4,exit} .
The different options 1,2,3,4 will display the output as follow:


1.Input  a  filename  from  user  and  display  permissions  of  that particular  file. Then invertthe permissions e.g. If permissions werer-xchange them to-w-. Then again displaythe updated permissions of that file.

2.Input afilenameand astringand search it in the file. Output the lines of file where  thatstringis  found.  But  if  thestringcontains  adot(.)it  means  any character can fillthe place. For example: string = c.t = {cat, cot, c t,}


3.Create  a  filedummy.txtand  add  the  content  of  all  the  files  in  the  current directory to dummy. But copy the content in such a way that if files in current directory = {f1, f2, f3, f4, ..., fn}. Then copy firstNlines of files at even location{f2, f4,.}and lastNlines offiles at odd location{f1,f3,. }. Input value ofNfrom user.

4.Input a filename from user and check modified date of that file. If modified date is greaterthan 24 hours from the current time change the modified date to current date.Along with displaying the output on terminal, maintain a log file that contains the informationof the script.

### part b:

You are to use any distribution of the Linux operating system to create two C programs. Program consumerProducer.cand program producerConsumer.c. These two programs communicate with eachother through ordinary pipes.The producerConsumer program will1)open a text file with the name editSource.txtand will write all sentences of the created file on one pipe to be read by the consumerProducer program.

The consumerProducer program will
1)read from the pipe, and it will
2)count the number of characters,
3)count the number of words, and
4)count the number of lines in the received sentences. It will then
5)create a file named theCount.txt,
6)write the produced output to theCount.txt,and will
7)write the contents of the file theCount.txton a second pipe to be read the producerConsumer process.The producerConsumer process will display the received file on standard output.

The contents of the editSource.txtfile is as follows:
Source coderepresents the part ofprocess thatcontains the programminglanguage itself. You mayuse a text editor towrite your source code file.The format of theCount.txtfile is:Number of characters:number of characters found in editSource.txtNumber of words:number of words found in editSource.txtNumber of lines:number of lines found in editSource.txt

## OS_A3:

### q1:

Write a program that takes a filename as input. The task is to count the numberof alphabets in the mentioned file. You have to create 26 threads each thread willbe  responsible  for  the  counting  of  a  particular  letter  in  the  file.  All  threads  willprinttheircharactercountandalsoreturnthecount,mainthreadwillreceivethecountofeachthreadandprintthesumwhichwillbeequivalenttonoofcharactersin file. Character that thread has to count should be passed as input parameter toeachthread.

### q2:


You have learned mergesort in datastructures which sorts an array in nlogn time,it is a divide and conquer technique. We can enhance the performance of mergesort using the multithreading. First of all, you have to check the processor cores of your system, let's suppose your system processor has 4 cores. Now you have to create  4  threads  and  divide  the  array  among  these  threads  and  sort  them  using mergesort.You have to take size of array and array elements from user. For this question you have to print number of cores and mac address of your system at the start  of  program. 

### q3:

Multiplication of matrix  does take time surely.Time complexity of matrix multiplication  is  O  (n^3)  using  normal  matrix  multiplication.  But,  is  there  anyway to improve the performance of matrix multiplication using normal method. Multi-threading can be done to improve it.In multi-threading,instead of utilizing a single core of your processor, we utilize all or more core to solve the problem.You have to create  different threads,  each thread evaluating one element of resultant matrix

# Operating Systems Labs 

## OS_L1:

Take 3 numbers from user, calculate larger number. Make two processes, calculate square of the larger number in child, pass it to the parent. In parent, check if the recieved number is even or not. If even, calculate the multiples < 50 of this number in it’s grand parent.

## OS_L2:

A program that take two inputs from the user, take their hcf and pass it to it’s parent1 process.The  parent1  will  then  check  if  the number is prime or not, if the number is prime it would increment itand pass it to it’s grandparent. The grand parent will then execute another file in which it would takeincremented number as argument and display it’s multiple less than 100.

## OS_L3:

### Task 1:

Pipe without fork()

### Task 2:

Pipe with fork() -> One way Communication

### Task 3:

Pipe with fork() -> Twoway Communication

## OS_L4:

Two way communication using named pipes

## OS_L5:

### Task 1:

Write a program to create two threads say thr1 and thr2. Thread 1 prints even number less than 20 and thread 2 will print odd number less than 20

### Task 2:

A program to create two threads. One thread’s sole purposeis to create a text file named “lab9.txt” while other thread takes some input from the user and write that input text in “lab9.txt

### Task 3:

A program to create four threads. The main process will first of all take two inputs from user, then show menu, user will select one option from it and implement that specific functionality

## OS_L6:

A program that create two threads, one thread takes random input in an array. Other thread will sort the array using insertion sort and finally return the highest value among that. Finally the main process will check whether it’s palindrome or not and display it.

## **OS_L7:**

A program that generates 4 threads: two withdrawal threads that continue to withdraw $10 from a bank account and two depositing threads that continue to deposit $11 to the same account. Assume there is no limit on the maximum balance of the account but the withdrawal threads should block if the account does not have sufficient fund (i.e. less than $10) to withdraw.

## OS_L8:

same as OS_L7 but using semaphores

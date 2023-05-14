#Fiza Ahmad
#20I-0506
#Assignment 1
#Question Number 2

# !/bin/bash
clear
touch logFile.txt
echo "Enter the choice you want from the options below" #menu for the user
echo "---1. Check file permissions"
echo "---2. Search for a word in a file"
echo "---3. Creating a file and storing information in it"
echo "---4. Check the modified date of the file"
echo "---|  Write 'exit' to exit from the program"
echo ""
read -p ">> Enter your choice : " choice #taking the users choice 

case $choice in 
#*************************------------ PART 1 ------------****************************
	1) #if the user picks the first choice 
	#clear
	#taking file input from the user
	read -p "Enter the file name: " filename 
	ls -l $filename
	[ -w $filename ] && W="Write   = Yes" || W="Write   = No"
	[ -x $filename ] && X="Execute = Yes" || X="Execute = No"
	[ -r $filename ] && R="Read    = Yes" || R="Read    = No"
	echo " _____________________"
	echo "| Current Permissions |"
	echo "|_____________________|"
	echo "$filename permissions"
	echo "$W"
	echo "$R"
	echo "$X"
	
	#appending to log file
	echo "$filename permissions" >> logFile.txt
	echo " _____________________" >> logFile.txt
	echo "| Current Permissions |" >> logFile.txt
	echo "|_____________________|" >> logFile.txt
	echo "$W" >> logFile.txt
	echo "$R" >> logFile.txt
	echo "$X">> logFile.txt
	
	if [ -w $filename ] # condition to check if the file is writable or not
	then
		chmod -w $filename #if condition true then removing the permission
	else 
		chmod +w $filename #if condition is false then adding the permission
	fi
	if [ -x $filename ] # condition to check if the file is executable or not
	then
		chmod -x $filename #if condition true then removing the permission
	else 
		chmod +x $filename #if condition is false then adding the permission
	fi
	if [ -r $filename ] # condition to check if the file is readable or not
	then
		chmod -r $filename #if condition true then removing the permission
	else 
		chmod +r $filename #if condition is false then adding the permission
	fi
		
	ls -l $filename #displaying the file permissions
	#displaying file permissions in a more comprehensive manner 
	[ -w $filename ] && W="Write   = Yes" || W="Write   = No" 
	[ -x $filename ] && X="Execute = Yes" || X="Execute = No"
	[ -r $filename ] && R="Read    = Yes" || R="Read    = No"
	echo " _____________________"
	echo "| Permissions changed |"
	echo "|_____________________|"
	echo "$filename Updated permissions"
	echo "$W"
	echo "$R"
	echo "$X"
	
	#appending to log file
	echo "$filename Updated permissions" >> logFile.txt
	echo " _____________________" >> logFile.txt
	echo "| Permissions changed |" >> logFile.txt
	echo "|_____________________|" >> logFile.txt
	echo "$W" >> logFile.txt
	echo "$R" >> logFile.txt
	echo "$X" >> logFile.txt;;
#*************************------------ PART 2 ------------****************************
	2) #if the user picks the second choice 
	#clear
	#taking file input from the user
	read -p ">> Enter the file name : " filename 
	#taking string input from the user
	read -p ">> Enter the string    : " str 
	#command used to pick a word and show the sentence that it is in 
	grep -n $str $filename;; 
		
#*************************------------ PART 3 ------------****************************
	3)
	#clear
	touch dummy.txt #creating the dummy file 
	#taking the input of N from the user
	read -p ">> Enter the number of lines of file(N): " N 
	#storing all the files in one dummy file 
	#traverse all files in directory
	i=1
	#loop until all files in the directories
	for file in *
	do
		#for even location
		if [ $((i % 2)) -eq 0 ]
		then
			head -n $N *.sh >> dummy.txt

		#for odd location
		else
			tail -n $N *.sh >> dummy.txt

		fi
		(( i=i+1 ))
	done;;
#*************************------------ PART 4 ------------****************************
	4)
	#clear
	#taking file input from the user
	read -p ">> Enter the file name: " filename 
	date -r $filename #displaying the modified date
	current=$(date +%s); #storing the current date
	#storing the last modified date 
	last_modified=$(stat -c "%Y" $filename); 

	#condition to check if the modified date is greater than 24 hrs
	if [ $((current - last_modified)) -gt 86400 ] 
	then
		#changing the modified date to recent date
		touch -m $filename 
		#displaying the modified date 
		date -r $filename 
	else 
		echo "The file last modified date is less than 24hrs"
		date -r $filename #displaying the modified date 
	fi;;
		
#*************************------------ PART 5 ------------****************************
	exit)
	exit;;
	
esac


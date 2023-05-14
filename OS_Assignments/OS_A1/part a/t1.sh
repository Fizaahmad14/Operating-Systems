#Fiza Ahmad (20I-0506)
#echo "task 1"
# -eq is used to compare integers
# '=' is used to compare strings/characters 
#checking if second argument is integer
if echo $2 | egrep -q '^[0-9]+$'
then
	if [ $1 = "left" ]
	then
		count=$2
		#upper portion 
		for (( i=0; i<count; i++ ))
		do 
			for (( j=0; j<=i ; j++ ))
			do
				printf "*"
			done
		printf "\n"
		done
		#inverted portion
		for (( i=count-1; i>0; i-- ))
		do 
			for (( j=i; j>0 ; j-- ))
			do
				printf "*"
			done
		printf "\n"
		done
	#fi
	elif [ $1 = "right" ]
	then
		N=$2
		space=N-1;
	      	steric=1;
	    
	    	#loop for rows
		for ((i=1; i<N*2; i++))
		do
	  		#Print spaces comes before steric
			for ((j=1; j<=space; j++))
			do
				printf " "
			done
		
			#Print sterics after spaces
			for ((j=1; j<=steric; j++))
			do
		    		printf "*"
		    	done             
	       		#end line
			printf "\n"
		
			if [ $i -lt $N ] 
	      		then
			    (( steric=steric+1 ))
			    (( space=space-1 ))
			else
			    (( steric=steric-1 ))
			    (( space=space+1 ))
			fi    
		done   		
	#fi
	elif [ $1 = "full" ]
	then
		n=$2	
	  	for ((k=1; k<=n; k++))
	  	do
	    		for ((c=1; c<=n-k; c++))
	    		do
	      			printf " "
	    		done

	    		for ((c=1; c<=2*k-1; c++))
	    		do
	      			printf "*"
	    		done

	    		printf "\n"
	  	done

	  	for ((k=1; k<=n-1; k++))
	  	do
	    		for ((c=1; c<=k; c++))
	    		do
	      			printf " "
	    		done

	    		for ((c=1; c<=2*(n-k)-1; c++))
	    		do
	      			printf "*"
	    		done
	    		printf "\n"
	  	done
	#fi
	else
		printf "\n"
		echo "Error, Invalid Arguments :("
		printf "\n"
	fi
else
      echo "Error, Invalid Arguments :("
fi





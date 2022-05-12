#!/bin/bash
#
#
#
#usage:Accepts state and date arguments, and returns total vaccinated people in that state on that date, or so far 
#
#input: Stat abbreviation, optional date
#
#output: number of vaccinated people
#
#Callie Moody
#07.01.2021
#CS50, Dartmouth College


#check argument amounts
if [[ $# -gt 2 || $# -lt 1 ]] 
then
	echo 1>&2 Incorrect number of arguments
	exit 1
fi

# check if vaccine.csv exists
if [[ ! -e vaccine.csv ]]
then
	echo 1>&2 "Cannot find vaccine.csv"
	exit 2
fi

# check if state code is in appropriate format
if [[ $1 =~ ^[A-Z]{2}$ ]]
then

#save the relevant county totals as an array in the array variable
         targetarray=$(grep $1 vaccine.csv | cut -d , -f 1,2,4,5,7 | sort -r -t  "," -k2.1,2.6 -k1.7,1.11 -k1.1,1.3 -k1.4,1.5 | sort -u -t "," -k2.1,2.6 | cut -d , -f 5 )
    		if [ -z "$targetarray" ] 
		then
                   echo 1>&2 No entries with this state code
                   exit 3
                fi

	if [ $# -eq 2 ]
        then

#check if argument is in proper date format and exists in the document
		if [[ $2 =~ ^[0-9]{2}/[0-9]{2}/[0-9]{4}$ ]]
		then
			targetarray=$(grep $1 vaccine.csv | grep $2 | cut -d , -f 7)
			if [ -z "$targetarray" ]
	                then
                        echo 1>&2 No entries with this date
                        exit 4
                	fi

		else
			echo 1>&2 Invalid date format
			exit 5
		fi	
		

		
	fi

else
	echo 1>&2 Not a state abbreviation: try a 2 letter code
	exit 6
fi

#adds the individual county totals to the total
for a in $targetarray
do
	(( total += a ))
done

echo $1: $total
exit 0

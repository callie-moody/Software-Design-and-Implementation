#/bin/!/bash
# usage- call with at least two arguments: first argument is a directory name to either fill or compare to
# following arguments are executable files to test
#


#Check number of arguments
if [ $# -lt 2 ]; then
    echo 1>&2 "Not enough arguments"
    exit 1
fi
#check if the directory name passed in exists and is not a directory
if [[ -e $1 && ! -d $1 ]]; then
    echo 1>&2 "Not a directory"
    exit 2
fi

datedir=$(date +%m%d%y"."%H%M%S)
mkdir $datedir

#test each file passed in
for givfile in ${@:2}
do
   if [ -f "$givfile" ] && [ -x "$givfile" ]; then
       cat $givfile > $datedir/$givfile.test
       bash $givfile < /dev/null &> $datedir/$givfile.output 
       echo $?> $datedir/$givfile.status
       echo finished $givfile
    else
        echo 1>&2 "Not an executable file"
        exit 3
    fi
 
done

#appropriately name directory
if [ -d $1 ]; then
echo "comparing with most recent test"
comparison=$(ls -t --group-directories-first | head --lines=2 | tail --lines=1)
diff $comparison $datedir
else
mv $datedir $1
fi

exit 0


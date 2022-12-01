#! /bin/bash

echo ' exercise1-12.2 '
echo -n 'please input a data : '
read DIR
if [ -d $DIR ]
then
	sum_file=0
	sum_dir=0
	for FILE in `ls`
	do
		if [ -f $FILE ]
		then
			sum_file=`expr $sum_file + 1`
		else
			sum_dir=`expr $sum_dir + 1`
		fi
	done
	echo $sum_file
	echo $sum_dir
else
	echo 'not a directory'
	exit 1
fi

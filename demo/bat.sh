#! /bin/bash

echo ' exercise1-12.1'

i=1
if [ $# -eq 2 ]
then
	while [ $i -le $2 ]
	do
		touch $1_$i.txt
		i=`expr $i + 1`
	done
elif [ $# -eq 1 ]
then
	while [ $i -le 5 ]
	do
		touch $1_$i.txt
		i=`expr $i + 1`
	done
fi

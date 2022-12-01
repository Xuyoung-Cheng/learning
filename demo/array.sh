#! /bin/bash

array=(1 2 3 4 5)
i=0

for var in ${array[@]}
do
	echo "array[$i] = $var"
	i=`expr $i + 1`
done

declare -A ARGLIST

ARGLIST[key1]=1
ARGLIST[key2]=2
ARGLIST[key3]="SHELL"

for item in ${!ARGLIST[@]}
do
	echo "$item --> ${ARGLIST[$item]}"
done

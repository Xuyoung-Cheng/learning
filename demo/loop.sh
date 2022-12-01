#! /bin/bash

SUM=0
i=1

while [ $i -le 100 ]
do
	SUM=`expr $SUM + $i`
	i=`expr $i + 1`
done

echo "$SUM"

SUM=0
for j in $@ 
do
	SUM=`expr $SUM + $j`
done

echo "$SUM"

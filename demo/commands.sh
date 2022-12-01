#! /bin/bash

echo -n 'please input name and age : '
read NAME AGE
echo $NAME : $AGE

echo -n "input two number : "
read ARG1 ARG2
RES=`expr $ARG1 - $ARG2`
echo $RES
RES=`expr $ARG1 + $ARG2`
echo $RES
RES=`expr $ARG1 \* $ARG2`
echo $RES
RES=`expr $ARG1 / $ARG2`
echo $RES

test 1 -eq 2 
echo $?
[ 1 -eq 2 ]
echo $?

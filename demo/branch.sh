#! /bin/bash

echo -n 'please input dirname : '
read DIR

if [ -d $DIR ]
then
	ls $DIR
fi

echo -n 'please input data : '
read STR
if [ -d "$STR" ]
then
	ls $STR
	echo 'This is a dir'
else
	if [ -f "$STR" ]
	then
		ls -l $STR
		echo 'This is a file'
	else
		echo 'Other type!'
	fi
fi

echo -n "please input two data : "
read VAR1 VAR2

SUM=`expr $VAR1 + $VAR2`

if [ $SUM -ge 0 -a $SUM -le 100 ]
then
	echo "$SUM is [0, 100]" 
elif [ $SUM -gt 100 -a $SUM -le 500 ]
then
	echo "$SUM is (100, 500]"
elif [ $SUM -eq 600 ]
then
	echo "$SUM is 600"
fi

echo -n "please input a string : "
read STR
VAR='hello'
case $STR in
	$VAR)
		echo $VAR
		;;
	"ABC")
		echo "ABC"
		;;
	"123")
		echo "123"
		;;
	"AC"|"BC"|"1")
		echo "Ac or BC or 1"
		;;
	[3-4])
		echo "$STR is [3-4]"
		;;
	[1259abYW])
		echo "$STR in [1259abYW]"
		;;
	*)
		echo "Other"
esac


exit

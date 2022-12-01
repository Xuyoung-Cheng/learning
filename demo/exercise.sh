#! /bin/bash

echo '--------------- exercise -------------'

echo 'exercise1-6.1'

echo -n 'please input year month day : '
read YEAR MONTH DAY
echo "$YEAR"-"$MONTH"-"$DAY"

echo
echo 'exercise1-6.2'

echo -n 'please input two number : '
read ARG1 ARG2
echo "$ARG1 + $ARG2 =" `expr $ARG1 + $ARG2`
echo "$ARG1 - $ARG2 =" `expr $ARG1 - $ARG2`
echo "$ARG1 * $ARG2 =" `expr $ARG1 \* $ARG2`
echo "$ARG1 / $ARG2 =" `expr $ARG1 / $ARG2`

echo
echo 'exercise1-6.3'
echo -n 'please input a number : '
read ARG
test $ARG -ge 0 -a $ARG -lt 60
echo "$?"

echo
echo 'exercise1-8.1'
echo -n 'please input a filename : '
read FILE
if [ -f $HOME/$FILE ]
then
	ls -l $HOME/$FILE
	exit
else
	echo 'Good Study'
fi

echo
echo 'exercise1-8.2'
echo -n 'please input a score : '
read SCORE
if [ $SCORE -ge 60 -a $SCORE -lt 70 ]
then
	echo 'D'
elif [ $SCORE -ge 70 -a $SCORE -lt 80 ]
then
	echo 'C'
elif [ $SCORE -ge 80 -a $SCORE -lt 90 ]
then
	echo 'B'
elif [ $SCORE -ge 90 -a $SCORE -le 100 ]
then
	echo 'A'
fi

echo
echo 'exercise1-10'
read DIR
if [ -d "$HOME/$DIR" ]
then
	echo -n "do you want to delete $DIR? Y,y,yes,YES "
	read STR
	case $STR in
		"Y" | "y" | "yes" | "YES")
			rm -rf $HOME/$DIR
			;;
		*)
			exit		
	esac
else
	mkdir $HOME/$DIR
fi

echo
echo 'exercise1-14.1'
array=(7 6 5 3 2)
i=0
for var in ${array[@]}
do
	echo "$i: $var"
	i=`expr $i + 1`
done

echo
echo 'exercise1-14.2'
array=(I am westos teacher welcome to westos training class)
for var in ${array[@]}
do
	len=${#var}
	if [ $len -lt 6 ]
	then
		echo $var
	fi
done


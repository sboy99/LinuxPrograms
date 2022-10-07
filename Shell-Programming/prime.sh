#! /bin/bash

if [ $# -eq 0 ]
then 
echo "Atleast one number is needed"
exit 1 
fi

for i in $*
do
breaked=0
for j in $(seq 2 $((i - 1)))
do
if [ $((i%j)) -eq  0 ]
then
breaked=1
break
fi
done
if [ $breaked -eq 1 ]
then
	echo "$i is not a prime number"
else	
	echo "$i is a prime number"
fi
done

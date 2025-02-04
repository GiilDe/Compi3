#!/usr/bin/env bash
flag=1
for file in `ls tests | grep -w "in" | cut -d"." -f1`; do
	./hw3 < tests/${file}.in > tests/${file}
    temp_str=`diff tests/$file tests/${file}.out`
    if [ ${#temp_str} -ne 0 ]; then
        str=$str"test $file fail:"$'\n'
        str=$str$temp_str$'\n'$'\n'
        flag=0
    fi
    # rm tests/${file}
done
if [ $flag -ne 0 ]
then
str=$str$'\n'"\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*"$'\n'
str=$str"\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\* PASS ALL TESTS \*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*"$'\n'
str=$str"\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*\*"$'\n'
fi
echo "$str"


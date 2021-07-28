#!/usr/bin/env bash

src=$1
out=$(echo $(basename $src) | awk -F'.' '{print $1}')

echo out=$out.out

if [[ ! -f $(dirname $src)/${out}.out ]]
then
    g++ -o $(dirname $src)/${out}.out $src
fi

if [[ -f $(dirname $src)/${out}.out ]] && [[ -n $2 ]]
then
    g++ -o $(dirname $src)/${out}.out $src
    ./$(dirname $src)/${out}.out
else
    ./$(dirname $src)/${out}.out
fi
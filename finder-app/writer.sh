#!/bin/sh

if [ -n "$1" ] && [ -n "$2" ]
then
  writefile=$1
  writestr=$2
else
  echo "Two parameters are mandatory!"
  exit 1
fi

mkdir -p $(dirname $writefile) && touch $writefile

echo $writestr > $writefile


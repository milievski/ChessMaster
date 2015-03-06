#!/bin/sh
FROM=https://svnhost/checkmate/
TO="$HOME/test_results"
FNAME=$(date +%y%m%d)
ulimit -t 10
if [ $# -eq 2 ]
then
TO="$1"
FROM="$2"
elif [ $# -eq 1 ]
then
TO="$1"
fi
svn checkout "$FROM" "$TO"
if [ $? -eq 0 ]
then
cd "$TO/tests"
make clean-all
make -k > "$FNAME.comp.$$" 2>&1
if [ $? -eq 0 ]
then
./testMain > "$FNAME.res.$$"
fi
cd -
fi
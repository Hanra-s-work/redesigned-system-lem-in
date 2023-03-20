#!/bin/bash
# (c) Written by Henry Letellier
CONTENT="$(cat coding-style-reports.log)"
if [ ${#CONTENT} -eq 0 ]; then
    echo "::success file='',line=1,endLine=0,title=No coding style error detected"
    exit 0
fi
ILLEGAL_FILES_FOUND=0
while IFS= read -r LINE; do
    echo "::error file=$LINE,line=1,endLine=0,title=Unwanted file detected::$LINE"
    ILLEGAL_FILES_FOUND=1
done <<<"$CONTENT"
if [ $ILLEGAL_FILES_FOUND -eq 1 ]; then
    exit 1
else
    echo "::success file='',line=1,endLine=0,title=No Unwanted file detected"
fi

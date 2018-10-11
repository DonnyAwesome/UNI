#!/bin/bash
#v0.2
_timeStamp=1
_pathToEmails='Beispielmails/'
_pathToStore='ArchiveEmails/'


function PrintMessage() {
#    $1, $2, $3, ... is Message
  echo '----------------------------------------------------------'
  echo ''  
  echo ''
  echo ''
  echo ''

  for Messages in "$@"; do
    echo "$Messages"
  done
    
  echo ''
  echo ''
  echo ''
  echo ''
  echo 'Press any key to exit... '
  echo '----------------------------------------------------------'
  read -n1 -r -p "" key
  echo ''
}


if [ "$#" -eq 0 ] || [ "$1" == '-h' ]
then
  PrintMessage "Usage: ./Storemails.sh [Option] [Pfad/Maildateien/] [Maildateien/]" "" "Options:" "    -h  Help" "    -t  Timestamp" "    -d  Other Directory"
  exit 1

elif [ "$1" == '-t' ]
then 
  _timestamp=1
  _pathToEmails=$2

elif [ "$1" == '-d' ]
then 
  _pathToStore=$2
  _pathToEmails=$3

  # create rep if not exist
  if [ ! -d "$_pathToEmails" ]; then
    mkdir "$_pathToEmails"
  fi  

elif [ "$1" == '-z' ]
then
  PrintMessage jkjl kjkl jkl jlkj kljkl jl kjlj kl jkl jklj kljj l  
  exit 1

else
  # gebe alle Parameter in jeweils eine neue Zeile ab 
  for a in "$@"; do
    echo "$a"
  done
  exit 1
fi

  # create rep if not exist
if [ ! -d "$_pathToEmails" ]; then
  PrintMessage 'ERROR Path to emails is invalid!'
  exit -1
fi 


_yea=''
_mnt=''
_day=''
_hrs=''
_min=''
_sec=''
DSTRING= ``

# Gibt den Datum aus
#DSTRING=`grep -rI Date: eml/ | cut -d ":" -f 3`
DSTRING=`grep -rI Date: $_pathToEmails/ | cut -d ":" -f 3`

# Mon, 19 Mar 2018 15
_yea=$(echo $DSTRING | cut -d " " -f 4)
_mnt=$(echo $DSTRING | cut -d " " -f 3)
_day=$(echo $DSTRING | cut -d " " -f 2)
_hrs=$(echo $DSTRING | cut -d " " -f 5)
_min=`grep -rI Date: $_pathToEmails/ | cut -d ":" -f 4`
_sec=`grep -rI Date: $_pathToEmails/ | cut -d ":" -f 5`

echo "----------------------------"
echo "      Year: $_yea"
echo "      Mnth: $_mnt"
echo "      Day : $_day"
echo "      Hour: $_hrs"
echo "      Min : $_min"
echo "      Sec : $_sec"
echo "----------------------------"

case "$_mnt" in
"Jan")
    _mnt=1
    ;;
"Feb")
    _mnt=2
    ;;
"Mar")
    _mnt=3
    ;;
"Apr")
    _mnt=4
    ;;
"Mai")
    _mnt=5
    ;;
"Jun")
    _mnt=6
    ;;
"Jul")
    _mnt=7
    ;;
"Aug")
    _mnt=8
    ;;
"Sep")
    _mnt=9
    ;;
"Oct")
    _mnt=10
    ;;
"Nov")
    _mnt=11
    ;;
"Dec")
    _mnt=12
    ;;
*)
    echo "Fuck! Month not found!!!"
    _mnt=-1
    ;;
esac

echo "Month in num.: $_mnt"

read -n1 -r -p "Press any key to continue... " key

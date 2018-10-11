#!/bin/bash
#v0.1
_timeStamp=1
_pathEmails=''
_pathStore=''

if [ "$#" -eq 0 ] || [ "$1" == '-h' ]
then
  echo '----------------------------------------------------------'
  echo ''  
  echo ''
  echo ''
  echo ''
  echo 'Usage: ./Storemails.sh [Option] [Maildateien] [Pfad]'
  echo ''
  echo 'Options:'
  echo '-h  Help'
  echo '-t  Timestamp'
  echo '-d  Other Directory'
  echo ''
  echo ''
  echo ''
  echo ''
  echo '----------------------------------------------------------'
  exit 1
else
  # gebe alle Parameter in jeweils eine andere Zeile ab 
  for a in "$@"; do
    echo "$a"
  done
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
DSTRING=`grep -rI Date: Beispielmails/ | cut -d ":" -f 3`

# Mon, 19 Mar 2018 15
_yea=$(echo $DSTRING | cut -d " " -f 4)
_mnt=$(echo $DSTRING | cut -d " " -f 3)
_day=$(echo $DSTRING | cut -d " " -f 2)
_hrs=$(echo $DSTRING | cut -d " " -f 5)
_min=`grep -rI Date: Beispielmails/ | cut -d ":" -f 4`
_sec=`grep -rI Date: Beispielmails/ | cut -d ":" -f 5`

echo "----------------------------"
echo "Year: $_yea"
echo "Mnth: $_mnt"
echo "Day : $_day"
echo "Hour: $_hrs"
echo "Min : $_min"
echo "Sec : $_sec"
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
"Okt")
    _mnt=10
    ;;
"Nov")
    _mnt=11
    ;;
"Dez")
    _mnt=12
    ;;
*)
    echo "Fuck! Month not found!!!"
    ;;
esac

echo $_mnt

read -n1 -r -p "Press any key to continue... " key

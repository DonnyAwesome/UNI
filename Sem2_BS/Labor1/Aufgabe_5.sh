#!/bin/bash

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

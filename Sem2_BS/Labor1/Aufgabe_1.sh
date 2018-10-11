#!/bin/bash

#Wie überprüfen sie, ob ein Shellskript mit Parametern aufgerufen wurde, oder ohne?

# "$#" gibt die Anzahl an Param. ab
#echo "$#"

# "$@" gibt alle Param in ein String ab
#echo "$@"

if [[ "$#" -eq 0 ]]; then
  echo 'No Arguments!'
  exit 1
else
  # gebe alle Parameter in jeweils eine andere Zeile ab 
  for a in "$@"; do
    echo "$a"
  done
fi

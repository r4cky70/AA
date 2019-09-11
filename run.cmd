@echo off

echo Compilling %1.cpp...
IF [%2] == [] (
  g++ %1.cpp -std=c++14 -o sla
) ELSE (   
  g++ %1.cpp -std=c++14 -DLOCAL -o sla )
echo Compilled.

IF [%2] == [1] ( 
  sla >out.txt
) ELSE (
  sla
)
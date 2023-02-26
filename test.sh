#!/bin/bash
amount=100

for i in `seq 1 $amount`
do
    curl -X POST http://192.168.1.79:8537/increment
done

curl -X GET http://localhost:8537/imprimir
#!/usr/bin/bash

for i in 10 20 50 100 324 402 500 708 818; do

    for S in 800 1200 1600; do

        for p in 1 2 3 4 5; do

            (/usr/bin/time  -ao resultados_experimento.txt ./main test-cases/SJC$i.txt test-cases/demand-SJC$i.dat $p $S) >> "resultados_experimento.txt"
            echo "" >> "resultados_experimento.txt"
            echo "" >> "resultados_experimento.txt"

        done

    done
    
done

echo "Ejecución completada. Rsultados en resultados_experimento.txt"
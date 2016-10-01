reset
set ylabel 'time(sec)'
set xlabel 'N'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'
set datafile separator ","


plot [:][0:1] "result_clock_gettime.csv" using 1:2 title 'iteration', \
'' using 1:3  title 'binary_search', \
'' using 1:4  title 'byte_shift', \
'' using 1:5  title 'recursive'

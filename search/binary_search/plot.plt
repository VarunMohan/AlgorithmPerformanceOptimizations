list=system('ls -1 *.dat')
set ylabel "milliseconds"
set xlabel "array size"
plot for [file in list] file using 1:2 title file with lines

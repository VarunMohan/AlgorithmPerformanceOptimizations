list=system('ls -1 *.dat')
plot for [file in list] file using 1:2 title file with lines

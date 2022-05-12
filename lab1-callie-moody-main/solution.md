#Part A
grep ^05 vaccine.csv | grep NH
#Part B
grep -v Date vaccine.csv | cut -d , -f 4,5,6
#Part C
grep ^05/1[5-7] vaccine.csv
#Part D
grep CA vaccine.csv | cut -d , -f 1,2,4,6 | sort -r -t  "," -k2.1,2.6 -k1.7,1.11 -k1.1,1.3 -k1.4,1.5 | sort -u -t "," -k2.1,2.6 | grep ,0$ | cut -d , -f 3
#Part E 
cut -d , -f 1,2,5,6 vaccine.csv | sort -r -t  "," -k2.1,2.6 -k1.7,1.11 -k1.1,1.3 -k1.4,1.5 | sort -u -t "," -k2.1,2.6 | grep ,0$ | cut -d , -f 3 | uniq -c | sort -r -n
#Part F
cut -d , -f 1,2,4,5,6 vaccine.csv | sort -r -t  "," -k2.1,2.6 -k1.7,1.11 -k1.1,1.3 -k1.4,1.5 | sort -u -t "," -k2.1,2.6 | sort -n -r -t "," -k5 | head | cut -d , -f 3,4,5
#Part G
cut -d , -f 1,2,4,5,6 vaccine.csv | sort -r -t  "," -k2.1,2.6 -k1.7,1.11 -k1.1,1.3 -k1.4,1.5 | sort -u -t "," -k2.1,2.6 | sort -n -r -t "," -k5 | head | cut -d , -f 3,4,5 | sed s/"^"/"|"/g | sed s/","/"|"/g | sed s/"$"/"|"/g

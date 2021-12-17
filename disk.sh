echo "Total size of your disk is "
df -h --total | awk 'END {print $2}' >total.txt
cat total.txt

echo "Remaining size of your disk is "
df -h --total | awk 'END {print $4}' >remaining.txt
cat remaining.txt

df -h --total | awk 'END { if($5 > 30) print "alert!!!!!" $0;}'

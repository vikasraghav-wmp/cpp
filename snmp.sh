cd /etc/config
uci show discovered | grep "ip" | cut -d"'" -f2 |sed '1d' > discip
l=`grep -c "." discip`
echo Number of ip in file is $l
echo > data.txt 
for i in $(cat discip); 
do
a=`date "+%s"`
for j in $(seq 10);
do
    ping -c 1 $i  >> data.txt 
    snmpget -v2c -c public $i .1.3.6.1.2.1.1.2.0 2>/dev/null >> data.txt 
done
b=`date "+%s"`
c=$(( $b - $a ))
echo -e "response time for device $i in sec is " $c "second \n" >> data.txt
done
echo "process complete" >> data.txt
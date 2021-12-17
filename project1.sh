echo "Enter how many folders you want to create"
read n
a=1
while (( a <= n ))
do
mkdir $a && touch $a/$a.txt && echo "Hello $a">>$a/$a.txt
a=`expr $a + 1`
done
echo "hello"
echo "hello"

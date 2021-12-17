a()     #defining function a
{
    while :              #infite loop so after completion it again ask value from user
    do
    echo "Do you Want to Continue or not yes/no"
    read y
    case $y in
    yes)
    ping -c 10 google.com > ~/Documents/cpp/ping.txt    #ping google and storing its value in ping.txt
    echo "A status file of ping of google.com is stored in your local area "
    ;;
    no)
    break
    ;;
    esac
    done
}

b()               #defining function b
{
    top -b -n 1 > top.txt | grep "chrome"    #set limit in top and storing its value in a file
    top -b -n 1 | grep "chrome"
    echo "Status of Chrome is stored in a file"
}
c()                 #defining function c
{
    sed 's/Date/DateTime/' google        #replacing Date with DateTime
}
d()          #defining function d
{
    for i in {1..10}
    do
    curl -l https://www.google.com/ > google
    done
    c                  #calling function c inside d
}
while :                  #infite loop so after completion it again ask value from user
do
echo ""
echo "Select any value 1,2,3,4 or type exit to exit"
read x
case $x in
1)
a          #calling function xyz
;;
2)
b          #calling function abc
;;
3)
d           #calling function d
;;
4)
ifconfig                      #getting ip address
nmap 192.168.41.50 > nmap.txt                #storing nmap of system ip
cat nmap.txt
;;
exit)
echo "Thanks for using"
break
;;
*)
echo "you have choosen the wrong value"
;;
esac
done
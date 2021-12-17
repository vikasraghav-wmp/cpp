ping_function() { #defining function : asking user to continue, if yes then ping google
    while :; do   #infite loop so after completion it again ask value from user
        echo "Do you Want to Continue or not yes/no"
        read y
        case $y in
        yes)
            ping -c 10 google.com >~/Documents/cpp/ping.txt #ping google and storing its value in ping.txt
            cat ping.txt
            echo "A status file of ping of google.com is stored in your local area "
            ;;
        no)
            break
            ;;
        esac
    done
}

top_function() {                         ##defining function b using top
    top -b -n 1 | grep "chrome" >top.txt #set limit in top and storing its value in a file
    cat top.txt
    echo "Status of Chrome is stored in a file"
}

sed_function() {                                    #defining function : using sed to replace Date with DateTime
    sed 's/Date/DateTime/' google | grep "DateTime" #replacing Date with DateTime
}

curl_function() { #defining function : using curl 10 times in loop to get the source code of google and saving it in system
    for i in {1..10}; do
        curl -l https://www.google.com/ >google
    done
    sed_function #calling this function inside curl_operation
}

while :; do #infite loop so after completion it again ask value from user
    echo "Select any value 1,2,3,4 or type exit to exit"
    echo "Press 1 to ping google and store output in your system"
    echo "Press 2 to summary information of list of processes of chrome "
    echo "Press 3 to curl google 10 times and storing the result in system"
    echo "Press 4 to see ip of system and Real time information of your network and Number of ports open in a network"
    read x
    case $x in
    1)
        ping_function #calling function
        ;;

    2)
        top_function #calling function
        ;;

    3)
        curl_function #calling function d
        ;;

    4)
        ifconfig #getting ip
        hostname -I >ip
        nmap -iL ip
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

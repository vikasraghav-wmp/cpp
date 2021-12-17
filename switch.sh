echo "Please talk to me ...
"
while :
do
  read x
  case $x in
	hello)
		echo "Hello Sir "
		;;
    hi)
        echo "Hiii "
        ;;
    good.morning)
        echo "good morning sir "
        ;;
    good.night)
        echo "good night sir "
        ;;
    good.afternoon)
        echo "good afternoon sir "
        ;;
    how.are.you)
        echo "i am good. What about you? "
        ;;
    i.am.good)
        echo "That's awesome sir "
        ;;
	bye)
		echo "See you again! "
		break
		;;
	*)
		echo "Sorry, I don't understand "
		;;
  esac
done
echo 
echo "That's all folks! "
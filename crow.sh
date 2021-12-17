echo "Select a fruit to see its nutritional value"
echo "or Type exit to exit"
while :
do
  read x
  case $x in
	apple)
		cat fruits/apple.txt
        echo "Thanks!! Now again select a fruit to see its nutritional value or Exit by typing exit"
		;;
    orange)
        cat fruits/orange.txt
        echo "Thanks!! Now again select a fruit to see its nutritional value or Exit by typing exit"
        ;;
    banana)
        cat fruits/banana.txt
        echo "Thanks!! Now again select a fruit to see its nutritional value or Exit by typing exit"
        ;;
    mango)
        cat fruits/mango.txt
        echo "Thanks!! Now again select a fruit to see its nutritional value or Exit by typing exit"
        ;;
    kiwi)
        cat fruits/kiwi.txt
        echo "Thanks!! Now again select a fruit to see its nutritional value or Exit by typing exit"
        ;;
    pineapple)
        cat fruits/pineapple.txt
        echo "Thanks!! Now again select a fruit to see its nutritional value or Exit by typing exit"
        ;;
    watermelon)
        cat fruits/watermelon.txt
        echo "Thanks!! Now again select a fruit to see its nutritional value or Exit by typing exit"
        ;;
    muskmelon)
        cat fruits/muskmelon.txt
        echo "Thanks!! Now again select a fruit to see its nutritional value or Exit by typing exit"
        ;;
    strawberry)
        cat fruits/strawberry.txt
        echo "Thanks!! Now again select a fruit to see its nutritional value or Exit by typing exit"
        ;;
    grapes)
        cat fruits/grapes.txt
        echo "Thanks!! Now again select a fruit to see its nutritional value or Exit by typing exit"
        ;;
    avocado)
        cat fruits/avocado.txt
        echo "Thanks!! Now again select a fruit to see its nutritional value or Exit by typing exit"
        ;;
    pomegranate)
        cat fruits/pomegranate.txt
        echo "Thanks!! Now again select a fruit to see its nutritional value or Exit by typing exit"
        ;;
    guava)
        cat fruits/guava.txt
        echo "Thanks!! Now again select a fruit to see its nutritional value or Exit by typing exit"
        ;;
    exit)
    echo "Thank you very much"
		echo "See you again! "
		break
		;;
	  *)
		echo "OOPS! Wrong choice Please Select a fruit or Exit by typing exit"
		;;
  esac
done
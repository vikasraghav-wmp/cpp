echo "This is a simple Calculator"
echo "Press 1 for addition"
echo "Press 2 for subtraction"
echo "Press 3 for multiplication"
echo "Press 4 for division"
echo "Type exit to exit"
while :
do
read x
case $x in
1)
read -p " Enter a number : " a
read -p " Enter another number : " b
add=$(( $a + $b ))
echo "sum of two numbers : $add"
echo " "
echo "Press 1 for addition"
echo "Press 2 for subtraction"
echo "Press 3 for multiplication"
echo "Type exit to exit"
echo "Press 4 for division"
;;
2)
read -p " Enter a number : " a
read -p " Enter another number : " b
subtraction=$(( $a - $b ))
echo "subtration of two numbers : $subtraction"
echo " "
echo "Press 1 for addition"
echo "Press 2 for subtraction"
echo "Press 3 for multiplication"
echo "Press 4 for division"
echo "Type exit to exit"
;;
3)
read -p " Enter a number : " a
read -p " Enter another number : " b
multiplication=$(( $a * $b ))
echo "multiplication of two numbers : $multiplication"
echo " "
echo "Press 1 for addition"
echo "Press 2 for subtraction"
echo "Press 3 for multiplication"
echo "Press 4 for division"
echo "Type exit to exit"
;;
4)
read -p " Enter a number : " a
read -p " Enter another number : " b
division=$(( $a / $b ))
echo "Division of two numbers : $division"
echo " "
echo "Press 1 for addition"
echo "Press 2 for subtraction"
echo "Press 3 for multiplication"
echo "Press 4 for division"
echo "Type exit to exit"
;;
exit)
echo "Thanks for using me"
echo "see you again"
break
;;
*)
echo "Please select the valid character"
echo " "
echo "Press 1 for addition"
echo "Press 2 for subtraction"
echo "Press 3 for multiplication"
echo "Press 4 for division"
echo "Type exit to exit"
;;
esac
done

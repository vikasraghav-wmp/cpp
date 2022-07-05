echo enter environment name
read env_name
for i in $(cat vikas.txt); 
do
    a=`echo $i | sed 's/=.*//' | tr '[:upper:]' '[:lower:]'`
    a=${a//[_]/-}
    b=`echo $i | sed 's/.*[=] *//'`
    echo $a
    echo $b
    echo $env_name
    aws ssm put-parameter --name "/env/prod/$a" --type "String" --value "$b"

done
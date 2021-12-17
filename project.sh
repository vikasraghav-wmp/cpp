echo "How many Folder you want to create"
read n
for i in {1..$n}
do
mkdir $i &&  touch $i/$i && echo Hello$i>>$i/$i
done


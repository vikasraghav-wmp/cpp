read -p "Please Enter Path:" path
ls -s -h ~/$path > size.txt
echo "list of files or folders in that particular path with size of each file and folders :"
cat size.txt
echo "list of files or folders in that particular path with size of each file and folders is stored in your system:"

echo "Enter the Environment: "
echo -e " 1. dev \n 2. staging \n 3. prod "  
read environment
echo "Enter apk version"
read ver
aws s3 cp s3://trakwa-app/$environment/$ver/app-release.apk ./
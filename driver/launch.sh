
if [ "$(pidof regserver)" ]
then
    echo "Registry server already running"
else
    ../../Registry/regserver -a 127.0.0.1 -p 5006&
fi


sudo ./driver

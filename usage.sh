compress

"/var/log/httpd/access.log" /var/log/httpd/error.log
{
    rotate 5
    mail www@my.org
    size 100k
    sharedscripts
    postrotate
        /usr/bin/killall -HUP httpd
    endscript
}
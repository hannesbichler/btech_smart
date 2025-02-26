#!/bin/bash
### BEGIN INIT INFO
# Provides:          reconf.sh
# Required-Start:    $local_fs $network
# Required-Stop:     
# Default-Start:     S
# Default-Stop:      
# Short-Description: HBS RE-Configuration
### END INIT INFO
####################################################################################################
# source vars+func
####################################################################################################
source "/hbin/def-vars.txt.sh"
source "/hbin/def-func.txt.sh"
####################################################################################################
R_config_txt
####################################################################################################
W_dmesg "___Starting /hbin/reconf.sh"

####################################################################################################
# colored terminal prompt with date
echo "PS1='\[\033[1;32m\]\D{%F %T}\n\[\033[1;32m\]\u@\h:\w\$ \[\033[0m\]'" >/home/root/.profile

####################################################################################################
# enable ip forwarding
echo 1 >/proc/sys/net/ipv4/ip_forward

####################################################################################################
# gateway
#route add default gw "${g0}" eth0
#route add default gw "${g1}" eth1
# dns (gateway ip address)
#echo "nameserver ${g0}" >/etc/resolv.conf
#echo "nameserver ${g1}" >/etc/resolv.conf

####################################################################################################
S_datetime >/dev/null &

####################################################################################################
# /hbin/cometwd.sh &

####################################################################################################
/hbin/bichler_smart &
W_dmesg "/hbin/start bichler_smart &"

###################################################################################################
/cometintern/broadcast/broadcast_server &

####################################################################################################
# enable cronjob - /etc/crontab - /hbin/syschk.sh
echo 0 >/hbin/do_cron_jobs

####################################################################################################
W_dmesg "___/hbin/reconf.sh ready."

####################################################################################################

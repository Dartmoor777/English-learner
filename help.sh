#!/bin/bash
if [[ $# -eq 0 ]]
then
    echo "You should specify at least one argument!\n"
    exit
fi
echo ""
function zyxel {
    shift
    case $1 in
        'show') case $2 in
                'config') echo "show running-config";;
                'log') echo "show logging";;
                'cable') echo "cable-diagnostics <1-24> ";;
                'ports') echo "show interfaces <port>";;
                'errors') echo "show logging";;
                'mac') case $3 in
                        'blocked') echo "";;
                        'income')
                                echo "Firstly: check learning on the port"
                                echo "show port-security"
                                echo "if it open, shutdown it:"
                                echo "port-security <port> learn inactive"
                                echo "then check it:"
                                echo "show mac address-table port (all) <port>"
                                echo "after you have to revert the state:"
                                echo "no port-security <port> learn inactive"
                                ;;
                        'bound') echo "show mac address-table static";;
                    esac;;
            esac ;;
        'add') case $2 in
                'mac')
                    echo "1.First at all, check the MAC in database(c MAC)"
                    echo "2.If it has't found, the next step"
                    echo "config"
                    echo "mac-forward name x mac <xx:xx:xx:xx:> vlan <number> int <port>"
                    echo "3.save changes:"
                    echo "write"
                    echo "4.add the mac into database:"
                    echo "ad -i IP -m MAC"
                    echo "write the changes into billing"
                ;;
                'vlan')
                    echo "vlan <number>"
                    echo "Save it! -- write | write mem"
                    ;;
                'port')
                        echo "Tagging a port into vlan:"
                        echo "fixed <port>"
                        echo "exit"
                        echo "int p <port> no untagged"
                        echo "pvid <number_vlan>"
                        echo "Save it! -- write | write mem"
                    ;;
        esac;;
        'delete') case $2 in
                'mac')
                    echo "conf"
                    echo "no mac-forward mac <xx:xx:xx:xx:> vlan <number> int <port>"
                    echo "and then delete it from database and billing!"
                    echo "Save it! -- write | write mem"
                ;;
                'vlan') echo "dunno";;
                'port') echo "deleting a port from vlan:"
                        echo "forbidden <number_port>"
                        echo "Save it! -- write | write mem"
                    ;;
                'error') echo "dunno";;
        esac;;
        'reboot') echo "shutdown"
                    echo "no shutdown";;
        *)echo 'something went wrong..';;
    esac
}
function zyxel35 {
    shift
    case $1 in
        'show') case $2 in
                'config') echo "show running-config";;
                'cable') echo "cable-diagnostics <1-24> ";;
                'log') echo "show logging";; #maybe wrong
                'ports') echo "show interfaces status";;
                'errors') echo "dunno";;
                'mac') case $3 in
                        'blocked') echo "dunno";;
                        'income')
                                echo "config"
                                echo "1.Check mac-learning:"
                                echo "show port-security"
                                echo "2.If works shutdown it:"
                                echo "no port-security"
                                echo "3.Check an income mac:"
                                echo "show mac address-table port <nport>"
                                echo "4.Revert the state:"
                                echo "port-security"
                            ;;
                        'bound') echo "show classifier";;
                    esac;;
            esac ;;
        'add') case $2 in
                'mac')
                    echo "1.Firstly, check the MAC in the database!"
                    echo "2.Check from config file by keywords policy and classifier"
                    echo "3.Save it! -- write | write mem"
                    echo "After, add it into database and billing!"
                    ;;
                'vlan')
                    echo "get into vlan:"
                    echo "mvr <Nvlan>"
                    echo "vlan <Nvlan>"
                    echo "no inactive"
                    echo "Save it! -- write | write mem"
                    ;;
                'port')
                    echo "adding the port into vlan:"
                    echo "Example: receiver-port 1-26,28"
                    echo "Save it! -- write | write mem"
                    ;;
        esac;;
        'delete') case $2 in
                'mac')
                    echo "1.check the number of rules in config"
                    echo "show running-config"
                    echo "no policy pp19_1"
                    echo "no classifier port19_1"
                    echo "2.Save it! -- write | write mem"
                    echo "3.Delete it in the database and billing!"
                    echo "delip -i IP -m MAC"
                ;;
                'vlan')
                    echo "get into vlan:"
                    echo "mvr <Nvlan>"
                    echo "delete vlan"
                    echo "inactiv vlan"
                    echo "Save it! -- write | write mem"
                    ;;
                'port')
                    echo "forbidden <Nport>"
                    echo "Save it! -- write | write mem"
                    ;;
                'error') echo "dunno";;
        esac;;
        'reboot')
            echo "config"
            echo "interface port-channel <nport>"
            echo "inactive"
            echo "no inactive"
            ;;
        *) 'something went wrong..';;
    esac
}
function fox60 {
    shift
    case $1 in
        'show') case $2 in
                'config') echo "show running-config";;
                'cable') echo "doesn't exist";;
                'ports') echo "show port state";;
                'errors') echo "show port counter <nport>";;
                'vlan') echo "show vlan";;
                'mac') case $3 in
                        'blocked')echo 'dunno';;
                        'income')
                            echo "1.Shutdown a mac-learning"
                            echo "set security mac-learning <port> disable"
                            echo "2.Check an income mac"
                            echo "show port mac-learning <port>"
                            echo "Enabling of mac"
                            echo "set security mac-learning <port> enable"
                            ;;
                        'bound') echo "show security static-mac";;
                    esac;;
            esac ;;
        'add') case $2 in
                'mac')
                    echo "1.Check the MAC in the database!"
                    echo "2.set security static-mac <xxxx.xxxx.xxxx.xxxx> <N-porta>"
                    echo "3.Save it ! -- copy config flash"
                    echo "4.Add the MAC into database and billing!!"
                ;;
                'vlan') echo "Check: fox60 add port";;
                'port')
                    echo "set vlan <number_vlan> <port>"
                    echo "Save it ! -- copy config flash"
                    ;;
        esac;;
        'delete') case $2 in
                'mac')
                    echo "1.clear security static-mac <xxxx.xxxx.xxxx.xxxx>"
                    echo "2.Save it ! -- copy config flash"
                    echo "3.Delete from the database and billing!"
                    echo "delip -i IP -m MAC"
                ;;
                'vlan') echo "Check: fox60 delete port";;
                'port') echo "clear vlan <Nvlan> <port>"
                        echo "Write it in the billing!"
                    ;;
                'error') echo "clear port counter (port?)";; #maybe wrong
        esac;;
        'reboot')
            echo "set port disable <port>"
            echo "set port enable <port>"
            ;;
        *) 'something went wrong..';;
    esac
}
function fox62 {
    shift
    case $1 in
        'show') case $2 in
                'config') echo "show running-config";;
                'vlan') echo 'show vlan';;
                'log') echo 'show logging buffered level warnings';;
                'ports')
                    echo "show interface ethernet status"
                    #echo "(if only one port) config"
                    echo "show int eth 0/0/<port>"
                    ;;
                'cable')
                    echo "1.config"
                    echo "2.interface ethernet 0/0/<port>"
                    echo "3.virtual-cable-test"
                    echo "via new firmware -- virtual-cable-test interface ethernet"
                    ;;
                'errors')
                    echo "show port counter <nport>" #maybe wrong
                    echo "if there are any dhcp requests:"
                    echo "no ip dhcp snooping binding user-control"
                    ;;
                'mac') case $3 in
                        'blocked') echo "dunno";;
                        'income')
                            echo "1.You should turned off port-security"
                            echo "WARNNING!! After that the all your config on the port disappears!"
                            echo "show mac-address-table int eth 0/0/<port>"
                            echo "2.Ater, you should add the previous config on the port!"
                            ;;
                        'bound') echo "show mac-address-table static";;
                    esac;;
            esac ;;
        'add') case $2 in
                'mac')
                    echo "1.Firstly, check the MAC in the database!!"
                    echo "2.conf"
                    echo "3.interface ethernet 0/0/<port>"
                    echo "3.switchport port-security mac <new_mac>"
                    echo "(if you haven't deleted the config, you can skip 3 next steps)"
                    echo "4.switchport port-security max < 1-5 >"
                    echo "5.switchport access vlan <number_vlan>"
                    echo "6.switchport port-security violation restrict"
                    echo "Save it!! -- write | write mem"
                    echo "Add the mac into the database and billing!(ad -i IP -m MAC)"
                    ;;
                'vlan')
                    echo "1.conf"
                    echo "2.interface ethernet 0/0/<port>"
                    echo "3.switchport access vlan <number_vlan>"
                    echo "Save it!! -- write | write mem"
                    echo "Write it in the journal!"
                    ;;
                'port') echo "check: fox62 add vlan";;
                'trunk') echo "1.config>
                    2.interface ethernet 0/0/<port>
                    3.switchport mode trunk
                    4.switchport trunk allowed vlan add <...>"
                    echo "Save it!! -- write | write mem"
                    echo "Write it in the journal!"
        esac;;
        'delete') case $2 in
                'mac')
                    echo "1.conf"
                    echo "2.interface ethernet 0/0/<port>"
                    echo "Option 1:"
                    echo "no switchport port-security mac <old_mac>"
                    echo "Option 2:"
                    echo "no switchport port-security -- deleting all configs on the port"
                    echo "(after this you have to add all the configs!)"
                    echo "Save it!! -- write | write mem"
                    echo "Delete the mac from the database and billing!!"
                ;;
                'vlan')
                    echo "1.conf"
                    echo "2.interface ethernet 0/0/<port>"
                    echo "Option 1:"
                    echo "no switchport access vlan <number_vlan>"
                    echo "Option 2:"
                    echo "no switchport port-security -- deleting all configs on the port"
                    echo "(after this you have to add all the configs!)"
                    echo "Save it!! -- write | write mem"
                    echo "Write the information about it into billing!!"
                    ;;
                'port') echo "check: fox62 delete vlan";;
                'error') echo "dunno";;
        esac;;
        'reboot')
            echo "1.conf"
            echo "2.interface ethernet 0/0/<port>"
            echo "3.shutdown"
            echo "4.no shutdown"
            ;;
        *) 'something went wrong..';;
    esac
}
function linksys {
    shift
    case $1 in
        'show') case $2 in
                'config') echo "show running-config";;
                'vlan') echo "show vlan";;
                'cable') echo "";;
                'ports') echo "show interface status";;
                'errors') echo "show interfaces counters";;
                'mac') case $3 in
                        'blocked') echo "dunno";;
                        'income')
                            echo "1.conf"
                            echo "2.int eth e<port>"
                            echo "3.no port security"
                            echo "4.show bridge address-table ethernet e<number_interface>"
                            echo "5.port security"
                            ;;
                        'bound') echo "show mac address-table static";;
                    esac;;
            esac ;;
        'add') case $2 in
                'mac')
                    echo "1.Check the MAC in the database!!"
                    echo "2.config"
                    echo "3.interface vlan <number_vlan>"
                    echo "4.bridge address <mac_address> ethernet e<number_interface> secure"
                    echo "5.Save it!! -- write"
                    echo "6.Add the mac into database and billing!!"
                    ;;
                'vlan') echo "check: linksys add port";;
                'port')
                    echo "1.conf"
                    echo "2.int eth e<port>"
                    echo "3.switchport access vlan <number_vlan>"
                    echo "4.Save it!! -- write"
                    echo "5.Add information into billing!"
                    ;;
        esac;;
        'delete') case $2 in
                'mac')
                    echo "1.config"
                    echo "2.interface vlan <number_vlan>"
                    echo "3.no bridge address <old_mac_address> "
                    echo "4.Save it!! -- write"
                    echo "5.Delete the mac from the database and billing!!"
                ;;
                'vlan') echo "check linksys delete port";;
                'port')
                    echo "~~~maybe~~~"  #maybe wrong
                    echo "1.conf"
                    echo "2.int eth e<port>"
                    echo "3.no switchport access vlan <number_vlan>"
                    echo "4.Save it!! -- write"
                    echo "5.Add information into billing!"
                    ;;
                'error') echo "dunno";;
        esac;;
        'reboot')
            echo "~~~maybe~~~"  #maybe wrong
            echo "1.conf"
            echo "2.int eth e<port>"
            echo "shutdown"
            echo "no shutdown"
            ;;
        *) 'something went wrong..';;
    esac
}
function dlink {
    shift
    case $1 in
        'show') case $2 in
                'config') echo "";;
                'cable') echo "";;
                'ports') echo "";;
                'errors') echo "";;
                'mac') case $3 in
                        'blocked') echo "";;
                        'income') echo "";;
                        'bound') echo "";;
                    esac;;
            esac ;;
        'add') case $2 in
                'mac') echo "";;
                'vlan') echo "";;
                'port') echo "";;
        esac;;
        'delete') case $2 in
                'mac') echo "";;
                'vlan') echo "";;
                'port') echo "";;
                'error') echo "";;
        esac;;
        'reboot') echo "";;
        *) 'something went wrong..';;
    esac
}
case $1 in
    'zyxel') zyxel "$@" ;; #1
    'zyxel35')  zyxel35 "$@";; #2
    'fox60') fox60 "$@" ;; #3
    'fox62') fox62 "$@" ;; #4
    'linksys') linksys "$@" ;; #5
    'dlink') dlink "$@" ;; #6
esac
#case $1 in
    #'zyxel') let n=1*1000 ;; #1
    #'zyxel35') let n=2*1000 ;; #2
    #'fox60') let n=3*1000 ;; #3
    #'fox62') let n=4*1000 ;; #4
    #'linksys') let n=5*1000 ;; #5
    #'dlink') let n=6*1000 ;; #6
#esac

#case $2 in
    #'show') let "n+=1*100";; #1
    #'add') let "n+=2*100";; #2
    #'delete') let "n+=3*100";; #3
    #'reboot') let "n+=4*100";; #4
#esac

#if [[ $2 -eq 'show' ]] ;then
#case $3 in
    #'config') let "n+=1*10";;
    #'ports') let "n+=2*10";;
    #'mac') let "n+=3*10";;
    #'errors') let "n+=4*10"
#esac
#else
    #case $3 in
        #'mac') let "n+=5*10";;
        ##'vlan') let "n+=6*10";;
        #'port') let "n+=7*10";;
        #'errors')let "n+=8*10";;
    ##esac
#fi
#if [[ $# -eq 4 ]] ;then
#case $4 in
    #'bound') let "n+=1";;
    #'income') let "n+=2";;
    #'blocked') let "n+=3";;
#esac
#fi
#case $n in
    #1110) echo "";; #zyxel show config
    #1120) echo "";; #zyxel show ports
    #1130) echo "you should finish your command";; #zyxel show mac..
    #1131) echo "";; #zyxel show mac bound
    #1132) echo "";; #zyxel show mac income
    #1133) echo "";; #zyxel show mac blocked
    #12
#esac
echo ""
exit

#!/bin/bash
if [[ $# -eq 0 ]]
then
    echo 'You should specify at least one argument!'
    exit
fi
echo ''
function zyxel {
    shift
    case $1 in
        'show') case $2 in
                'config') echo 'show running-config';;
                'log') echo 'show logging';;
                'cable') echo 'cable-diagnostics (1-24) ';;
                'ports') echo 'show interfaces (port)';;
                'errors') echo 'show logging';;
                'mac') case $3 in
                        'blocked') echo '';;
                        'income')
                                echo '1.Check learning on the port'
                                echo 'show port-security'
                                echo '2.Then, switch mac-learning on:'
                                echo 'no port-security (port) learn inactive'
                                echo 'then check it:'
                                echo 'show mac address-table port (all) (port)'
                                echo '3.After you have to revert the state:'
				                echo 'port-security (port) learn inactive'
                                ;;
                        'bound') echo 'show mac address-table static';;
                *) echo "Incorrect keyword: $3"
                    echo "Possible endings: blocked, income, bound"
                    ;;
                    esac;;
                *)echo "Incorrect keyword: $2"
                    echo "Possible endings: config, log, vlan, cable, ports, errors, mac"
                    ;;
            esac ;;
        'add') case $2 in
                'mac')
                    echo '1.First at all, check the MAC in database(c MAC)'
                    echo '2.If it has*t found, the next step'
                    echo 'config'
                    echo 'mac-forward name x mac (xx:xx:xx:xx:) vlan (number) int (port)'
                    echo '3.save changes:'
                    echo 'write'
                    echo '4.add the mac into database:'
                    echo 'ad -i IP -m MAC'
                    echo 'write the changes into billing'
                ;;
                'vlan') echo 'dunno'
                    ;;
                'port')
                    	echo 'vlan (number)'
                        echo 'Tagging a port into vlan:'
                        echo 'fixed (port)'
                        echo 'exit'
                        echo 'int p (port) no untagged'
                        echo 'pvid (number_vlan)'
                        echo 'Save it! -- write | write mem'
                    ;;
                *)echo "Incorrect keyword: $2"
                    echo "Possible endings: mac, vlan, port"
                    ;;
        esac;;
        'delete') case $2 in
                'mac')
                    echo 'conf'
                    echo 'no mac-forward mac (xx:xx:xx:xx:) vlan (number) int (port)'
                    echo 'and then delete it from database and billing!'
                    echo 'Save it! -- write | write mem'
                ;;
                'vlan') echo 'dunno';;
                'port') echo 'deleting a port from vlan:'
			echo 'configure'
			echo 'vlan (vlan)'
                        echo 'forbidden (number_port)'
                        echo 'Save it! -- write | write mem'
                    ;;
                'error') echo 'dunno';;
		'abon')
			echo '1.Open the abon in billing and terminal'
			echo '2.Delete macs'
                    	echo 'conf'
                    	echo 'no mac-forward mac (xx:xx:xx:xx:) vlan (number) int (port)'
			echo '3.Delete the port from vlan'
			echo 'vlan (vlan)'
                        echo 'forbidden (number_port)'
                    	echo '4.then delete it from database!'
			echo '5.And billing!(lines, equipment, macs, ip)'
			echo '6.Write the changes into the journal!'
		;;
                *)echo "Incorrect keyword: $2"
                    echo "Possible endings: mac, vlan, port, error, abon"
                    ;;
        esac;;
        'reboot')
            echo 'interface ethernet <port>'
            echo 'shutdown'
            echo 'no shutdown';;
        *)echo "Incorrect keyword $1" ; echo 'Possible endings: show, add, delete, reboot';;
    esac
}
function zyxel35 {
    shift
    case $1 in
        'show') case $2 in
                'config') echo 'show running-config';;
                'cable') echo 'cable-diagnostics (1-24) ';;
                'log') echo 'show logging';; #maybe wrong
                'ports') echo 'show interfaces status';;
                'errors') echo 'dunno';;
                'mac') case $3 in
                        'blocked') echo 'dunno';;
                        'income')
                                echo 'config'
                                echo '1.Check mac-learning:'
                                echo 'show port-security'
                                echo '2.If works shutdown it:'
                                echo 'no port-security'
                                echo '3.Check an income mac:'
                                echo 'show mac address-table port (nport)'
                                echo '4.Revert the state:'
                                echo 'port-security'
                            ;;
                        'bound') echo 'show classifier';;
                *) echo "Incorrect keyword: $3"
                    echo "Possible endings: blocked, income, bound"
                    ;;
                    esac;;
                *)echo "Incorrect keyword: $2"
                    echo "Possible endings: config, log, vlan, cable, ports, errors, mac"
                    ;;
            esac ;;
        'add') case $2 in
                'mac')
                    echo '1.Firstly, check the MAC in the database!'
                    echo '2.Check from config file by keywords policy and classifier'
                    echo '3.Save it! -- write | write mem'
                    echo 'After, add it into database and billing!'
                    ;;
                'vlan')
                    echo 'get into vlan:'
                    echo 'mvr (Nvlan)'
                    echo 'vlan (Nvlan)'
                    echo 'no inactive'
                    echo 'Save it! -- write | write mem'
                    ;;
                'port')
                    echo 'adding the port into vlan:'
                    echo 'Example: receiver-port 1-26,28'
                    echo 'Save it! -- write | write mem'
                    ;;
                *)echo "Incorrect keyword: $2"
                    echo "Possible endings: mac, vlan, port"
                    ;;
        esac;;
        'delete') case $2 in
                'mac')
                    echo '1.check the number of rules in config'
                    echo 'show running-config'
                    echo 'no policy pp19_1'
                    echo 'no classifier port19_1'
                    echo '2.Save it! -- write | write mem'
                    echo '3.Delete it in the database and billing!'
                    echo 'delip -i IP -m MAC'
                ;;
                'vlan')
                    echo 'get into vlan:'
                    echo 'mvr (Nvlan)'
                    echo 'delete vlan'
                    echo 'inactiv vlan'
                    echo 'Save it! -- write | write mem'
                    ;;
                'port')
                    echo 'forbidden (Nport)'
                 	echo 'deleting a port from vlan:'
			echo 'configure'
			echo 'vlan (vlan)'
                    echo 'Save it! -- write | write mem'
                    ;;
                'error') echo 'dunno';;
		'abon')
			echo '1.Open the abon in billing and terminal'
			echo '2.Delete macs'
                    	echo '(check the number of rules in config)'
                    	echo 'show running-config'
                    	echo 'no policy ppx_y'
                    	echo 'no classifier portx_y'
			echo '3.Delete the port from vlan'
			echo 'config'
			echo 'vlan (nvlan)'
                        echo 'forbidden (number_port)'
                    	echo '4.then delete it from database!'
			echo '5.And billing!(lines, equipment, macs, ip)'
			echo '6.Write the changes into the journal!'
		;;
                *)echo "Incorrect keyword: $2"
                    echo "Possible endings: mac, vlan, port, error, abon"
                    ;;
        esac;;
        'reboot')
            echo 'config'
            echo 'interface port-channel (nport)'
            echo 'inactive'
            echo 'no inactive'
            ;;
        *) echo "Incorrect keyword $1" ; echo 'Possible endings: show, add, delete, reboot';;
    esac
}
function fox60 {
    shift
    case $1 in
        'show') case $2 in
                'config') echo 'show running-config';;
                'cable') echo 'doesn*t exist';;
                'ports') echo 'show port state';;
                'errors') echo 'show port counter (nport)';;
                'vlan') echo 'show vlan';;
                'mac') case $3 in
                        'blocked')echo 'dunno';;
                        'income')
                            echo '1.Switching on mac-learning'
                            echo '_set security mac-learning (port) enable'
                            echo '2.Check an income mac'
                            echo 'show port mac-learning (port)'
                            echo '1.Switching off mac-learning'
                            echo '_set security mac-learning (port) disable'
                            ;;
                        'bound') echo 'show security static-mac';;
                *) echo "Incorrect keyword: $3"
                    echo "Possible endings: blocked, income, bound"
                    ;;
                    esac;;
                *)echo "Incorrect keyword: $2"
                    echo "Possible endings: config, log, vlan, cable, ports, errors, mac"
                    ;;
            esac ;;
        'add') case $2 in
                'mac')
                    echo '1.Check the MAC in the database!'
                    echo '2._set security static-mac (xxxx.xxxx.xxxx.xxxx) (N-porta)'
                    echo '3.Save it ! -- copy config flash'
                    echo '4.Add the MAC into database and billing!!'
                ;;
                'vlan') echo 'Check: fox60 add port';;
                'port')
                    echo '_set vlan (number_vlan) (port)'
                    echo 'Save it ! -- copy config flash'
                    ;;
                *)echo "Incorrect keyword: $2"
                    echo "Possible endings: mac, vlan, port"
                    ;;
        esac;;
        'delete') case $2 in
                'mac')
                    echo '1.clear security static-mac (xxxx.xxxx.xxxx.xxxx)'
                    echo '2.Save it ! -- copy config flash'
                    echo '3.Delete from the database and billing!'
                    echo 'delip -i IP -m MAC'
                ;;
                'vlan') echo 'dunno';;
                'port') echo 'clear vlan (Nvlan) (port)'
                        echo 'Write it in the billing!'
                    ;;
                'error') echo 'clear port counter (port?)';; #maybe wrong
		'abon')
			echo '1.Open the abon in billing and terminal'
			echo '2.Delete macs'
                    	echo 'clear security static-mac (xxxx.xxxx.xxxx.xxxx)'
			echo '3.Delete the port from vlan'
			echo 'clear vlan (Nvlan) (port)'
                    	echo '4.then delete it from database!'
			echo '5.And billing!(lines, equipment, macs, ip)'
			echo '6.Write the changes into the journal!'
		;;
                *)echo "Incorrect keyword: $2"
                    echo "Possible endings: mac, vlan, port, error, abon"
                    ;;
        esac;;
        'reboot')
            echo '_set port disable (port)'
            echo '_set port enable (port)'
            ;;
        *) echo "Incorrect keyword $1" ; echo 'Possible endings: show, add, delete, reboot';;
    esac
}
function fox62 {
    shift
    case $1 in
        'show') case $2 in
                'config') echo 'show running-config';;
                'vlan') echo 'show vlan';;
                'log') echo 'show logging buffered level warnings';;
                'ports')
                    echo 'show interface ethernet status'
                    #echo '(if only one port) config'
                    echo 'show int eth 0/0/(port)'
                    ;;
                'cable')
                    echo '1.config'
                    echo '2.interface ethernet 0/0/(port)'
                    echo '3.virtual-cable-test'
                    echo 'via new firmware -- virtual-cable-test interface ethernet'
                    ;;
                'errors')
                    echo 'show port counter (nport)' #maybe wrong
                    echo 'if there are any dhcp requests:'
                    echo 'no ip dhcp snooping binding user-control'
                    ;;
                'mac') case $3 in
                        'blocked') echo 'dunno';;
                        'income')
                            echo '1.You should turned off port-security'
                            echo 'WARNNING!! After that the all your config on the port disappears!'
                            echo 'show mac-address-table int eth 0/0/(port)'
                            echo '2.Ater, you should add the previous config on the port!'
                            ;;
                        'bound') echo 'show mac-address-table static';;
                *) echo "Incorrect keyword: $3"
                    echo "Possible endings: blocked, income, bound"
                    ;;
                    esac;;
                *)echo "Incorrect keyword: $2"; echo "Possible endings: config, log, vlan, cable, ports, errors, mac"
                    ;;
            esac ;;
        'add') case $2 in
                'mac')
                    echo '1.Firstly, check the MAC in the database!!'
                    echo '2.conf'
                    echo '3.interface ethernet 0/0/(port)'
                    echo '3.switchport port-security mac (new_mac)'
                    echo '(if you haven*t deleted the config, you can skip 3 next steps)'
                    echo '4.switchport port-security max ( 1-5 )'
                    echo '5.switchport access vlan (number_vlan)'
                    echo '6.switchport port-security violation restrict'
                    echo 'Save it!! -- write | write mem'
                    echo 'Add the mac into the database and billing!(ad -i IP -m MAC)'
                    ;;
                'vlan')
                    echo '1.conf'
                    echo '2.interface ethernet 0/0/(port)'
                    echo '3.switchport access vlan (number_vlan)'
                    echo 'Save it!! -- write | write mem'
                    echo 'Write it in the journal!'
                    ;;
                'port') echo 'check: fox62 add vlan';;
                'trunk') echo '1.config)
                    2.interface ethernet 0/0/(port)
                    3.switchport mode trunk
                    4.switchport trunk allowed vlan add (...)'
                    echo 'Save it!! -- write | write mem'
                    echo 'Write it in the journal!'
                    ;;
                *)echo "Incorrect keyword: $2"
                    echo "Possible endings: mac, vlan, port, trunk"
                    ;;
        esac;;
        'delete') case $2 in
                'mac')
                    echo '1.conf'
                    echo '2.interface ethernet 0/0/(port)'
                    echo 'Option 1:'
                    echo 'no switchport port-security mac (old_mac)'
                    echo 'Option 2:'
                    echo 'no switchport port-security -- deleting all configs on the port'
                    echo '(after this you have to add all the configs!)'
                    echo 'Save it!! -- write | write mem'
                    echo 'Delete the mac from the database and billing!!'
                ;;
                'port')
                    echo '1.conf'
                    echo '2.interface ethernet 0/0/(port)'
                    echo 'no switchport access vlan (number_vlan)'
                    #echo 'no switchport port-security -- deleting all configs on the port'
                    echo '(after this you have to add all the configs!)'
                    echo 'Save it!! -- write | write mem'
                    echo 'Write the information about it into billing!!'
                    ;;
                'vlan') echo 'dunno';;
                'error') echo 'dunno';;
		'abon')
			echo '1.Open the abon in billing and terminal'
			echo '2.Delete macs'
			echo 'conf'
                    	echo 'interface ethernet 0/0/(port)'
                    	echo 'no switchport port-security -- deleting all configs on the port'
			echo '3.Delete the port from vlan'
                    	echo 'no switchport access vlan (number_vlan)'
                    	echo '4.then delete it from database!'
			echo '5.And billing!(lines, equipment, macs, ip)'
			echo '6.Write the changes into the journal!'
		;;
                *)echo "Incorrect keyword: $2"
                    echo "Possible endings: mac, vlan, port, error, abon"
                    ;;
        esac;;
        'reboot')
            echo '1.conf'
            echo '2.interface ethernet 0/0/(port)'
            echo '3.shutdown'
            echo '4.no shutdown'
            ;;
        *) echo "Incorrect keyword $1" ; echo 'Possible endings: show, add, delete, reboot';;
    esac
}
function linksys {
    shift
    case $1 in
        'show') case $2 in
                'config') echo 'show running-config';;
                'vlan') echo 'show vlan';;
                'cable') echo '';;
                'ports') echo 'show interface status';;
                'errors') echo 'show interfaces counters';;
                'mac') case $3 in
                        'blocked') echo 'dunno';;
                        'income')
                            echo '1.conf'
                            echo '2.int eth e(port)'
                            echo '3.no port security'
                            echo '4.show bridge address-table ethernet e(number_interface)'
                            echo '5.port security'
                            ;;
                        'bound') echo 'show mac address-table static';;
                *) echo "Incorrect keyword: $3"
                    echo "Possible endings: blocked, income, bound"
                    ;;
                    esac;;
                *)echo "Incorrect keyword: $2"
                    echo "Possible endings: config, log, vlan, cable, ports, errors, mac"
                    ;;
            esac ;;
        'add') case $2 in
                'mac')
                    echo '1.Check the MAC in the database!!'
                    echo '2.config'
                    echo '3.interface vlan (number_vlan)'
                    echo '4.bridge address (mac_address) ethernet e(number_interface) secure'
                    echo '5.Save it!! -- write'
                    echo '6.Add the mac into database and billing!!'
                    ;;
                'vlan') echo 'check: linksys add port';;
                'port')
                    echo '1.conf'
                    echo '2.int eth e(port)'
                    echo '3.switchport access vlan (number_vlan)'
                    echo '4.Save it!! -- write'
                    echo '5.Add information into billing!'
                    ;;
                *)echo "Incorrect keyword: $2"
                    echo "Possible endings: mac, vlan, port"
                    ;;
        esac;;
        'delete') case $2 in
                'mac')
                    echo '1.config'
                    echo '2.interface vlan (number_vlan)'
                    echo '3.no bridge address (old_mac_address) '
                    echo '4.Save it!! -- write'
                    echo '5.Delete the mac from the database and billing!!'
                ;;
                'vlan') echo 'check linksys delete port';;
                'port')
                    echo '~~~maybe~~~'  #maybe wrong
                    echo '1.conf'
                    echo '2.int eth e(port)'
                    echo '3.no switchport access vlan (number_vlan)'
                    echo '4.Save it!! -- write'
                    echo '5.Add information into billing!'
                    ;;
                'error') echo 'dunno';;
		'abon')
			echo '1.Open the abon in billing and terminal'
			echo '2.Delete macs'
                    	echo 'config'
                    	echo 'interface vlan (number_vlan)'
                    	echo 'no bridge address (old_mac_address) '
			echo '3.Delete the port from vlan'
                    	echo 'int eth e(port)'
                    	echo 'no switchport access vlan (number_vlan)'
                    	echo '4.then delete it from database!'
			echo '5.And billing!(lines, equipment, macs, ip)'
			echo '6.Write the changes into the journal!'
		;;
                *)echo "Incorrect keyword: $2"
                    echo "Possible endings: mac, vlan, port, error, abon"
                    ;;
        esac;;
        'reboot')
            echo '~~~maybe~~~'  #maybe wrong
            echo '1.conf'
            echo '2.int eth e(port)'
            echo 'shutdown'
            echo 'no shutdown'
	    echo '(or inactive, etc.)'
            ;;
	    *) echo "Incorrect keyword $1" ; echo 'Possible endings: show, add, delete, reboot';;
    esac
}
function dlink {
    shift
    case $1 in
        'show') case $2 in
                'config') echo 'show access_profile profile_id 3';;
                'log') echo 'show log';;
                'vlan') echo 'dunno';;
                'cable') echo 'cable_diag ports (nport)';;
                'ports') echo 'show ports';;
                'errors')
			echo 'show error ports (port)'
			echo 'If mac on aplink port:'
			echo '1.show fdb mac_address (MAC) '
			echo '2.clear fdb port (nport)'
			echo '3.create fdb (vlan*s name) (mac) port (nport)'
			echo '4.Write this accident into billing!'
			;;
                'mac') case $3 in
                        'blocked') echo 'show address_binding blocked all';;
                        'income')
				echo '1.config ports (nport) learning enable/disable'
				echo '2.show fdb port (nport)'
			;;
                        'bound')
				echo 'firmware1:'
				echo 'show access_profile profile_id 3'
				echo 'firmware2:'
				echo 'show fdb static'
				;;
                *) echo "Incorrect keyword: $3"
                    echo "Possible endings: blocked, income, bound"
                    ;;
                    esac;;
                *)echo "Incorrect keyword: $2"
                    echo "Possible endings: config, log, vlan, cable, ports, errors, mac"
                    ;;
            esac ;;
        'add') case $2 in
                'mac')
			echo 'Firmware1:'
			echo '1.Check in the database!!'
			echo '2.Check rules'
			echo '3.config access_profile profile_id 3 add access_id (num of rule) ethernet source_mac (MAC) port (nport) permit'
			echo '4.save it!! -- save'
			echo '5.Add the MAC into the database and billing!'
			echo 'Firmware2:'
			echo '1.Check in the database!!'
			echo '2.Check rules'
			echo '3.create fdb (vlan*s name) (mac) port (nport)'
			echo '4.save it!! -- save'
			echo '5.Add the MAC into the database and billing!'
			;;
                'port') echo 'config vlan vlanid (N_Vlan) add untagged (Nport)';;
                'vlan') echo 'dunno';;
                *)echo "Incorrect keyword: $2"
                    echo "Possible endings: mac, vlan, port"
                    ;;
        esac;;
        'delete') case $2 in
                'mac')
			echo '1.Check rules'
			echo '2.config access_profile profile_id 3 delete access_id (num of rule)'
			echo 'or the next:'
			echo 'delete fdb (name vlan) mac'
			echo '3.Delete the MAC into the database and billing!'
			;;
                'vlan') echo 'check: dlink delete port';;
                'port')
			echo 'config vlan vlanid (N_Vlan) delete (Nport)'
			echo 'on DES-3526:'
			echo 'config vlan <vlanid> delete <port>'
			;;
                'error') echo 'clear counters ports (port)';;
		'abon')
			echo '1.Open the abon in billing and terminal'
			echo '2.Delete macs'
			echo 'Check rules'
			echo 'config access_profile profile_id 3 delete access_id (num of rule)'
			echo 'or the next:'
			echo 'delete fdb (name vlan) mac'
			echo '3.Delete the port from vlan'
			echo 'config vlan vlanid (N_Vlan) delete (Nport)'
			echo 'on DES-3526:'
			echo 'config vlan <vlanid> delete <port>'
                    	echo '4.then delete it from database!'
			echo '5.And billing!(lines, equipment, macs, ip)'
			echo '6.Write the changes into the journal!'
		;;
                *)echo "Incorrect keyword: $2"
                    echo "Possible endings: mac, vlan, port, error, abon"
                    ;;
        esac;;
        'reboot')
		echo 'config ports (nport) state enable/disable';;
        *) echo "Incorrect keyword $1" ; echo 'Possible endings: show, add, delete, reboot';;
    esac
}
case $1 in
    'zyxel') zyxel "$@" ;; #1
    'zyxel35')  zyxel35 "$@";; #2
    'fox60') fox60 "$@" ;; #3
    'fox62') fox62 "$@" ;; #4
    'linksys') linksys "$@" ;; #5
    'dlink') dlink "$@" ;; #6
    *) echo "Incorrect keyword $1"
    echo 'Possible endings: zyxel, zyxel35, fox60, fox62, linksys, dlink';;
esac
echo ''
exit

#!ruby
require 'dbus'

puts "I'm there!"

sys = DBus::SystemBus.instance

dbus_service = sys['org.freedesktop.DBus']
dbus_object = dbus_service['/org/freedesktop/DBus']
#puts dbus_object.introspect
dbus_interface = dbus_object['org.freedesktop.DBus']
#puts dbus_interface.ListNames

iwd_obj = sys['net.connman.iwd']['/net/connman/iwd/0/4']
#iwd_obj['Nodes']
puts iwd_obj.introspect
#puts iwd_obj['net.connman.iwd.KnownNetwork']['Name']
puts iwd_obj['org.freedesktop.DBus.Properties'].GetAll 'net.connman.iwd.Station'

#net.connman.iwd.KnownNetwork
#        <node name="0"/>
#<node name="3432_psk"/>
#<node name="6d6f72736b61796139_psk"/>
#<node name="37_psk"/>
#
#

#upower_interface = upower_object["org.freedesktop.UPower"]
#on_battery       = upower_interface["OnBattery"]

# dbus-send --system            \
#   --dest=org.freedesktop.DBus \
#   --type=method_call          \
#   --print-reply               \
#   /org/freedesktop/DBus       \
#   org.freedesktop.DBus.ListNames

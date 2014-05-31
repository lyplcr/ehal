arch=$(zenity --list --title="select architecture:" \
	--column="arch" $(ls arch))
sub=$(zenity --list --title="select architecture:" \
	--column="arch" $(ls arch/$arch))
mcu=$( zenity --list --title="select mcu:" \
	--column="mcu" $(cat arch/$arch/$sub/mcus))

echo "arch:" $arch "sub:" $sub "mcu:" $mcu

while read line
do
	eval echo "$line"
done < "arch/$arch/$sub/config" > .config

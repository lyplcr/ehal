echo "choose the arch:"
ls arch/
read -r arch
echo

echo "choose the sub arch:"
ls arch/$arch/
read -r sub
echo

echo "choose the mcu:"
cat arch/$arch/$sub/mcus
read -r mcu
echo

echo "arch:" $arch "sub:" $sub "mcu:" $mcu

while read line
do
	eval echo "$line"
done < "arch/$arch/$sub/config" > .config

#! /bin/bash

echo "Installation de wxWidgets sur votre ordinateur"


mkdir ../../../builds
mkdir ../../../builds/gtk-build-1

cd ../../../builds/gtk-build-1

echo "Installation des dépendances"
echo "Vous devez être root sur votre machine pour pouvoir continuer"

# sous ubuntu, si ça ne fonctionne pas, décommenter l'instr suivante
#apt-get install build-essential
apt-get install libgtk-3-0
apt-get install libgtk-3-dev
#si ça ne fonctionne pas, décommenter l'intr suivante sur ubuntu (et seulement ubuntu)
#apt-get install gnome-core-devel

set -e

../../automate/src/gui/wxWidgets-3.0.2/configure --enable-unicode CFLAGS="-fPIC" CXXFLAGS="-fPIC" --with-libpng --with-libjpeg
make
make install


echo "Version de wxwidget installée : "
wx-config --version

## Dossier regroupant les sources de l'interface

** Avant de commencer, lancer la commande suivante (si vous avez déja installé wxwidgets 3.0.2, voir ci-dessous) : **

	sudo apt-get install libwxgtk2.8-dev wx-common

Un fois ceci fait, faite ce que vous voulez dans le fichier /gui/src
Pour compiler, lancez make à la racine (automate/src/gui)
ça va compiler toutes les sources que vous avez modifiées. L'executable créé d'appelle ACS (Automate Cellulaire à Signaux)


### Si vous avez déja installé wxWidgets 3.0.2:

* Aller dans le répertoire gtk-build-1 créé et lancer :
	* make uninstall
	* make clean
* si en faisant wx-config --version vous voyez encore 3.0.2, faites ceci :
	* allez dans /usr/local/include et supprimez à la main le dossier wx (être root)
	* allez dans /usr/local/lib et supprimez à la main le dossier wx (être root)
	* les dossiers wx mentionnés plus tôt peuvent être nommés wx-<version>, supprimez ceux la.
* lancez sudo apt-get install libwxgtk2.8-dev wx-common
* lancez wx-config --version Vous devriez voir 2.8.12
* Si ce n'est pas le cas, skypez moi.

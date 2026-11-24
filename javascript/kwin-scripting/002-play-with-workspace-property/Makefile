install:
	kpackagetool6 --type=KWin/Script -i .

uninstall:
	kpackagetool6 --type=KWin/Script -r playwithworkspace

reload:
	kwriteconfig6 --file kwinrc --group Plugins --key playwithworkspaceEnabled false
	qdbus-qt6 org.kde.KWin /KWin reconfigure
	sleep 1s
	kpackagetool6 --type=KWin/Script -u .
	kwriteconfig6 --file kwinrc --group Plugins --key playwithworkspaceEnabled true
	qdbus-qt6 org.kde.KWin /KWin reconfigure

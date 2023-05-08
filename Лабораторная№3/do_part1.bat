chcp 65001
mkdir ПТ-22\ШарагаД.О.\batch\СкрытаяПапка ПТ-22\ШарагаД.О.\batch\НеСкрытаяПапка
attrib +h ПТ-22\ШарагаД.О.\batch\СкрытаяПапка
xcopy /? > ПТ-22\ШарагаД.О.\batch\НеСкрытаяПапка\copyhelp.txt
xcopy /f /a ПТ-22\ШарагаД.О.\batch\НеСкрытаяПапка\copyhelp.txt ПТ-22\ШарагаД.О.\batch\СкрытаяПапка\copyhelp.txt
ren /y ПТ-22\ШарагаД.О.\batch\СкрытаяПапка\copyhelp.txt copied_copyhelp.txt

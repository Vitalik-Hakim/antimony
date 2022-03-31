:: Create a batch file to copy the nodeconf file into the hidden AppData Folder
:: Users should run this file after installing the Antimony.exe
:: Put the file antimony.conf in this dir C:\Users\ok\AppData\Roaming\Antimony
COPY "Nodes\antimony.conf" "%APPDATA%\Antimony"

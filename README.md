Antimony P2P Crypto
================================

This is an Experimental Software purposely for my School Personal Project.

Copyright (c) 2009-2014 Bitcoin Developers<br />
Copyright (c) 2011-2014 Litecoin Developers<br />
Copyright (c) 2020-2022 Antimony Developers<br />

What is Antimony?
----------------

Antimony is a lite version of Bitcoin using scrypt as a proof-of-work algorithm.
 - 2 minute block targets
 - subsidy halves in 240k blocks (~4 years Approx)
 - ~5 million total coins
 - 25 coins per block
 - 2016 blocks to retarget difficulty

For more information, as well as an immediately useable, binary version of
the Antimony client sofware, send me an email at aremeyaw_a@soshgic.edu.gh

<h3> HOW TO INSTALL for Windows OS </h3>

<h2>Release steps and Precautions:</h2>


1) NOTE: Antimony.exe has an inbuilt miner that may be detected by your system as a silent miner. So make sure you disable your Antivirus or add an exclusion for the folder.
2) Windows Smart Screen May appear saying `"Ah! ah! I Blocked a terrible app from destroying your system!" `but this is just a result of me not getting or buying a Windows publishing Certificate.

#Skip this step with a very simple process Go to Connect automatically through ActivateNode.bat
3) Last but compulsory thing to set up will be the `antimony.conf` file in your package folder. This contains active nodes on the network that I couldn't hard code into the application.
Just copy and paste the .conf file in the `C:\Users\${Your username}\AppData\Roaming\Antimony`. It's a hidden folder so just paste this in your file explorer path.

4) I will be updating a new file called `activenodes` with new ip's that are active nodes on the network. So if you are not getting connected just copy the new nodes in the `activenodes.txt` file and paste the contents into your configuration files or the `antimony.conf` file. In the path of where previous option showed you. That is the `C:\Users\${Your username}\AppData\Roaming\Antimony\antimony.conf`

To start Mining the coin after starting the application, just open `help` then `debug`. Choose `console` and type in this 
`setgenerate true`
hit Enter

Boom you have started mining your own ANTYs.

To stop mining just type in the console
`setgenerate false`

Thats it! We just made our own Blockchain and Virtual Currency. 
Don't be greedy after mining your coins.
Make sure to send me some  ANTY donations at this address `AQXpFQRZ49wwJJsdYuWqS3FjSNLSNmYTyB` it will be much appreciated. 
Linux or specifically Ubuntu Building instructions coming soon. Stay tuned.
Thanks Have a nice day.

### Connect to a Node
To connect to a specified node from the activenodes file , just open `help` then `debug`. Choose `console` and type in this 
`addnode 192.. onetry `
replace the 192.. with the specific node
hit Enter

### Connect automatically through ActivateNode.bat
To connect to the specified node from the activenodes file , just run the ActivateNode.bat file and the node will be connected.


License
-------

Antimony is released under the terms of the MIT license. See `COPYING` for more
information or see http://opensource.org/licenses/MIT.

Building from Source
--------------------

Building from source may require some dependencies. I will add them later.
But if you have built bitcoin or litecoin from source, you may have all of them.
Clone the v1.2 version tag from the repo using:

    git clone -b v1.2 https://github.com/Vitalik-Hakim/antimony.git
This is the latest version that is working.

### Build CLI VERSION
To build the daemon version:

    cd src
    make -f makefile.unix
    ./antimonyd -server -daemon
This will build the daemon.

### Build GUI VERSION
To build the GUI version:
Right in the Antimony folder

    qmake
    make
    ./antimony-qt
    or 
    ./antimony-qt -testnet
    for Testnet
This will build the GUI version of Antimony.

Development process
-------------------

Developers work in their own trees, then submit pull requests when they think
their feature or bug fix is ready.

If it is a simple/trivial/non-controversial change, then one of the Antimony
development team simply pulls it.

If it is a *more complicated or potentially controversial* change, then the patch
submitter will be asked to start a discussion with the devs and community.

The patch will be accepted if there is broad consensus that it is a good thing.
Developers should expect to rework and resubmit patches if the code doesn't
match the project's coding conventions (see `doc/coding.txt`) or are
controversial.

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/antimony-project/antimony/tags) are created
regularly to indicate new official, stable release versions of Antimony.

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test. Please be patient and help out, and
remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write unit tests for new code, and to
submit new unit tests for old code.

Unit tests for the core code are in `src/test/`. To compile and run them:

    cd src; make -f makefile.unix test

Unit tests for the GUI code are in `src/qt/test/`. To compile and run them:

    qmake BITCOIN_QT_TEST=1 -o Makefile.test bitcoin-qt.pro
    make -f Makefile.test
    ./antimony-qt_test


Burstcoin-Miner
===========

Features added in this fork:-
- add support of uray based miner to mine at pool behind cloudflare or any other DDOS protection engine.
(Main purpose is to have linux based miner to work on pool behind cloudflare such as burstrenegade and pool.burstcoin.space, tested in Windows too.)


Burstcoin Miner with low Output

This miner only displays
- current block
- readtime for plotfiles
- deadline result

Based on burst-miner by Uray Meiviar.

Added functionalities by Luc Van Braekel:

Forked from cuthulino

+ Solo mining:

	Add the following lines to the mining.conf file:

	`"mode" : solo`

	`"passPhrase" : your passphrase here`


+ Max Deadline to be submitted to server:

	Just change the following line in the mining.conf file:

	`"maxDeadline" : ????`

	For solo mining, choose a low value like 5000 to withhold useless deadlines.

	For pool mining, choose a high value in order not to lose any shares or use the max for your pool.

+ Time reporting:

	Time for complete reading of plotfiles will be reported every round.


## compilation :
tested on Linux using GCC

+ for linux, just do "make", binary will be in "bin" directory and then edit "mining.conf" file
+ for windows, compilation is tested using Visual Studio Express 2013 (Desktop)
+ for OSX, compilation is tested using XCode 5

burst-miner
===========

Native burstcoin miner.

Fast, multithreaded, low memory usage, multi-account and multi-plot.
You can specity plot directories or files inside mining.conf file.

Based on burst-miner by Uray Meiviar.

Added functionalities by Luc Van Braekel:

Solo mining:
Add the following lines to the mining.conf file:
+ "mode" : "solo",
+ "passPhrase" : "your passphrase here"

This miner is only multi-account when pool mining.

Contact : Luc Van Braekel [ luc@lvb.net ]

+ [ Burst   ] `BURST-3XFG-2JSB-HCUX-7HXBC`
+ [ Bitcoin ] `19ZgsPHQFNRDcM8An7yg1Jaj87F1VwN7ci`

## compilation :
tested on OSX and Linux using GCC 4.8.x

+ for linux, just do "make", binary will be in "bin" directory and then edit "mining.conf" file
+ for windows, compilation is tested using Visual Studio Express 2013 (Desktop)
+ for OSX, compilation is tested using XCode 5

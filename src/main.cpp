//  Modified Burstcoin Miner
//  with added solo mining capability
// 
//  Author: Luc Van Braekel <luc@lvb.net> 2015
//
//  Burst: BURST-3XFG-2JSB-HCUX-7HXBC
//  Bitcoin: 19ZgsPHQFNRDcM8An7yg1Jaj87F1VwN7ci
//
//  Based on:
//  cryptoport.io Burst Pool Miner
//
//  Created by Uray Meiviar < uraymeiviar@gmail.com > 2014
//  donation :
//
//  [Burst  ] BURST-8E8K-WQ2F-ZDZ5-FQWHX
//  [Bitcoin] 1UrayjqRjSJjuouhJnkczy5AuMqJGRK4b

#include "Miner.h"

int main(int argc, const char* argv[])
{
    //Burst::MinerLogger::write("Modified Burst Miner");
    //Burst::MinerLogger::write("-----------------------");
    //Burst::MinerLogger::write("https://github.com/cuthulino/BurstMiner");
    //Burst::MinerLogger::write("author : cuthulino");
    //Burst::MinerLogger::write("based on cryptoport miner by Uray Meiviar, forked by Luc Van Breakel");
    Burst::MinerLogger::write(" ");

#ifdef WIN32
	WSADATA   wsadata;
	if (WSAStartup(MAKEWORD(2, 2), &wsadata) != 0)
	{
		Burst::MinerLogger::write("failed to initalize networking system");
	}
#endif
    
    std::string configFile = "mining.conf";
    if(argc > 1)
    {
        if(argv[1][0] == '-')
        {
            Burst::MinerLogger::write("usage : burstminer <config-file>");
            Burst::MinerLogger::write("if no config-file specified, program will look for mining.conf file inside current directory");
        }
        configFile = std::string(argv[1]);
    }
    //Burst::MinerLogger::write("using config file : "+configFile);
    
    Burst::MinerConfig config;
    if( config.readConfigFile(configFile) )
    {
		Burst::MinerLogger::write("Config:");
        Burst::MinerLogger::write("Submission Max Delay: "+ std::to_string(config.submissionMaxDelay));
        Burst::MinerLogger::write("Submission Max Retry: "+ std::to_string(config.submissionMaxRetry));
        Burst::MinerLogger::write("Submission Max Deadline: "+ std::to_string(config.maxDeadline));
        Burst::MinerLogger::write("Buffer Size: "+ std::to_string(config.maxBufferSizeMB)+"MB");
        Burst::MinerLogger::write("Pool Host: "+config.poolHost+"  Port: "+ std::to_string(config.poolPort));
	if (config.mode.length() > 0)
	{
            Burst::MinerLogger::write("Mode: "+config.mode);
	}
        
        Burst::Miner miner(config);
        miner.run();
    }
    else
    {
        Burst::MinerLogger::write("Aborting program due to invalid configuration");
    }
    
#ifdef WIN32
	WSACleanup();
#endif
    return 0;
}


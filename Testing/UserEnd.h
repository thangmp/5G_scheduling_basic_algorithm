#pragma once
    class UserEnd
    {
        //Constants
        public:
        int MCS;
        int index;
        int NumberOfRBScheduled;
        int NumberOfTTIScheduled;
        int Delay;
        int AverageDelay;
        int MaxDelay;
        double AverageMCS;
        double Throughput;
        double AverageThroughput;
        double Priority;
        double TotalBitsTrx;
        double TotalRBsScheduled;
        bool Scheduled;

        //Constructors
        UserEnd()
        {
            MCS = 0;
            index = 0;
            AverageMCS = 0;
            NumberOfRBScheduled = 0;
            TotalRBsScheduled = 0;
            NumberOfTTIScheduled = 0;
            Throughput = 0;
            TotalBitsTrx = 0;
            Delay = 0;
            AverageDelay = 0;
            MaxDelay = 0;
            AverageThroughput = 0;
            Priority = 0;
            Scheduled = false;
        }; 

        UserEnd(int index_, int MCS_)
        {
            MCS = MCS_;
            index = index_;
            AverageMCS = 0;
            NumberOfRBScheduled = 0;
            TotalRBsScheduled = 0;
            NumberOfTTIScheduled = 0;
            Throughput = 0;
            TotalBitsTrx = 0;
            Delay = 0;
            AverageDelay = 0;
            MaxDelay = 0;
            AverageThroughput = 0;
            Priority = 0;
            Scheduled = false;
        }; 
    }UE;

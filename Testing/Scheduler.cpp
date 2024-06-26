// Library
#include "Scheduler.h"
using namespace std;


    Scheduler::Scheduler(const vector<UserEnd>& UEs) : ues(UEs) {
        for (size_t i = 0; i < ues.size(); ++i) {
            ue_queue.push(i);
        }
    };

    void Scheduler::calculateDataRate() {
        for (UserEnd& ue : ues)
        {
        // Caclculate the datarate in Megabits/sec
            if(ue.Scheduled = true && ue.NumberOfTTIScheduled != 0 ) {
                ue.TotalBitsTrx = ue.NumberOfTTIScheduled * TBSizeArr[ue.MCS][(ue.NumberOfRBScheduled-1)] * 8; // Total Transmitted Bits 
                ue.Throughput = ue.TotalBitsTrx/(TTI*1000); // Calculate Throughput using Total Transmitted Bits / TTI 
                ue.AverageThroughput = (ue.AverageThroughput + ue.Throughput) / 2;
                ue.Scheduled = false;
            }else break;
        }
    };

    void Scheduler::calculateCellDataRate() {
        for (UserEnd& ue : ues)
        {
        // Caclculate the datarate in Megabits/sec
            Cell.CellTotalBitsTrx += ue.TotalBitsTrx;
            Cell.CellAvgThroughput = Cell.CellTotalBitsTrx/(TTI*1000);
            
        }
    };

    //Roundrobin Scheduler
    void Scheduler::RR_scheduler() {
        int ue_count = ues.size();
        int scheduled_ues = 0;
        TTI++;

    // Randomize MCS for each UE
        for (UserEnd& ue : ues) {
            ue.AverageMCS += ue.MCS;
        }

    // Algorithm Loop
        while (!ue_queue.empty() && scheduled_ues < 4) {
            int ue_index = ue_queue.front(); 
            ue_queue.pop();
            UserEnd& ue = ues[ue_index];
            
            // Allocate Resource Blocks to this UserEnd
            ue.NumberOfRBScheduled = num_rbs / 4; 
            ue.TotalRBsScheduled += ue.NumberOfRBScheduled;
            ue.NumberOfTTIScheduled++; 
            ue.Delay = 0; 
            ue.Scheduled = true;
            // Move to the next UserEnd in the round-robin queue
            ue_queue.push(ue_index);
            scheduled_ues++;
        }

    //Delay Calculation
        for (UserEnd& ue : ues) {
            if (ue.Scheduled == false) {
                ue.Delay++; 
                ue.AverageDelay += ue.Delay;
                ue.MaxDelay = max(ue.Delay,ue.MaxDelay);
            }
        }
    // Calculate Throughput
        calculateDataRate();
    };

    //MaxCQI Scheduler
    void Scheduler::MaxCQI_scheduler() {

    // Randomize MCS for each UE
        for (UserEnd& ue : ues) {
            if(TTI % 1 == 0 ) {
                if(ue.index < 4) ue.MCS = 20 +  (rand() % 8);
                else if(ue.index < 10) ue.MCS = 10 +  (rand() % 11);
                else ue.MCS = rand() % 10;
            }
        }

    // Sort UEs based on MCS 
        sort(ues.begin(), ues.end(), [](const UserEnd& a, const UserEnd& b) {
            return a.MCS > b.MCS;
        });
        TTI++;

    // Allocate RBs to the top 4 UEs based on MCS
        int scheduled_ue = 0;
        int rb_per_ue = num_rbs / 4; 

    // Algorithm Loop
        for (UserEnd& ue : ues) {
            ue.AverageMCS += ue.MCS;
            if (scheduled_ue < 4) {
                ue.NumberOfRBScheduled = rb_per_ue;
                ue.TotalRBsScheduled += ue.NumberOfRBScheduled;
                ue.NumberOfTTIScheduled++;
                ue.Scheduled = true;
                scheduled_ue++;
                ue.Delay = 0; // Reset delay counter for UEs that got scheduled
            } else {
                ue.Delay++; // Increase delay counter for UEs not scheduled
                ue.AverageDelay += ue.Delay;
                ue.MaxDelay = max(ue.Delay,ue.MaxDelay);
            }
        }

    // Calculate Throughput
        calculateDataRate();

    //Return the UE vector form base on Average MCS
        sort(ues.begin(), ues.end(), [](const UserEnd& a, const UserEnd& b) {
        return a.AverageMCS > b.AverageMCS;
        });
    }


    //Proportional Fair Scheduler
    void Scheduler::PF_scheduler() {
    // Randomize MCS for each UE
        for (UserEnd& ue : ues) {
            if(TTI % 1 == 0 ) {
                if(ue.index < 4) ue.MCS = 20 +  (rand() % 8);
                else if(ue.index < 10) ue.MCS = 10 +  (rand() % 11);
                else ue.MCS = rand() % 10;
            }
        }
    // Calculate the scheduling metric for each UE (Proportional Fair metric)
        for (UserEnd& ue : ues) {
            if (ue.AverageThroughput == 0.0) {
                ue.AverageThroughput = ue.Throughput; // Initialize the average data rate
            }
        }

    // Sort UEs based on the Proportional Fair metric
        sort(ues.begin(), ues.end(), [](UserEnd& a,UserEnd& b) {
            a.Priority = a.Throughput / (a.AverageThroughput + 1); // Avoid division by zero
            b.Priority = b.Throughput / (b.AverageThroughput + 1);
            if(a.Delay > 39) {
                a.Priority = 99;
            } else if(b.Delay > 39) {
                b.Priority = 99;
                return b.Priority < a.Priority;
            }
            return a.Priority > b.Priority;
        });

        // Allocate RBs to the top 4 UEs based on the PF metric
        int scheduled_ues = 0;
        int rb_per_ue = num_rbs / 4; // Allocate an equal number of RBs to each of the top 4 UEs

        for (UserEnd& ue : ues) {
            ue.AverageMCS += ue.MCS;
            if (scheduled_ues < 4) {
                ue.NumberOfRBScheduled = rb_per_ue;
                ue.TotalRBsScheduled += ue.NumberOfRBScheduled;
                ue.NumberOfTTIScheduled++;
                ue.Scheduled = true;
                scheduled_ues++;
                ue.Delay = 0; // Reset delay counter for UEs that got scheduled
            } else {
                ue.Delay++; // Increase delay counter for UEs not scheduled
                ue.AverageDelay += ue.Delay;
                ue.MaxDelay = max(ue.Delay,ue.MaxDelay);
            }
        }


    // Calculate Throughput
        calculateDataRate();

    //Return the UE vector form
        sort(ues.begin(), ues.end(), [](const UserEnd& a, const UserEnd& b) {
        return a.AverageMCS > b.AverageMCS;
        });
        
    // Next TTI
        TTI++;

    };

    void Scheduler::print_allocation()  {
        cout << " Cell Throughput: " << setprecision(4) << setw(5) << Cell.CellAvgThroughput  << " Mbps \n \n" ;
        for (const UserEnd& ue : ues) {
            cout << " At TTI "  << TTI  << " || UserEnd " << setw(2) << ue.index + 1  << " || Average MCS: " << setw(4) << ue.AverageMCS/TTI 
            << " || Average Number of RBs per TTI: " << setw(5) << ue.TotalRBsScheduled/TTI << " RBs " 
            << "|| Number of TTI Scheduled: " << setw(5) << ue.NumberOfTTIScheduled <<  " || Average Throughput: " << setprecision(4) << setw(7) << ue.Throughput
            <<  " Mbps" << " || Average Delay: " << setw(2) << ue.AverageDelay/TTI 
            << " || Max Delay: " << ue.MaxDelay << " TTIs \n";
        } 
    }

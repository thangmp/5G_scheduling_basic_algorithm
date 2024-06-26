// Library
#include "Scheduler.h"
using namespace std;


int main()
{
//Constants
    srand( time(NULL) );

    int TTI = 0;
    int simTime = 10000;

    int UserCount = MAX_NUMBER_OF_UES;
    int UserIndex = 0;

    int MCS_value;
    int Scheduler_mode;

// UESetup
    vector<UserEnd> UEs;
    vector<int> mcs_values = {5, 19, 2, 14, 7, 27, 3, 26, 10, 6, 18, 23};

// Define the MCS values for each UE
    while(UserIndex < MAX_NUMBER_OF_UES)
    {
        //MCS_value = rand() % 27;
        MCS_value = mcs_values[UserIndex];
        UEs.emplace_back(UserIndex,MCS_value);
        UserIndex++;
    }

//Create a Scheduler
    Scheduler scheduler(UEs);

// Run
    // Input
    cout << "Select Scheduler Mode: 1 = Round Robin || 2 = MaxCQI || 3 = Propotional Fair \n" << "Mode = " ;
    cin >> Scheduler_mode;
    // Algoritm Loop
    while(TTI < simTime)
    {
    //Check status and current TTI
        sleep(0.01);
    switch (Scheduler_mode)
    {
    case 1:
    // Roung Robin Scheduler
        scheduler.RR_scheduler();
        break;
    case 2:
    //MaxCQI Scheduler
        scheduler.MaxCQI_scheduler();
        break;
    case 3:
    //PF Scheduler    
        if(TTI < 3) scheduler.RR_scheduler();
        else scheduler.PF_scheduler();
        break;
    default:
        TTI = -1;
        cout << "Invalid Input! Please select scheduler mode: 1 = Round Robin || 2 = MaxCQI || 3 = Propotional Fair \n" << "Mode = " ; 
        cin >> Scheduler_mode;
        break;
    }
    

    // Print out info every 1s
        // if(TTI % 1000 == 0 && TTI > 0) {
        //     scheduler.print_allocation();
        //     cout << endl;
        // }
        
        TTI++;
    }
    scheduler.calculateCellDataRate();
    scheduler.print_allocation();
    return 0;
}
#pragma once
// Library
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <vector> 
#include <queue>
#include<algorithm>
#include <bits/stdc++.h>
#include "gNodeB.h"
#include "UserEnd.h"
#include "macTBSize.cpp"

//Namespace
using namespace std;

//Definition
#define MAX_NUMBER_OF_UES 12


    class Scheduler {
        int TTI = 0; //Transmission Time Interval
        int num_rbs = MAX_RESOURCE_BLOCK; // Number of Resource Blocks available per TTI
        gNodeB Cell; // Cell Data
        std::vector<UserEnd> ues; // List of UEs
        std::queue<int> ue_queue; // Queue to keep track of UserEnd scheduling order

        public:
        Scheduler(const vector<UserEnd>& UEs);
        void calculateDataRate();
        void calculateCellDataRate();
        void RR_scheduler();
        void MaxCQI_scheduler();
        void PF_scheduler();
        void print_allocation();
    };

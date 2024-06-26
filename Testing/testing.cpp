void PF(int total_TTI, int numOfUE, int max_UE_in_TTI){
    /*int numOfUE = 12;
    struct UEInformation UE[20];
    int total_TTI = 10000;
    int max_UE_in_TTI = 4;
    int subFrame_Time = 1; //1TTI = 1 SubFrame = 1ms. Trong trường hợp này để 1s để test*/

    int countTTI = 0; // SAU KHI 4 UE ĐƯỢC CẤP TBS THÌ UPDATE
    struct UEInformation UE[20];
    for(int i=0;i<numOfUE;i++){// KHỞI TẠO CÁC GIÁ TRỊ BAN ĐẦU CỦA TỪNG UE BẰNG 0 HẾT
            UE[i].scheduleTimes = 0;
            UE[i].Throughput = 0;
            UE[i].TTIDelay = 0;
    }

    while(countTTI < total_TTI){
        for(int i=0;i<numOfUE;i++){ /*CẤP MCS CHO TỪNG UE*/
            UE[i].MCS = updateMCS();
        }

        for(int i=0;i<numOfUE;i++){ /*SAU MỖI LẦN LẬP LỊCH RESET TRẠNG THÁI UE VỀ FALSE HẾT*/
            UE[i].IsScheduled = false;
        }

        pair<int,int> posValue[12]; // KHỞI TẠO MỘT PAIR

        for(int i=0;i<numOfUE;i++){ // GÁN TỪNG GIÁ TRỊ MCS VÀ THỨ TỰ CỦA UE VÀO MỘT PAIR
            posValue[i] = make_pair(UE[i].MCS,i);
        }

        sort(posValue, posValue + numOfUE);// SẮP XẾP LẠI ĐỘ ƯU TIÊN CỦA CÁC UE THEO GIÁ TRỊ MCS

        int countUEOutOf40 = 0; // BIẾN ĐẾM SỐ LƯỢNG UE CHƯA ĐƯỢC LẬP LỊCH TRONG 40 TTI
        vector<int> UEposOut40;// VECTO LƯU VỊ TRÍ CỦA CÁC UE CHƯA ĐƯỢC LẬP LỊCH TRONG 40 TTI
        for(int i=0;i<numOfUE;i++){
            if(UE[i].TTIDelay >= 40){
                countUEOutOf40++;
                UEposOut40.push_back(i);
                cout << "User " << i << "out of 40 TTIs ";
            }
        }

        switch(countUEOutOf40){
        case 0:
            for(int i = numOfUE-1; i > numOfUE - 1 - max_UE_in_TTI + countUEOutOf40; i--){ // CỘNG TÍCH LŨY SỐ LẦN ĐƯỢC LẬP LỊCH VÀ TBS CỦA 4 UE CÓ MCS CAO NHẤT
                UE[posValue[i].second].scheduleTimes ++;// Cộng số lần lập lịch
                UE[posValue[i].second].Throughput += TBSizeArr[UE[posValue[i].second].MCS][24];
                UE[posValue[i].second].IsScheduled = true; // SAU KHI ĐƯỢC LẬP LỊCH THÌ SẼ THÀNH TRUE
                UE[posValue[i].second].TTIDelay = 0; // KHI ĐÃ ĐƯỢC LẬP LỊCH THÌ TTI DELAY SẼ VỀ 0
            }
            break;
        case 1:
            for(int i = numOfUE-1; i > numOfUE - 1 - max_UE_in_TTI + countUEOutOf40; i--){ // CỘNG TÍCH LŨY SỐ LẦN ĐƯỢC LẬP LỊCH VÀ TBS CỦA 4 UE CÓ MCS CAO NHẤT
                UE[posValue[i].second].scheduleTimes ++;// Cộng số lần lập lịch
                UE[posValue[i].second].Throughput += TBSizeArr[UE[posValue[i].second].MCS][24];
                UE[posValue[i].second].IsScheduled = true; // SAU KHI ĐƯỢC LẬP LỊCH THÌ SẼ THÀNH TRUE
                UE[posValue[i].second].TTIDelay = 0; // KHI ĐÃ ĐƯỢC LẬP LỊCH THÌ TTI DELAY SẼ VỀ 0
            }
            UE[UEposOut40[0]].scheduleTimes ++;
            UE[UEposOut40[0]].Throughput += TBSizeArr[UE[UEposOut40[0]].MCS][24];
            UE[UEposOut40[0]].IsScheduled = true;
            UE[UEposOut40[0]].TTIDelay = 0;
            UEposOut40.erase(UEposOut40.begin());// SAU KHI LẬP LỊCH CHO 1 UE CÓ TTI DELAY > 40, XÓA UE ĐÓ KHỎI VECTO VÀ TIẾN HÀNH RESET
            break;
        case 2:
            for(int i = numOfUE-1; i > numOfUE - 1 - max_UE_in_TTI + countUEOutOf40; i--){ // CỘNG TÍCH LŨY SỐ LẦN ĐƯỢC LẬP LỊCH VÀ TBS CỦA 4 UE CÓ MCS CAO NHẤT
                UE[posValue[i].second].scheduleTimes ++;// Cộng số lần lập lịch
                UE[posValue[i].second].Throughput += TBSizeArr[UE[posValue[i].second].MCS][24];
                UE[posValue[i].second].IsScheduled = true;
                UE[posValue[i].second].TTIDelay = 0;
            }
            for(int i=0;i<countUEOutOf40;i++){
                UE[UEposOut40[i]].scheduleTimes ++;
                UE[UEposOut40[i]].Throughput += TBSizeArr[UE[UEposOut40[0]].MCS][24];
                UE[UEposOut40[i]].IsScheduled = true;
                UE[UEposOut40[i]].TTIDelay = 0;
                UEposOut40.erase(UEposOut40.begin(),UEposOut40.begin()+countUEOutOf40-1);
            }
            break;
        case 3:
            for(int i = numOfUE-1; i > numOfUE - 1 - max_UE_in_TTI + countUEOutOf40; i--){ // CỘNG TÍCH LŨY SỐ LẦN ĐƯỢC LẬP LỊCH VÀ TBS CỦA 4 UE CÓ MCS CAO NHẤT
                UE[posValue[i].second].scheduleTimes ++;// Cộng số lần lập lịch
                UE[posValue[i].second].Throughput += TBSizeArr[UE[posValue[i].second].MCS][24];
                UE[posValue[i].second].IsScheduled = true;
                UE[posValue[i].second].TTIDelay = 0;
            }
            for(int i=0;i<countUEOutOf40;i++){
                UE[UEposOut40[i]].scheduleTimes ++;
                UE[UEposOut40[i]].Throughput += TBSizeArr[UE[UEposOut40[0]].MCS][24];
                UE[UEposOut40[i]].IsScheduled = true;
                UE[UEposOut40[i]].TTIDelay = 0;
                UEposOut40.erase(UEposOut40.begin(),UEposOut40.begin()+countUEOutOf40-1);
            }
            break;
        default:// Trường hợp 4,5,6,7,8 người không được lập lịch
            for(int i=0;i<countUEOutOf40;i++){
                UE[UEposOut40[i]].scheduleTimes ++;
                UE[UEposOut40[i]].Throughput += TBSizeArr[UE[UEposOut40[0]].MCS][24];
                UE[UEposOut40[i]].IsScheduled = true;
                UE[UEposOut40[i]].TTIDelay = 0;
                UEposOut40.erase(UEposOut40.begin(),UEposOut40.begin()+3);
            }
    }
        for(int i=0;i<numOfUE;i++){// NẾU NHƯ UE CHƯA ĐƯỢC LẬP LỊCH THÌ TTI DELAY TĂNG THÊM 1 ĐƠN VỊ
            if(UE[i].IsScheduled == false){
                UE[i].TTIDelay++;
            }
        }

        countTTI++;// SAU KHI 4UE ĐƯỢC LẬP LỊCH THÌ TĂNG CHỈ SỐ TTI CHO ĐẾN KHI ĐỦ 10000 THÌ DỪNG
    }
    for(int i=0;i<numOfUE;i++){
        cout << "Schedule Times of UE " << i << " is: " << UE[i].scheduleTimes << endl;
        cout << "Throughput of UE " << i << "is: " << UE[i].Throughput/UE[i].scheduleTimes << endl;
    }
}
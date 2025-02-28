// Coordinate Processes in order to construct dataset
// DJI_M300RTK_Process
// Optitrack_Process
// SickVisionaryTMini_Process

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


// Signals
// SIGINT (2)-> Send to finish processes
// SIGUSR1 (10)-> Send to start recording the data by each process

int main(int argc, char* argv[]){ //Parent Process

    int PID_DJI_M300RTK_Process;
    int PID_Optitrack_Process;
    int PID_SickVisionaryTMini_Process;

    char ch='q';
    char *args[10];

    //------------------------------------------------------------------
    printf("-->DJI_M300RTK_Process will run...\n");
    if(!(PID_DJI_M300RTK_Process = fork())){
        args[0] = "/home/lattepanda/git/RIS_122E408_Project/DJI_Payload_SDK/build/bin/DJI_M300RTK_Process";
        args[1] = NULL;
        if(-1==execv("/home/lattepanda/git/RIS_122E408_Project/DJI_Payload_SDK/build/bin/DJI_M300RTK_Process", args)){
            printf("-->EXEC ERROR: DJI_M300RTK_Process...\n");
            exit(0);
        }

    }
    if(PID_DJI_M300RTK_Process!=-1){
        printf("-->DJI_M300RTK_Process is running...\n");
    }
    else{
        printf("-->ERROR: DJI_M300RTK_Process is not running...\n");
    }
    sleep(5);
    //------------------------------------------------------------------

    //------------------------------------------------------------------
    printf("-->Optitrack_Process will run...\n");
    if(!(PID_Optitrack_Process = fork())){
        args[0] = "/home/lattepanda/git/RIS_122E408_Project/Optitrack_NatNet_SDK_4_1_Ubuntu/samples/SampleClient/build/Optitrack_Process";
        args[1] = NULL;
        if(-1==execv("/home/lattepanda/git/RIS_122E408_Project/Optitrack_NatNet_SDK_4_1_Ubuntu/samples/SampleClient/build/Optitrack_Process", args)){
            printf("-->EXEC ERROR: Optitrack_Process...\n");
            exit(0);
        }
    }
    if(PID_Optitrack_Process!=-1){
        printf("-->Optitrack_Process is running...\n");
    }
    else{
        printf("-->ERROR: Optitrack_Process is not running...\n");
    }
    sleep(5);
    //------------------------------------------------------------------

    //------------------------------------------------------------------
    printf("-->SickVisionaryTMini_Process will run...\n");
    if(!(PID_SickVisionaryTMini_Process = fork())){
        args[0] = "/home/lattepanda/git/RIS_122E408_Project/SickVisionarySamples/build/122E408/SickVisionaryTMini_Process";
        args[1] = NULL;      
        if(-1==execv("/home/lattepanda/git/RIS_122E408_Project/SickVisionarySamples/build/122E408/SickVisionaryTMini_Process", args)){
            printf("-->EXEC ERROR: Optitrack_Process...\n");
            exit(0);
        }
    }
    if(PID_SickVisionaryTMini_Process!=-1){
        printf("-->SickVisionaryTMini_Process is running...\n");
    }
    else{
        printf("-->ERROR: SickVisionaryTMini_Process is not running...\n");
    }
    sleep(5);
    //------------------------------------------------------------------

    while(ch!='s'){
	    printf("Enter r to start recording, s to finish the processes:");
        scanf("%c",&ch);

        if(ch=='r'){
            kill(PID_DJI_M300RTK_Process,SIGUSR1);
            kill(PID_Optitrack_Process,SIGUSR1);
            kill(PID_SickVisionaryTMini_Process,SIGUSR1);
        }
        else if(ch=='s'){
            kill(PID_DJI_M300RTK_Process,SIGINT);
            kill(PID_Optitrack_Process,SIGINT);
            kill(PID_SickVisionaryTMini_Process,SIGINT);
        }
        else
            ch='q';
    }

	return 0;
} // end-main
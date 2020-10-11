#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printCPU(){
    printf("CPU Information :\n");

    //use linux commands
    system("grep -m1 'cpu cores' /proc/cpuinfo");

    //read from the proc file and use string functions
    FILE *fp;
    fp = fopen("/proc/cpuinfo", "r");

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        if(strstr(line, "cpu MHz")!=NULL)
            printf("%s", line);
    }

    fclose(fp);
}

void printVersion(){
    printf("Information about version of running Linux Kernel :\n");

    //using linux commands
    system("grep -m1 'version' /proc/version"); //command is cat /proc/version or cat /proc/version
}

 void printTimeSinceLastBoot(){
	printf("Information about date and time since the last boot :\n");
    //using linux commands
    system("date -d @$(( $(date +%s) - $(cut -f1 -d. /proc/uptime) ))");
 }

void printAverageLoadonSystemlast15mins(){
	printf("Information about Average Load on System last 15 mins :\n");
    //using linux commands 
    system("awk '{ print $3 }' /proc/loadavg");

}
 
void MemoryInfo(){
	printf("Information about usable and currently free memory in the system :\n");//Assuming memory means RAM not hard disk
    //using linux commands 
    //system("head -3 /proc/meminfo")
    //system("awk '/MemAvailable/ {print $0}' /proc/meminfo");
    //system("awk '/MemFree/ {print $0}' /proc/meminfo");
    
    system("egrep  'Mem|Cache|Swap' /proc/meminfo");
    
    //MemTotal: Total amount of usable RAM.
    //MemFree: The amount of physical RAM left unused by the system.
    //MemAvailable: An estimate of how much memory is available for starting new applications, without swapping.
    //Buffers: The amount of temporary storage for raw disk blocks.
    //Cached: The amount of physical RAM used as cache memory.
    //SwapCached: The amount of memory that has once been moved into swap, then back into the main memory.
    //SwapTotal: The total amount of swap available.
    //SwapFree: The total amount of swap free.
    system("free");
}
 
 void SwapInfo(){
      printf("The total swap space and the currently used swap space in the system\n");
      system("grep Swap /proc/meminfo");
 }


 void SwapPartitions(){
      printf("The swap partitions and their sizes\n");
      system("cat /proc/swaps");
      system("swapon -s -v");
 }
 void UserAndKernelModeTime(){
 	printf("The time the CPU spent (over all processes) in the user mode and kernel mode\n");
 	system("head -3 /proc/stat| awk '/cpu/' /proc/stat");
 	//The very first "cpu" line aggregates the numbers in all of the other "cpuN" lines.

    //These numbers identify the amount of time the CPU has spent performing different kinds of work. Time units are in USER_HZ or Jiffies (typically hundredths of a second).

    //The meanings of the columns are as follows, from left to right:

    //user: normal processes executing in user mode
    //nice: niced processes executing in user mode
    //system: processes executing in kernel mode
    //idle: twiddling thumbs
    //iowait: waiting for I/O to complete
    //irq: servicing interrupts
    //softirq: servicing softirqs
 }
void ContextSwitches()
{
	printf("The number of context switches made by the system so far:\n");
	system("awk '/ctxt/ ' /proc/stat");
}

void Interrupts(){
    printf("The number of interrupts handled by the system so far\n");
    system("cat /proc/interrupts | wc -l");
}

void AllInfo(){
	printf("All info \n");
	printf("CPU Information :\n");

    //use linux commands
    system("grep -m1 'cpu cores' /proc/cpuinfo");

    //read from the proc file and use string functions
    FILE *fp;
    fp = fopen("/proc/cpuinfo", "r");

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        if(strstr(line, "cpu MHz")!=NULL)
            printf("%s", line);
    }

    fclose(fp);
    printf("Information about version of running Linux Kernel :\n");

    //using linux commands
    system("grep -m1 'version' /proc/version"); //command is cat /proc/version or cat /proc/
    printf("Information about date and time since the last boot :\n");
    //using linux commands
    system("date -d @$(( $(date +%s) - $(cut -f1 -d. /proc/uptime) ))");
    printf("Information about Average Load on System last 15 mins :\n");
    //using linux commands 
    system("awk '{ print $3 }' /proc/loadavg");
    printf("Information about usable and currently free memory in the system :\n");//Assuming memory means RAM not hard disk
    //using linux commands 
    //system("head -3 /proc/meminfo")
    //system("awk '/MemAvailable/ {print $0}' /proc/meminfo");
    //system("awk '/MemFree/ {print $0}' /proc/meminfo");
    
    system("egrep  'Mem|Cache|Swap' /proc/meminfo");
    
    //MemTotal: Total amount of usable RAM.
    //MemFree: The amount of physical RAM left unused by the system.
    //MemAvailable: An estimate of how much memory is available for starting new applications, without swapping.
    //Buffers: The amount of temporary storage for raw disk blocks.
    //Cached: The amount of physical RAM used as cache memory.
    //SwapCached: The amount of memory that has once been moved into swap, then back into the main memory.
    //SwapTotal: The total amount of swap available.
    //SwapFree: The total amount of swap free.
    system("free");
    printf("The total swap space and the currently used swap space in the system\n");
      system("grep Swap /proc/meminfo");

    printf("The swap partitions and their sizes\n");
      system("cat /proc/swaps");
      system("swapon -s -v");
    printf("The time the CPU spent (over all processes) in the user mode and kernel mode\n");
 	system("head -3 /proc/stat| awk '/cpu/' /proc/stat");  
    printf("The number of context switches made by the system so far:\n");
	system("awk '/ctxt/ ' /proc/stat");
	
    printf("The number of interrupts handled by the system so far\n");
    system("cat /proc/interrupts | wc -l");

}
int main(int argc, char const *argv[])
{
    int choice = 0;

    while (1)
    {
        printf("\nEnter your choice :\n");
        printf("1. CPU Information\n");
        printf("2. Linux Kernel Version\n");
        printf("3. Time Since Last Boot\n");
        printf("4. Average Load on System last 15 mins\n");
        printf("5. Memory Information :\n");
        printf("6. Swap SpaceInformation\n");
        printf("7. Swap Partition Information\n");
        printf("8. CPU time Kernel and User Mode\n");
        printf("9. Number of Context Switches\n");
        printf("10. Number of Interrupts\n");
        printf("11. All Information\n");
        printf("12. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printCPU();
            break;
        
        case 2:
            printVersion();
            break;

        case 3:
            printTimeSinceLastBoot();
            break;

        case 4:
            printAverageLoadonSystemlast15mins();
            break;

        case 5:
            MemoryInfo();
            break;

        case 6:
            SwapInfo();
            break;

        case 7:
            SwapPartitions();
            break;

        case 8:
            UserAndKernelModeTime();
            break;

        case 9:
            ContextSwitches();
            break;

        case 10:
            Interrupts(); 
            break;

        case 11:
            AllInfo();
            break;

        case 12:
            exit(0);
            break;

        default:
            printf("Invalid Choice!");
            break;
        }
    }
    
    return 0;
}
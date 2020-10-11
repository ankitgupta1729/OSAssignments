#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUFFER_SIZE 1000000

int check_page_hit(int page_no,int no_of_frames,int *pf)
{
	int page_hit=0;
	int j=0;
    for(j=0; j< no_of_frames; j++)
    {
        if(pf[j]==page_no)
        {
            page_hit=1;
            break;
        }
 
    }
 
    return page_hit;
}

int FIFO(int no_of_pages,int no_of_frames,int *ref_str)
{
   printf("FIFO Page Replacement Algo\n");
   int total_page_faults=0;
   int pf[50];
   int i,k;
    for(i=0; i<no_of_frames; i++)
        pf[i]=9999;
    for(i=0; i<no_of_pages; i++)
    {
        printf("\nFor %d :",ref_str[i]);
        if(check_page_hit(ref_str[i],no_of_frames,pf)==0)
        {
            for(k=0; k<no_of_frames-1; k++)
                pf[k]=pf[k+1];
            pf[k]=ref_str[i];
            total_page_faults++;
            for (k=0; k<no_of_frames; k++)
             {
               if(pf[k]!= 9999)
                   printf("%d",pf[k]);
             }
        }
        else
            printf("No page fault");
    }
    printf("\nTotal no of page faults:%d\n\n",total_page_faults);    
}

int getIndex(int ref_data,int no_of_frames,int *pf)
{
    int k,index;
    for(k=0; k<no_of_frames; k++)
    {
        if(pf[k]==ref_data)
        {
            index=k;
            break;
        }
    }
    return index;
}

int LFU(int no_of_pages,int no_of_frames,int *ref_str)
{
	printf("LFU Page Replacement Algo");
   int count[100];
   int l,r,sofar_count=0,b;
   int total_page_faults=0;
   int pf[50];
   int i,k;
    for(i=0; i<no_of_frames; i++)
        pf[i]=9999;
    for(i=0; i<no_of_frames; i++)
        count[i]=0;
    for(i=0; i<no_of_pages; i++)
    {
        printf("\n For %d :",ref_str[i]);
        if(check_page_hit(ref_str[i],no_of_frames,pf))
        {
            int index=getIndex(ref_str[i], no_of_frames, pf);
            count[index]++;
            printf("No page fault");
        }
        else
        {
            total_page_faults++;
            if(b<no_of_frames)
            {
                pf[b]=ref_str[i];
                count[b]=count[b]+1;
                b++;
            }
            else
            {
                l=9999;
                for(k=0; k<no_of_frames; k++)
                    if(count[k]<l)
                    {
                        l=count[k];
                        r=k;
                    }
                pf[r]=ref_str[i];
                sofar_count=0;
                for(k=0; k<=i; k++)
                    if(ref_str[i]==ref_str[k])
                        sofar_count=sofar_count+1;
                count[r]=sofar_count;
            }
 
            for (k=0; k<no_of_frames; k++)
             {
               if(pf[k]!= 9999)
                   printf("%d",pf[k]);
             }
        }

 
    }
    printf("\nTotal no of page faults:%d\n\n",total_page_faults);
   
}

int LRU(int no_of_pages,int no_of_frames,int *ref_str)
{
    printf("LRU Page Replacement Algo");	
   int total_page_faults=0;
   int pf[50];
   int i,j,k;
    for(i=0; i<no_of_frames; i++)
        pf[i]=9999;
   int less[50];
   for(i=0; i<no_of_pages; i++)
    {
        printf("\nFor %d :",ref_str[i]);
 
        if(check_page_hit(ref_str[i],no_of_frames,pf)==0)
        {
 
            for(j=0; j<no_of_frames; j++)
            {
                int x=pf[j];
                int y=0;
                for(k=i-1; k>=0; k--)
                {
                    if(x==ref_str[k])
                    {
                        less[j]=k;
                        y=1;
                        break;
                    }
                    else
                        y=0;
                }
                if(!y)
                    less[j]=-9999;
            }
            int min=9999;
            int index;
            for(j=0; j<no_of_frames; j++)
            {
                if(less[j]<min)
                {
                    min=less[j];
                    index=j;
                }
            }
            pf[index]=ref_str[i];
            total_page_faults++;
 
            for (k=0; k<no_of_frames; k++)
             {
               if(pf[k]!= 9999)
                   printf("%d",pf[k]);
             }
         }
        else
            printf("No page fault");
    }
    printf("\nTotal no of page faults:%d\n\n",total_page_faults);
}
int main(int argc, char const *argv[])
{
	int i=0,line=9;
	const char *delimiter_characters = " ";
	char buffer[ BUFFER_SIZE ];
    char *last_token;
	FILE *fp;
	fp=fopen("data.txt","r");
	/*if(argc <=5){
	  for (i=0; i<argc;i++)
	  	//printf("%s\n", argv[i]);
	
	else
	   printf("maximum 5 command-line arguments are allowed!\n ");  */
	i=0;
	int m=0;
	int reference_string[100000];
	int no_of_pages;
	int no_of_frames;
	if(fp==NULL)
		printf("File is failed to open\n");
	else
		{
			// Read each line into the buffer
        while( fgets(buffer, BUFFER_SIZE, fp) != NULL ){
            // Write the line to stdout
            //fputs( buffer, stdout );

            // Gets each token as a string and prints it
            last_token = strtok( buffer, delimiter_characters );
            while( last_token != NULL ){
                //printf( "%s", last_token );
                reference_string[m]=atoi(last_token);
                if(m==0)
                	no_of_pages=reference_string[0];
                if(m==1)
                	no_of_frames=reference_string[1];
                last_token = strtok( NULL, delimiter_characters );
                m++;
              }
           }   
	   } 
	i=0;
	int ref_str[no_of_pages];

	for(m=2;m<no_of_pages+2;m++)
	    //printf("%d\n",reference_string[m]);

    for(m=2;m<no_of_pages+2;i++,m++)
    	ref_str[i]=reference_string[m];

    for(i=0;i<no_of_pages;i++)
	    //printf("%d\n",ref_str[i]);
    
    if(argc ==1)
    {
    	FIFO(no_of_pages,no_of_frames,ref_str);
    	LFU(no_of_pages,no_of_frames,ref_str);
    	LRU(no_of_pages,no_of_frames,ref_str);
    }
    if(argc==5 && strcmp(argv[2],"FF")==0 && strcmp(argv[3],"LF")==0 && strcmp(argv[4],"LR")==0)
    {
    	FIFO(no_of_pages,no_of_frames,ref_str);
    	LFU(no_of_pages,no_of_frames,ref_str);
    	LRU(no_of_pages,no_of_frames,ref_str);
    }
    if(argc==5 && strcmp(argv[2],"FF")==0 && strcmp(argv[3],"LR")==0 && strcmp(argv[4],"LF")==0)
    {
    	FIFO(no_of_pages,no_of_frames,ref_str);
    	LRU(no_of_pages,no_of_frames,ref_str);
    	LFU(no_of_pages,no_of_frames,ref_str);
    }
    if(argc==5 && strcmp(argv[2],"LF")==0 && strcmp(argv[3],"FF")==0 && strcmp(argv[4],"LR")==0)
    {
    	LFU(no_of_pages,no_of_frames,ref_str);
    	FIFO(no_of_pages,no_of_frames,ref_str);
    	LRU(no_of_pages,no_of_frames,ref_str);
    }
    if(argc==5 && strcmp(argv[2],"LF")==0 && strcmp(argv[3],"LR")==0 && strcmp(argv[4],"FF")==0)
    {
    	LFU(no_of_pages,no_of_frames,ref_str);
    	LRU(no_of_pages,no_of_frames,ref_str);
    	FIFO(no_of_pages,no_of_frames,ref_str);
    }
    if(argc==5 && strcmp(argv[2],"LR")==0 && strcmp(argv[3],"FF")==0 && strcmp(argv[4],"LF")==0)
    {
    	LRU(no_of_pages,no_of_frames,ref_str);
    	FIFO(no_of_pages,no_of_frames,ref_str);
    	LFU(no_of_pages,no_of_frames,ref_str);
    }
    if(argc==5 && strcmp(argv[2],"LR")==0 && strcmp(argv[3],"LF")==0 && strcmp(argv[4],"FF")==0)
    {
    	LRU(no_of_pages,no_of_frames,ref_str);
    	LFU(no_of_pages,no_of_frames,ref_str);
    	FIFO(no_of_pages,no_of_frames,ref_str);
    }

    if(argc==4 && strcmp(argv[2],"FF")==0 && strcmp(argv[3],"LF")==0)
    {
    	FIFO(no_of_pages,no_of_frames,ref_str);
    	LFU(no_of_pages,no_of_frames,ref_str);
    }
    if(argc==4 && strcmp(argv[2],"LF")==0 && strcmp(argv[3],"FF")==0)
    {
    	LFU(no_of_pages,no_of_frames,ref_str);
    	FIFO(no_of_pages,no_of_frames,ref_str);
    }
    if(argc==4 && strcmp(argv[2],"LF")==0 && strcmp(argv[3],"LR")==0)
    {
    	LFU(no_of_pages,no_of_frames,ref_str);
    	LRU(no_of_pages,no_of_frames,ref_str);
    }
    if(argc==4 && strcmp(argv[2],"LR")==0 && strcmp(argv[3],"LF")==0)
    {
    	LFU(no_of_pages,no_of_frames,ref_str);
    	LRU(no_of_pages,no_of_frames,ref_str);
    }
    if(argc==4 && strcmp(argv[2],"FF")==0 && strcmp(argv[3],"LR")==0)
    {
    	FIFO(no_of_pages,no_of_frames,ref_str);
    	LRU(no_of_pages,no_of_frames,ref_str);
    }
    if(argc==4 && strcmp(argv[2],"LR")==0 && strcmp(argv[3],"FF")==0)
    {
    	FIFO(no_of_pages,no_of_frames,ref_str);
    	LRU(no_of_pages,no_of_frames,ref_str);
    }
    if(argc==3 && strcmp(argv[2],"FF")==0)
    {
    	FIFO(no_of_pages,no_of_frames,ref_str);
    }
    if(argc==3 && strcmp(argv[2],"LF")==0)
    {
    	LFU(no_of_pages,no_of_frames,ref_str);
    }
    if(argc==3 && strcmp(argv[2],"LR")==0)
    {
    	LRU(no_of_pages,no_of_frames,ref_str);
    }
    
	fclose(fp);	

	return 0;
}
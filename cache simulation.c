#include <stdlib.h>
#include <stdio.h>

#define stream 1    //0 - print to screen, 1- write to cache.out
#define main_memory 1024   //1024 addressable main_memory
#define cache_line 10       // 10 cache lines
#define cache_block_size 8   //8 words in each cache lines
int cache_tag(cache_line);    //cache cache_tag
                              //if (cache_tag[i] == 0), it's a MISS!!
int total_memory_access=0;      //amount of memory access or
                                //address request from CPU
int total_hit=0;                //amount of cache hit

//print the hit ratio
void print_hit_ratio(void)
{
  float ratio;
  if (total_hit == 0)
    ratio=0;
  else
    ratio = (float)total_hit/(float)total_memory_access;


    //get percentage
    ratio *= 100;
    if (total_hit== 0) ratio =0;

    //printf("Hit/Access: %.2f/%.2f\n",(float)total_hit,(float)total_memory_access);
    printf("Hit ratio : %.2f%\n",ratio);
}

//print the content of cache table
void write_cache_table(void)
{
  int i,j;
  FILE *ofp;    //output file pointer
  if (stream)
    ofp = fopen("cache.out","w");
  else
    ofp = stdout;

  //print table header
  fprintf(ofp, "%6s|","Lines " );
  for (i=0;i<cache_block_size;i++)
  {
    fprintf(ofp,"%6d|",i);
  }
  fprintf(ofp,"\n");
  for (i=1;i<cache_block_size;i++)
  {
    fprintf(ofp,"-------");
  }
  fprintf(ofp,"\n");

  //loop each cache lines
  for (i=0;i<cache_line;i++)
  {
    fprintf(ofp,"%6d|",i);
    for ( j=0;j<cache_block_size;j++)
    {
      //no content in cache
      if (cache_tag[i] == 0)
        fprintf(ofp,"%6d|",0);
      else
        fprintf(ofp,"%6d|",cache_tag[i]+j);
    }
    fprintf(ofp,"\n");
  }
  if (stream) fclose(ofp);
}

int usage(void)
{
  printf("Please pass a file\n");
  printf("Usage: cachesim <file>\n");
  return - 1;
}


int main(int argc, char *argv[])
{
  FILE *ifp;
  int address_requested=0;  //address requested

  if (argc != 2)
  {
    exit(usage());
  }

  //Read input file from command lines
  ifp = fopen(argv[i],"r");
  if(ifp == NULL)
  {
    printf("ERROR: File %s does not exist\n",argv[i]);
    exit(usage());
  }
}

/*-----------------------------------------------------------
                    START CODE
-------------------------------------------------------------*/

      int i ;
      for (i=0;i<cache_line;i++)
      {
        cache_tag(cache_line) = 0;
      }
      int lastwrote = -1;

      //Read input file line by line and store CPU request
      //in variable 'address_requested'
      while (fscanf(ifp,"%d\n",&address_requested) != EOF)
      {
        int done = 0;

        for ( i=0;i<cache_line;i++)
        {
          if(address_requested >= cache_tag[i] && (address_requested) = cache_tag[i] < cache_block_size)
            {
              total_hit++;
              done = 1;
              break;
            }
        }

        if (done ==0 )
        {
          lastwrote = (++lastwrote)%cache_line;
          cache_tag(lastwrote) = address_requested;
        }
        total_memory_access++;
      }

/*--------------------------------------------------------------------------------
                          END CODE
----------------------------------------------------------------------------------*/

    print_hit_ratio();
    write_cache_table();
    fclose(ifp);



#include "contiki.h"
#include "net/rime.h"
#include "random.h"
#include "sys/node-id.h"
#include "dev/button-sensor.h"

#include "dev/leds.h"
#include "collect-common.h"
#include "collect-view.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
/*---------------------------------------------------------------------------*/
PROCESS(example_broadcast_process, "Broadcast example");
AUTOSTART_PROCESSES(&example_broadcast_process);
/*---------------------------------------------------------------------------*/

typedef uint8_t byte;


static unsigned long long int get_min(unsigned long long int a, unsigned long long int b) {
    return b ^ ((b ^ a) & -(b > a));
}

static void print_bits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j, k=0;

    for (i=4;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            k += 1;
            //if(size==1 && k>4) printf("%d",k);
            printf("%u", byte);
        }
    }
    //puts("");
}


static void print_byte(unsigned long long int* ptr)
{
    if(*ptr == 22620161638 || *ptr == 4563403298)
        print_bits(1, ptr);
    else
        print_bits(0, ptr);
}


/**
  * Given two bytes, computes a byte s.t. for every adjacent 2 bits, the byte has the minimum of the two
  * e.g.: min_consensus(11010011,10001110) = 10000010
  *
  */
static unsigned long long int min_consensus(unsigned long long int a, unsigned long long int b)
{
	unsigned long long int final = 0;

    //print_byte(&a);
    //print_byte(&b);

    byte j = 0;
    for (;j < sizeof(a)*(8/2); j++)
    {
    	unsigned long long int tmp1 = (a >> j*2) & (0xff >> 6);
    	unsigned long long int tmp2 = (b >> j*2) & (0xff >> 6);
    	unsigned long long int m = get_min(tmp1,tmp2);

    	final = final + (m << 2*j);
    }

    return final;

    // print_byte(&final);
}


/* These hold the broadcast and unicast structures, respectively. */
static struct broadcast_conn broadcast;

static void
broadcast_recv(struct broadcast_conn *c, const rimeaddr_t *from)
{
    printf("broadcast message received from %d.%d: '%s' , MAC 2^(4*10)\n",
         from->u8[0], from->u8[1], (char *)packetbuf_dataptr());
  
    int a,b;
    //Good Node MIN Bad node
    for(a=1;a<301;a++){
        for(b=301;b<401;b++){
            if((node_id == a && from->u8[0] == b) || (node_id == b && from->u8[0] == a)){
            printf("Min Value : 00010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100001000000000000001000010\n");
            }
        }
    }

    //Good Node MIN Good node
    for(a=1;a<301;a++){
        for(b=1;b<301;b++){
            if(node_id == a && from->u8[0] == b){
            printf("Min Value : 01010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000110011001100110011001100110011001100110\n");
            }
        }
    } 

    //Bad Node MIN Bad node
    for(a=301;a<401;a++){
        for(b=301;b<401;b++){
            if(node_id == a && from->u8[0] == b){
            printf("Min Value : 00010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100010001000100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000100001000010000100001000010000100001000010\n");
            }
        }
    }  
}
static const struct broadcast_callbacks broadcast_call = {broadcast_recv};

/*---------------------------------------------------------------------------*/
PROCESS_THREAD(example_broadcast_process, ev, data)
{
  static struct etimer et;

  PROCESS_EXITHANDLER(broadcast_close(&broadcast);)

  PROCESS_BEGIN();

  broadcast_open(&broadcast, 129, &broadcast_call);


  while(1) {

    /* Delay 2-4 seconds */
    etimer_set(&et, CLOCK_SECOND * 4 + random_rand() % (CLOCK_SECOND * 4));

    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));
    
    int a;
    //Setting message content for Good nodes
    for(a=1;a<301;a++){
        if(node_id == a){
            packetbuf_copyfrom("2.2226714776266 X (10)^240", 27);
        }
    }
    
    //Setting message content for Bad nodes
    for(a=301;a<401;a++){
        if(node_id == a){
            packetbuf_copyfrom("8.8906859105064 X (10)^239", 27);
        }
    }


    broadcast_send(&broadcast);
    printf("broadcast message sent\n");
  }

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/



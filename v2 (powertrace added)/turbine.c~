#include "contiki.h"
#include "net/rime.h"
#include "sys/node-id.h"

#include "dev/button-sensor.h"
#include "dev/leds.h"
#include "powertrace.c"
#include "collect-view.h"

#include "params.h"


/*---------------------------------------------------------------------------*/
PROCESS(temperature_process, "Temperature unicast");
AUTOSTART_PROCESSES(&temperature_process);
/*---------------------------------------------------------------------------*/
int bld1, bld2, bld3, vib;
int flag;

static void
recv_uc(struct unicast_conn *c, const rimeaddr_t *from)
{
    char *sd = (char *)packetbuf_dataptr();
    int val;
    
    if ((from->u8[0]==blade1 || from->u8[0]==blade2 || from->u8[0]==blade3) && flag!=1){
        printf("Blade%d Temperature: %s degree celsius\n", from->u8[0], (char *)packetbuf_dataptr());
        
        val = atoi(sd);
        if(val >= blade_alarm){
            	printf("Temperature of blade%d reached %s degree celsius. Alarm Raised.\n", from->u8[0],(char *)packetbuf_dataptr());

		if(val >= blade_shutdown){
		    printf("Temperature of blade%d reached %s degree celsius. Central node Shutting Down.\n", from->u8[0],(char *)packetbuf_dataptr());
		    flag=1;
		}
        }
    }

    if (from->u8[0]==vibration && flag!=1){
        printf("Vibration at %d Node: %s um\n", from->u8[0], (char *)packetbuf_dataptr());
        
    }

}

static const struct unicast_callbacks unicast_callbacks = {recv_uc};
static struct unicast_conn uc;
/*---------------------------------------------------------------------------*/
PROCESS_THREAD(temperature_process, ev, data)
{
  PROCESS_EXITHANDLER(unicast_close(&uc);)
    
  PROCESS_BEGIN();

  unicast_open(&uc, 146, &unicast_callbacks);

  while(1) {
    static struct etimer et;
    rimeaddr_t addr;

    //Creating delay
    etimer_set(&et, CLOCK_SECOND * delay);
    PROCESS_WAIT_EVENT_UNTIL(etimer_expired(&et));

    //Setting receiver to Central node
    addr.u8[0] = central_node;
    addr.u8[1] = 0;

    //Adding Powertrace module
    powertrace_start(CLOCK_SECOND * 10);
    
    //Sending blade1 into to central node
    if(node_id == blade1) {
        char buffer[6];
	itoa(bladeOne[bld1++],buffer,10);
        const void *message= buffer;
        packetbuf_copyfrom(message, 3);
        unicast_send(&uc, &addr);
    }

    //Sending blade2 into to central node
    if(node_id == blade2) {
        char buffer[6];
	itoa(bladeTwo[bld2++],buffer,10);
        const void *message= buffer;
        packetbuf_copyfrom(message, 3);
        unicast_send(&uc, &addr);
    }

    //Sending blade3 into to central node
    if(node_id == blade3) {
        char buffer[6];
	itoa(bladeThree[bld3++],buffer,10);
        const void *message= buffer;
        packetbuf_copyfrom(message, 3);
        unicast_send(&uc, &addr);
    }

   

    //Sending Vibration into to central node
    if(node_id == vibration) {
        char buffer[6];
	itoa(vibrate[vib++],buffer,10);
        const void *message= buffer;
        packetbuf_copyfrom(message, 3);
        unicast_send(&uc, &addr);
    }	
  }

  PROCESS_END();
}
/*---------------------------------------------------------------------------*/

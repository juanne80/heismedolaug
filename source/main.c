#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "driver/safety.h"
#include "driver/start_up.h"
#include "driver/orders.h"






int main(){
    elevio_init();
    
    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");
   

    // setter variabler (extern ints i start_up.h), oppstartsfase
    oppstart = 0; 
    bytt = 1;
    last_floor = 0;
    reset_lists();
    start_up_fase();
    has_been_pressed = 0;
    dir = 1; //1 = opp, 0 = ned

    while(1){
        int floor = elevio_floorSensor();

        //logikk for stoppknapp
        stop_elevator(&has_been_pressed);

        //legge til bestillinger inne/ute i lister
        add_orders();
      
        
        floor = elevio_floorSensor();
        
        if (floor != -1){
            last_floor = floor;
        }
        

        //Logikk for retning heisen skal kjøre
        direction_logic();
       
        //oppdaterer etasjevariabelen
        floor = elevio_floorSensor();
        
        //stopper i etasjen hvis den ligger i bestillingslisten vi følger, kjører så til neste etasje i listen
        deliver_orders(); 
       
        //lukker alltid døren hvis den er åpen, så lenge det ikke er obstruksjon
        close_door();



        
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL);
    }

    return 0;
}


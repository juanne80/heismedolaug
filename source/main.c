#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/orders.h"
#include "driver/elevio.h"
#include "driver/set_up.h"
#include "driver/safety.h"



int vent = 0; //hvis vi skal vente = 1, ellers = 0

int main(){
    elevio_init();
    
    printf("=== Example Program ===\n");
    printf("Press the stop button on the elevator panel to exit\n");

    //Oppstartsfase START--------------------------------------------------------------
    nullstill_lister();
    go_to_start_pos();
    vent = 1;
    //Oppstartsfase SLUTT--------------------------------------------------------------
   
    while(1){
        stop_elevator(); //logikk for stopp-knapp
        update_orders();
        print_lister();
        if(elevio_callButton(2,0)){ //opp fra 3. etasje (e)
            vent = 0;
            elevio_motorDirection(DIRN_UP);
        } 
        int floor = elevio_floorSensor();
        //elevio_floorIndicator(floor);
       
        if(elevio_floorSensor()==0 && vent==0){
            elevio_motorDirection(DIRN_UP);
        }
        if(elevio_floorSensor()==ant_etasjer-1 && vent==0){
            elevio_motorDirection(DIRN_DOWN);

        }

        for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                elevio_buttonLamp(f, b, btnPressed);
            }
        }

      

        
    
        nanosleep(&(struct timespec){0, 10 * 1000 * 1000}, NULL);

    }

    return 0;
}

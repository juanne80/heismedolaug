#include "safety.h"
#include "elevio.h"
#include "set_up.h"
#include "orders.h"

#include <stdio.h>
#include <time.h>


void close_door(){
    if(elevio_floorSensor() != -1){
    nanosleep(&(struct timespec){3, 0}, NULL);
    elevio_doorOpenLamp(0); 
    }
}

void stop_elevator(){
   while(elevio_stopButton()==1){
    elevio_motorDirection(DIRN_STOP);
    elevio_stopLamp(1);
    if(elevio_floorSensor()!=-1){
        elevio_doorOpenLamp(1);
    }
   }
   elevio_stopLamp(0);
   if(elevio_floorSensor()!=-1){
    close_door();
    }
}


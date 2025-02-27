#include "set_up.h"
#include "elevio.h"
#include "safety.h"
#include "orders.h"

#include <stdio.h>
#include <time.h>

//definere lister
int Bestillingsliste_Opp[4];
int Bestillingsliste_Ned[4];

//definere variabler
int ant_etasjer = 4;

//definere funksjoner
void nullstill_lister(){
    for(int i = 0; i<ant_etasjer;i++){
        Bestillingsliste_Opp[i]=5;
        Bestillingsliste_Ned[i]=5;
    }
}

void print_lister(){
    printf("Opp:  %d  %d  %d  %d\n", Bestillingsliste_Opp[0], Bestillingsliste_Opp[1], Bestillingsliste_Opp[2], Bestillingsliste_Opp[3]);
    printf("Ned:  %d  %d  %d  %d\n", Bestillingsliste_Ned[0], Bestillingsliste_Ned[1], Bestillingsliste_Ned[2], Bestillingsliste_Ned[3]);
    printf("\n");

}

void go_to_start_pos(){
    while (elevio_floorSensor() != 0) {  
        elevio_motorDirection(DIRN_DOWN);
        nanosleep(&(struct timespec){0, 100 * 1000 * 1000}, NULL); // 100ms pause for å unngå CPU-overbelastning
    }

    // Når vi er i første etasje, stopp motoren
    elevio_motorDirection(DIRN_STOP);
}
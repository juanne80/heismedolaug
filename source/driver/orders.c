#include "safety.h"
#include "elevio.h"
#include "set_up.h"
#include "orders.h"
#include <stdio.h>
#include <time.h>

void update_orders(){
if (elevio_callButton(0, 0)){
    Bestillingsliste_Opp[0] = 0;
}
if (elevio_callButton(1, 0)){
    Bestillingsliste_Opp[1] = 1;

}
if (elevio_callButton(1, 1)){
    Bestillingsliste_Ned[1] = 1;


}
if (elevio_callButton(2, 0)){
    Bestillingsliste_Opp[2] = 2;

}
if (elevio_callButton(2, 1)){
    Bestillingsliste_Ned[2] = 2;

    

}
if (elevio_callButton(3, 1)){
    Bestillingsliste_Ned[3] = 3;    
}
}
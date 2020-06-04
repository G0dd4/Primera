#include "SRC/DRV8825.h"
#include "SRC/interface.h"
          

#define pinEN PI_3
#define pinDIR PI_0
#define pinSTEP PH_6

//copy download

int main(){
    initWindow();
    DRV8825 drv8825(pinEN,pinDIR,pinSTEP);
    
    while(1){
        drv8825.setEnable(START);
        drv8825.setDir(STOP);
        drv8825.move(1);  
    }


}
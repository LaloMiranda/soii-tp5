#include "../include/serverFuncs.h"

int main(void){
    struct _u_instance instance;
    
    //Inicializo la API
    initInstance(&instance);
    printf("Instancia inicializada\n");

    //Cargo los endpoints
    addEndPoints(&instance);
    printf("Endpoints agregados\n");

    //Arranco la API
    startAPI(&instance);

    //Cierro la API
    eraseInstance(&instance);
    printf("API cerrada\n");

    return 0;
}

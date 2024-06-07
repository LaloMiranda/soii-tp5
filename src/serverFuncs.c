#include "../include/serverFuncs.h"

int counter;

void initInstance(struct _u_instance *instance){
    if (ulfius_init_instance(instance, PORT, NULL, NULL) != U_OK)
    {
        fprintf(stderr, "Error ulfius_init_instance, abort\n");
        exit(EXIT_FAILURE);
    }
}

void eraseInstance(struct _u_instance *instance){
    ulfius_stop_framework(instance);
    ulfius_clean_instance(instance);
}

void addEndPoints(struct _u_instance *instance){
    ulfius_add_endpoint_by_val(instance, "POST", URL_INC, NULL, 0, &incCounter, NULL);
    ulfius_add_endpoint_by_val(instance, "GET", URL_PRINT, NULL, 0, &getCounter, NULL);
    ulfius_add_endpoint_by_val(instance, "POST", URL_RESET, NULL, 0, &resetCounter, NULL);
    ulfius_set_default_endpoint(instance, &defaultPage, NULL);
}

void startAPI(struct _u_instance *instance){
    if (ulfius_start_framework(instance) == U_OK){
        printf("RestAPI iniciada en el puerto: %d\n", instance->port);

        getchar();
    }
    else{
        fprintf(stderr, "Error al inicializar el frameworkk\n");
    }
}

int defaultPage(const struct _u_request *request, struct _u_response *response, void *user_data){
    (void)request;
    (void)user_data;
    ulfius_set_string_body_response(response, 404, "Page not found, try http://[Server IP]:8537/increment or http://[Server IP]:8537/imprimir\n");
    return U_CALLBACK_CONTINUE;
}

int incCounter(const struct _u_request *request, struct _u_response *response, void *user_data){
    (void)user_data;
    (void)request;
    (void)response;
    
    counter ++;

    return U_CALLBACK_CONTINUE;
}

int getCounter(const struct _u_request *request, struct _u_response *response, void *user_data){
    (void)user_data;
    (void)request;

    char message[100];
    json_t* js;
    sprintf(message, "Valor en el contador: %i", counter);
    js = json_pack("{s:s}", "GET:", message);

    ulfius_set_json_body_response(response, 409, js);
    return U_CALLBACK_CONTINUE;

}

int resetCounter(const struct _u_request *request, struct _u_response *response, void *user_data){
    (void)user_data;
    (void)request;
    (void)response;
    
    counter = 0;

    return U_CALLBACK_CONTINUE;
}
#ifndef _SERVERFUNCS_
#define _SERVERFUNCS_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ulfius.h>


#define PORT 8537
#define URL_PRINT   "/imprimir"
#define URL_INC     "/increment"
#define URL_RESET   "/reset"

int counter;

void initInstance(struct _u_instance *instance);
void eraseInstance(struct _u_instance *instance);
void addEndPoints(struct _u_instance *instance);
void startAPI(struct _u_instance *instance);


int defaultPage(const struct _u_request *request, struct _u_response *response, void *user_data);
int incCounter(const struct _u_request *request, struct _u_response *response, void *user_data);
int getCounter(const struct _u_request *request, struct _u_response *response, void *user_data);
int resetCounter(const struct _u_request *request, struct _u_response *response, void *user_data);

#endif
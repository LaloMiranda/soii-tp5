#ifndef _SERVERFUNCS_
#define _SERVERFUNCS_

#include <stdio.h>
#include <stdlib.h>

#include <ulfius.h>


#define PORT 8537
#define URL_PRINT "/test"

void initInstance(struct _u_instance *instance);
void eraseInstance(struct _u_instance *instance);
void addEndPoints(struct _u_instance *instance);
void startAPI(struct _u_instance *instance);


int defaultPage(const struct _u_request *request, struct _u_response *response, void *user_data);
int testPage(const struct _u_request *request, struct _u_response *response, void *user_data);

#endif
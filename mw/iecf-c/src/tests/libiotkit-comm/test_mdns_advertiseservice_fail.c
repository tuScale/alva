/*
 * MDNS through iotkit-comm API
 * Copyright (c) 2014, Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU Lesser General Public License,
 * version 2.1, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 */

/** @file test_mdns_advertiseservice_fail.c

*/

#include <stdio.h>
#include <zmq.h>
#include <zmq_utils.h>
#include "../../lib/libiotkit-comm/iotkit-comm.h"


int main(void) {
    ServiceSpec *serviceSpec = (ServiceSpec *) parseServiceSpec("./invalidtemperatureServiceZMQPUBSUB.json");
    if (serviceSpec) {
        printf("Waiting for the Service to Advertise\n");
        if (advertiseService(serviceSpec)) {
             puts("Success: Service Advertised");
             exit(EXIT_FAILURE);
        } else {
             puts("Failed: Service Advertise");
             exit(EXIT_SUCCESS);
        }
    }
    return 0;
}

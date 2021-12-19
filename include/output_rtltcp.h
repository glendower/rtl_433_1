/** @file
    rtl_tcp output for rtl_433 raw data.

    Copyright (C) 2021 Christian Zuckschwerdt

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
*/

#ifndef INCLUDE_OUTPUT_RTLTCP_H_
#define INCLUDE_OUTPUT_RTLTCP_H_

#include <stdint.h>

// generic raw output

struct raw_output;

typedef struct raw_output {
    void (*output_frame)(struct raw_output *output, uint8_t const *data, uint32_t len);
    void (*output_free)(struct raw_output *output);
} raw_output_t;

void raw_output_frame(struct raw_output *output, uint8_t const *data, uint32_t len);

void raw_output_free(struct raw_output *output);

// actual output

struct r_cfg;

/** Construct rtl_tcp data output.

    @param host the server host to bind
    @param port the server port to bind
    @param cfg the r_api config to use
    @return The initialized rtltcp output instance.
            You must release this object with raw_output_free once you're done with it.
*/
struct raw_output *raw_output_rtltcp_create(char const *host, char const *port, struct r_cfg *cfg);

#endif /* INCLUDE_OUTPUT_RTLTCP_H_ */

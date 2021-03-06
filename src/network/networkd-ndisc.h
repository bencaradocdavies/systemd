/* SPDX-License-Identifier: LGPL-2.1+ */
#pragma once

/***
  This file is part of systemd.

  Copyright 2013 Tom Gundersen <teg@jklm.no>
***/

#include "networkd-link.h"

typedef struct NDiscRDNSS {
        usec_t valid_until;
        struct in6_addr address;
} NDiscRDNSS;

typedef struct NDiscDNSSL {
        usec_t valid_until;
        /* The domain name follows immediately. */
} NDiscDNSSL;

static inline char* NDISC_DNSSL_DOMAIN(const NDiscDNSSL *n) {
        return ((char*) n) + ALIGN(sizeof(NDiscDNSSL));
}

int ndisc_configure(Link *link);
void ndisc_vacuum(Link *link);
void ndisc_flush(Link *link);

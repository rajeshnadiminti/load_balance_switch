
#ifndef PATH_RESOLVER_H
#define PATH_RESOLVER_H


#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include "libtopology.h"
#include "hash_table.h"
#include "doubly_linked_list.h"


typedef struct {
  hash_table *topology_table;
  hash_table *node_table;
  hash_table *link_stats_table;
} path_resolver;


typedef struct {
  uint64_t dpid;
  uint16_t in_port_no;
  uint16_t out_port_no;
} path_resolver_hop;


dlist_element *resolve_path( path_resolver *table, uint64_t in_dpid, uint16_t in_port,
                             uint64_t out_dpid, uint16_t out_port );
void free_hop_list( dlist_element *hops );
path_resolver *create_path_resolver( void );
bool delete_path_resolver( path_resolver *table );
void update_topology( path_resolver *table, const topology_link_status *s );


#endif	// PATH_RESOLVER_H



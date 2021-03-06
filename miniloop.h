/*******************************************************************************
*
* Header file generated by RDP on Oct 11 2010 13:08:26 from miniloop.bnf
*
*******************************************************************************/
#ifndef MINILOOP_H
#define MINILOOP_H

#include "arg.h"
#include "graph.h"
#include "hist.h"
#include "memalloc.h"
#include "scan.h"
#include "set.h"
#include "symbol.h"
#include "textio.h"


/* Maximum number of passes */
#define RDP_PASSES 1

/* Time and date stamp */
#define RDP_STAMP "Generated on Oct 11 2010 13:08:26 and compiled on " __DATE__ " at " __TIME__ 

/* Token enumeration */
enum
{
RDP_TT_BOTTOM = SCAN_P_TOP,
RDP_T_33 /* ! */ = SCAN_P_TOP,RDP_T_3361 /* != */,RDP_T_34 /* " */,RDP_T_40 /* ( */,RDP_T_4042 /* (* */,RDP_T_41 /* ) */,RDP_T_42 /* * */,RDP_T_4242 /* ** */,
RDP_T_43 /* + */,RDP_T_44 /* , */,RDP_T_45 /* - */,RDP_T_47 /* / */,RDP_T_59 /* ; */,RDP_T_60 /* < */,RDP_T_6061 /* <= */,RDP_T_61 /* = */,
RDP_T_6161 /* == */,RDP_T_62 /* > */,RDP_T_6261 /* >= */,RDP_T_begin,RDP_T_do,RDP_T_else,RDP_T_end,RDP_T_if,
RDP_T_int,RDP_T_print,RDP_T_then,RDP_T_while,
RDP_TT_TOP
};

/* Tree data types */

typedef struct rdp_tree_node_data_struct
{
  SCAN_DATA
  
} rdp_tree_node_data;
typedef struct rdp_tree_edge_data_struct
{
  int rdp_edge_kind;
  
} rdp_tree_edge_data;

/* Symbol table support */
typedef struct mini_data_node
{
 char* id; 
} mini_data;
extern void * mini;
extern mini_data * mini_temp;
#define mini_cast(x) ((mini_data *)x)

/* Parser start production */
void program(rdp_tree_node_data* rdp_tree);



#endif

/* End of miniloop.h */

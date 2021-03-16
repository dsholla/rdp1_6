/*******************************************************************************
*
* Header file generated by RDP on Sep 13 2004 14:37:28 from rdp.bnf
*
*******************************************************************************/
#ifndef RDP_H
#define RDP_H

#include "arg.h"
#include "graph.h"
#include "hist.h"
#include "memalloc.h"
#include "scan.h"
#include "set.h"
#include "symbol.h"
#include "textio.h"


/* Maximum number of passes */
#define RDP_PASSES 2

/* Time and date stamp */
#define RDP_STAMP "Generated on Sep 13 2004 14:37:28 and compiled on " __DATE__ " at " __TIME__ 

/* Token enumeration */
enum
{
RDP_TT_BOTTOM = SCAN_P_TOP,
RDP_T_34 /* " */ = SCAN_P_TOP,RDP_T_35 /* # */,RDP_T_39 /* ' */,RDP_T_40 /* ( */,RDP_T_4042 /* (* */,RDP_T_41 /* ) */,RDP_T_42 /* * */,RDP_T_46 /* . */,
RDP_T_58 /* : */,RDP_T_5858 /* :: */,RDP_T_585861 /* ::= */,RDP_T_60 /* < */,RDP_T_62 /* > */,RDP_T_64 /* @ */,RDP_T_ALT_ID,RDP_T_ANNOTATED_EPSILON_TREE,
RDP_T_ARG_BLANK,RDP_T_ARG_BOOLEAN,RDP_T_ARG_NUMERIC,RDP_T_ARG_STRING,RDP_T_CASE_INSENSITIVE,RDP_T_CHAR,RDP_T_CHAR_ESC,RDP_T_COMMENT,
RDP_T_COMMENT_LINE,RDP_T_COMMENT_LINE_VISIBLE,RDP_T_COMMENT_NEST,RDP_T_COMMENT_NEST_VISIBLE,RDP_T_COMMENT_VISIBLE,RDP_T_DERIVATION_TREE,RDP_T_EPSILON_TREE,RDP_T_GLOBAL,
RDP_T_HASH_PRIME,RDP_T_HASH_SIZE,RDP_T_INCLUDE,RDP_T_INTERPRETER,RDP_T_MAX_ERRORS,RDP_T_MAX_WARNINGS,RDP_T_MULTIPLE_SOURCE_FILES,RDP_T_NEW_ID,
RDP_T_NUMBER,RDP_T_OPTION,RDP_T_OUTPUT_FILE,RDP_T_PARSER,RDP_T_PASSES,RDP_T_POST_PARSE,RDP_T_POST_PROCESS,RDP_T_PRE_PARSE,
RDP_T_PRE_PROCESS,RDP_T_RETAIN_COMMENTS,RDP_T_SET_SIZE,RDP_T_SHOW_SKIPS,RDP_T_STRING,RDP_T_STRING_ESC,RDP_T_SUFFIX,RDP_T_SUPPRESS_BUILT_IN_ARGUMENTS,
RDP_T_SYMBOL_TABLE,RDP_T_TAB_WIDTH,RDP_T_TEXT_SIZE,RDP_T_TITLE,RDP_T_TREE,RDP_T_USES,RDP_T_91 /* [ */,RDP_T_9142 /* [* */,
RDP_T_93 /* ] */,RDP_T_94 /* ^ */,RDP_T_9494 /* ^^ */,RDP_T_949494 /* ^^^ */,RDP_T_9495 /* ^_ */,RDP_T_123 /* { */,RDP_T_124 /* | */,RDP_T_125 /* } */,
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
typedef struct locals_data_node
{
 char *id; 
} locals_data;
extern void * locals;
extern locals_data * locals_temp;
#define locals_cast(x) ((locals_data *)x)

typedef struct codes_data_node
{
  RDP_DATA
} codes_data;
extern void * codes;
extern codes_data * codes_temp;
#define codes_cast(x) ((codes_data *)x)

typedef struct tokens_data_node
{
  RDP_DATA
} tokens_data;
extern void * tokens;
extern tokens_data * tokens_temp;
#define tokens_cast(x) ((tokens_data *)x)

typedef struct rdp_data_node
{
  RDP_DATA
} rdp_data;
extern void * rdp;
extern rdp_data * rdp_temp;
#define rdp_cast(x) ((rdp_data *)x)

/* Parser start production */
void unit(rdp_tree_node_data* rdp_tree);



#endif

/* End of rdp.h */

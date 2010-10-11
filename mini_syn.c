/*******************************************************************************
*
* Parser generated by RDP on Oct 11 2010 13:08:25 from mini_syn.bnf
*
*******************************************************************************/
#include <time.h>
#include "mini_syn.h"

char
  *rdp_sourcefilename,          /* current source file name */
  **rdp_sourcefilenames,        /* array of source file names */
  *rdp_outputfilename = "mini_syn.out";         /* output file name */

int
  rdp_symbol_echo = 0,                 /* symbol echo flag */
  rdp_verbose = 0,                     /* verbosity flag */
  rdp_sourcefilenumber,                /* Source file counter */
  rdp_pass;                            /* pass number */

int rdp_error_return = 0;              /* return value for main routine */

char *rdp_tokens = "IGNORE\0" 
"ID\0" "INTEGER\0" "REAL\0" "CHAR\0" "CHAR_ESC\0" "STRING\0" "STRING_ESC\0" "COMMENT\0" 
"COMMENT_VISIBLE\0" "COMMENT_NEST\0" "COMMENT_NEST_VISIBLE\0" "COMMENT_LINE\0" "COMMENT_LINE_VISIBLE\0" "EOF\0" "EOLN\0" "'\"'\0" 
"'('\0" "'(*'\0" "')'\0" "'*'\0" "'**'\0" "'+'\0" "','\0" "'-'\0" 
"'/'\0" "';'\0" "'='\0" "'int'\0" "'print'\0" ;


/* Load keywords */
static void rdp_load_keywords(void)
{
  scan_load_keyword("\"", "\\", RDP_T_34 /* " */, SCAN_P_STRING_ESC);
  scan_load_keyword("(", NULL, RDP_T_40 /* ( */, SCAN_P_IGNORE);
  scan_load_keyword("(*", "*)", RDP_T_4042 /* (* */, SCAN_P_COMMENT_NEST);
  scan_load_keyword(")", NULL, RDP_T_41 /* ) */, SCAN_P_IGNORE);
  scan_load_keyword("*", NULL, RDP_T_42 /* * */, SCAN_P_IGNORE);
  scan_load_keyword("**", NULL, RDP_T_4242 /* ** */, SCAN_P_IGNORE);
  scan_load_keyword("+", NULL, RDP_T_43 /* + */, SCAN_P_IGNORE);
  scan_load_keyword(",", NULL, RDP_T_44 /* , */, SCAN_P_IGNORE);
  scan_load_keyword("-", NULL, RDP_T_45 /* - */, SCAN_P_IGNORE);
  scan_load_keyword("/", NULL, RDP_T_47 /* / */, SCAN_P_IGNORE);
  scan_load_keyword(";", NULL, RDP_T_59 /* ; */, SCAN_P_IGNORE);
  scan_load_keyword("=", NULL, RDP_T_61 /* = */, SCAN_P_IGNORE);
  scan_load_keyword("int", NULL, RDP_T_int, SCAN_P_IGNORE);
  scan_load_keyword("print", NULL, RDP_T_print, SCAN_P_IGNORE);
}

/* Set declarations */

  set_ String_stop = SET_NULL;
  set_ comment_stop = SET_NULL;
  set_ e1_first = SET_NULL;
  set_ e1_stop = SET_NULL;
  set_ e2_first = SET_NULL;
  set_ e2_stop = SET_NULL;
  set_ e3_first = SET_NULL;
  set_ e3_stop = SET_NULL;
  set_ e4_first = SET_NULL;
  set_ e4_stop = SET_NULL;
  set_ e5_first = SET_NULL;
  set_ e5_stop = SET_NULL;
  set_ program_first = SET_NULL;
  set_ program_stop = SET_NULL;
  set_ rdp_e1_2_first = SET_NULL;
  set_ rdp_e1_3_first = SET_NULL;
  set_ rdp_e2_2_first = SET_NULL;
  set_ rdp_e2_3_first = SET_NULL;
  set_ rdp_e3_0_first = SET_NULL;
  set_ rdp_e4_2_first = SET_NULL;
  set_ rdp_program_1_first = SET_NULL;
  set_ rdp_program_2_first = SET_NULL;
  set_ rdp_program_3_first = SET_NULL;
  set_ rdp_program_4_first = SET_NULL;
  set_ rdp_program_5_first = SET_NULL;
  set_ rdp_statement_1_first = SET_NULL;
  set_ rdp_statement_3_first = SET_NULL;
  set_ statement_first = SET_NULL;
  set_ statement_stop = SET_NULL;
  set_ var_dec_stop = SET_NULL;

/* Initialise sets */

static void rdp_set_initialise(void)
{
  set_assign_list(&String_stop, SCAN_P_EOF, RDP_T_41 /* ) */, RDP_T_44 /* , */,SET_END);
  set_assign_list(&comment_stop, SCAN_P_EOF,SET_END);
  set_assign_list(&e1_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_40 /* ( */, RDP_T_43 /* + */, RDP_T_45 /* - */, SET_END);
  set_assign_list(&e1_stop, SCAN_P_EOF, RDP_T_41 /* ) */, RDP_T_44 /* , */, RDP_T_59 /* ; */,SET_END);
  set_assign_list(&e2_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_40 /* ( */, RDP_T_43 /* + */, RDP_T_45 /* - */, SET_END);
  set_assign_list(&e2_stop, SCAN_P_EOF, RDP_T_41 /* ) */, RDP_T_43 /* + */, RDP_T_44 /* , */, RDP_T_45 /* - */, 
RDP_T_59 /* ; */,SET_END);
  set_assign_list(&e3_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_40 /* ( */, RDP_T_43 /* + */, RDP_T_45 /* - */, SET_END);
  set_assign_list(&e3_stop, SCAN_P_EOF, RDP_T_41 /* ) */, RDP_T_42 /* * */, RDP_T_43 /* + */, RDP_T_44 /* , */, 
RDP_T_45 /* - */, RDP_T_47 /* / */, RDP_T_59 /* ; */,SET_END);
  set_assign_list(&e4_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_40 /* ( */, SET_END);
  set_assign_list(&e4_stop, SCAN_P_EOF, RDP_T_41 /* ) */, RDP_T_42 /* * */, RDP_T_43 /* + */, RDP_T_44 /* , */, 
RDP_T_45 /* - */, RDP_T_47 /* / */, RDP_T_59 /* ; */,SET_END);
  set_assign_list(&e5_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_40 /* ( */, SET_END);
  set_assign_list(&e5_stop, SCAN_P_EOF, RDP_T_41 /* ) */, RDP_T_42 /* * */, RDP_T_4242 /* ** */, RDP_T_43 /* + */, 
RDP_T_44 /* , */, RDP_T_45 /* - */, RDP_T_47 /* / */, RDP_T_59 /* ; */,SET_END);
  set_assign_list(&program_first, SCAN_P_ID, RDP_T_59 /* ; */, RDP_T_int, RDP_T_print, SET_END);
  set_assign_list(&program_stop, SCAN_P_EOF,SET_END);
  set_assign_list(&rdp_e1_2_first, RDP_T_43 /* + */, RDP_T_45 /* - */, SET_END);
  set_assign_list(&rdp_e1_3_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_40 /* ( */, RDP_T_43 /* + */, RDP_T_45 /* - */, SET_END);
  set_assign_list(&rdp_e2_2_first, RDP_T_42 /* * */, RDP_T_47 /* / */, SET_END);
  set_assign_list(&rdp_e2_3_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_40 /* ( */, RDP_T_43 /* + */, RDP_T_45 /* - */, SET_END);
  set_assign_list(&rdp_e3_0_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_40 /* ( */, SET_END);
  set_assign_list(&rdp_e4_2_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_40 /* ( */, SET_END);
  set_assign_list(&rdp_program_1_first, SCAN_P_ID, RDP_T_print, SET_END);
  set_assign_list(&rdp_program_2_first, SCAN_P_ID, RDP_T_int, RDP_T_print, SET_END);
  set_assign_list(&rdp_program_3_first, SCAN_P_ID, RDP_T_59 /* ; */, RDP_T_int, RDP_T_print, SET_END);
  set_assign_list(&rdp_program_4_first, SCAN_P_ID, RDP_T_59 /* ; */, RDP_T_int, RDP_T_print, SET_END);
  set_assign_list(&rdp_program_5_first, SCAN_P_ID, RDP_T_59 /* ; */, RDP_T_int, RDP_T_print, SET_END);
  set_assign_list(&rdp_statement_1_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_40 /* ( */, RDP_T_43 /* + */, RDP_T_45 /* - */, SET_END);
  set_assign_list(&rdp_statement_3_first, SCAN_P_ID, SCAN_P_INTEGER, RDP_T_34 /* " */, RDP_T_40 /* ( */, RDP_T_43 /* + */, 
RDP_T_45 /* - */, SET_END);
  set_assign_list(&statement_first, SCAN_P_ID, RDP_T_print, SET_END);
  set_assign_list(&statement_stop, SCAN_P_EOF, RDP_T_59 /* ; */,SET_END);
  set_assign_list(&var_dec_stop, SCAN_P_EOF, RDP_T_59 /* ; */,SET_END);
}

/* Parser forward declarations and macros */
static void String(void);
static void e1(void);
static void e2(void);
static void e3(void);
static void e4(void);
static void e5(void);
void program(void);
static void statement(void);
static void var_dec(void);

/* Parser functions */
static void String(void)
{
  {
    scan_test(NULL, RDP_T_34 /* " */, &String_stop);
    scan_();
    scan_test_set(NULL, &String_stop, &String_stop);
   }
}

static void e1(void)
{
  {
    e2();
    if (scan_test_set(NULL, &rdp_e1_2_first, NULL))
    { /* Start of rdp_e1_2 */
      while (1)
      {
        {
          if (scan_test(NULL, RDP_T_43 /* + */, NULL))
          {
            scan_test(NULL, RDP_T_43 /* + */, &e1_stop);
            scan_();
            e2();
          }
          else
          if (scan_test(NULL, RDP_T_45 /* - */, NULL))
          {
            scan_test(NULL, RDP_T_45 /* - */, &e1_stop);
            scan_();
            e2();
          }
          else
            scan_test_set(NULL, &rdp_e1_2_first, &e1_stop)          ;
          }
        if (!scan_test_set(NULL, &rdp_e1_2_first, NULL)) break;
      }
    } /* end of rdp_e1_2 */
    scan_test_set(NULL, &e1_stop, &e1_stop);
   }
}

static void e2(void)
{
  {
    e3();
    if (scan_test_set(NULL, &rdp_e2_2_first, NULL))
    { /* Start of rdp_e2_2 */
      while (1)
      {
        {
          if (scan_test(NULL, RDP_T_42 /* * */, NULL))
          {
            scan_test(NULL, RDP_T_42 /* * */, &e2_stop);
            scan_();
            e3();
          }
          else
          if (scan_test(NULL, RDP_T_47 /* / */, NULL))
          {
            scan_test(NULL, RDP_T_47 /* / */, &e2_stop);
            scan_();
            e3();
          }
          else
            scan_test_set(NULL, &rdp_e2_2_first, &e2_stop)          ;
          }
        if (!scan_test_set(NULL, &rdp_e2_2_first, NULL)) break;
      }
    } /* end of rdp_e2_2 */
    scan_test_set(NULL, &e2_stop, &e2_stop);
   }
}

static void e3(void)
{
  {
    if (scan_test_set(NULL, &rdp_e3_0_first, NULL))
    {
      e4();
    }
    else
    if (scan_test(NULL, RDP_T_43 /* + */, NULL))
    {
      scan_test(NULL, RDP_T_43 /* + */, &e3_stop);
      scan_();
      e3();
    }
    else
    if (scan_test(NULL, RDP_T_45 /* - */, NULL))
    {
      scan_test(NULL, RDP_T_45 /* - */, &e3_stop);
      scan_();
      e3();
    }
    else
      scan_test_set(NULL, &e3_first, &e3_stop)    ;
    scan_test_set(NULL, &e3_stop, &e3_stop);
   }
}

static void e4(void)
{
  {
    e5();
    if (scan_test(NULL, RDP_T_4242 /* ** */, NULL))
    { /* Start of rdp_e4_1 */
      while (1)
      {
        {
          scan_test(NULL, RDP_T_4242 /* ** */, &e4_stop);
          scan_();
          e4();
          }
        break;   /* hi limit is 1! */
      }
    } /* end of rdp_e4_1 */
    scan_test_set(NULL, &e4_stop, &e4_stop);
   }
}

static void e5(void)
{
  {
    if (scan_test(NULL, SCAN_P_ID, NULL))
    {
      scan_test(NULL, SCAN_P_ID, &e5_stop);
      scan_();
    }
    else
    if (scan_test(NULL, SCAN_P_INTEGER, NULL))
    {
      scan_test(NULL, SCAN_P_INTEGER, &e5_stop);
      scan_();
    }
    else
    if (scan_test(NULL, RDP_T_40 /* ( */, NULL))
    {
      scan_test(NULL, RDP_T_40 /* ( */, &e5_stop);
      scan_();
      e1();
      scan_test(NULL, RDP_T_41 /* ) */, &e5_stop);
      scan_();
    }
    else
      scan_test_set(NULL, &e5_first, &e5_stop)    ;
    scan_test_set(NULL, &e5_stop, &e5_stop);
   }
}

void program(void)
{
  {
    if (scan_test_set(NULL, &rdp_program_4_first, NULL))
    { /* Start of rdp_program_4 */
      while (1)
      {
        {
          if (scan_test_set(NULL, &rdp_program_2_first, NULL))
          { /* Start of rdp_program_2 */
            while (1)
            {
              {
                if (scan_test(NULL, RDP_T_int, NULL))
                {
                  var_dec();
                }
                else
                if (scan_test_set(NULL, &rdp_program_1_first, NULL))
                {
                  statement();
                }
                else
                  scan_test_set(NULL, &rdp_program_2_first, &program_stop)                ;
                }
              break;   /* hi limit is 1! */
            }
          } /* end of rdp_program_2 */
          scan_test(NULL, RDP_T_59 /* ; */, &program_stop);
          scan_();
          }
        if (!scan_test_set(NULL, &rdp_program_4_first, NULL)) break;
      }
    } /* end of rdp_program_4 */
    scan_test_set(NULL, &program_stop, &program_stop);
   }
}

static void statement(void)
{
  {
    if (scan_test(NULL, SCAN_P_ID, NULL))
    {
      scan_test(NULL, SCAN_P_ID, &statement_stop);
      scan_();
      scan_test(NULL, RDP_T_61 /* = */, &statement_stop);
      scan_();
      e1();
    }
    else
    if (scan_test(NULL, RDP_T_print, NULL))
    {
      scan_test(NULL, RDP_T_print, &statement_stop);
      scan_();
      scan_test(NULL, RDP_T_40 /* ( */, &statement_stop);
      scan_();
      { /* Start of rdp_statement_3 */
        while (1)
        {
          scan_test_set(NULL, &rdp_statement_3_first, &statement_stop);
          {
            if (scan_test_set(NULL, &rdp_statement_1_first, NULL))
            {
              e1();
            }
            else
            if (scan_test(NULL, RDP_T_34 /* " */, NULL))
            {
              String();
            }
            else
              scan_test_set(NULL, &rdp_statement_3_first, &statement_stop)            ;
            }
          if (SCAN_CAST->token != RDP_T_44 /* , */) break;
          scan_();
        }
      } /* end of rdp_statement_3 */
      scan_test(NULL, RDP_T_41 /* ) */, &statement_stop);
      scan_();
    }
    else
      scan_test_set(NULL, &statement_first, &statement_stop)    ;
    scan_test_set(NULL, &statement_stop, &statement_stop);
   }
}

static void var_dec(void)
{
  {
    scan_test(NULL, RDP_T_int, &var_dec_stop);
    scan_();
    { /* Start of rdp_var_dec_3 */
      while (1)
      {
        scan_test(NULL, SCAN_P_ID, &var_dec_stop);
        {
          scan_test(NULL, SCAN_P_ID, &var_dec_stop);
          scan_();
          if (scan_test(NULL, RDP_T_61 /* = */, NULL))
          { /* Start of rdp_var_dec_1 */
            while (1)
            {
              {
                scan_test(NULL, RDP_T_61 /* = */, &var_dec_stop);
                scan_();
                e1();
                }
              break;   /* hi limit is 1! */
            }
          } /* end of rdp_var_dec_1 */
          }
        if (SCAN_CAST->token != RDP_T_44 /* , */) break;
        scan_();
      }
    } /* end of rdp_var_dec_3 */
    scan_test_set(NULL, &var_dec_stop, &var_dec_stop);
   }
}

int main(int argc, char *argv[])
{
  clock_t rdp_finish_time, rdp_start_time = clock();
  int
    rdp_symbol_statistics = 0,    /* show symbol_ table statistics flag */
    rdp_line_echo_all = 0,        /* make a listing on all passes flag */
    rdp_filter = 0,               /* filter flag */
    rdp_line_echo = 0,            /* make listing flag */

    rdp_lexicalise = 0;            /* print lexicalised output flag */

  unsigned long rdp_textsize = 35000l;   /* size of scanner text array */

  unsigned long rdp_tabwidth = 8l;   /* tab expansion width */

  char* rdp_vcg_filename = NULL;      /* filename for -V option */

  arg_message("Mini_syn V1.50 (c) Adrian Johnstone 1997\n" RDP_STAMP "\n\n""Usage: mini_syn [options] source[.m]");

  arg_message("");
  arg_boolean('f', "Filter mode (read from stdin and write to stdout)", &rdp_filter);
  arg_boolean('l', "Make a listing", &rdp_line_echo);
  arg_boolean('L', "Print lexicalised source file", &rdp_lexicalise);
  arg_string ('o', "Write output to filename", &rdp_outputfilename);
  arg_boolean('s', "Echo each scanner symbol as it is read", &rdp_symbol_echo);
  arg_boolean('S', "Print summary symbol table statistics", &rdp_symbol_statistics);
  arg_numeric('t', "Tab expansion width (default 8)", &rdp_tabwidth);
  arg_numeric('T', "Text buffer size in bytes for scanner (default 20000)", &rdp_textsize);
  arg_boolean('v', "Set verbose mode", &rdp_verbose);
  arg_string ('V', "Write derivation tree to filename in VCG format", &rdp_vcg_filename);

  rdp_sourcefilenames = arg_process(argc, argv);

  /* Fix up filetypes */
  for (rdp_sourcefilenumber = 0; rdp_sourcefilenames[rdp_sourcefilenumber] != NULL; rdp_sourcefilenumber++)
    rdp_sourcefilenames[rdp_sourcefilenumber] = text_default_filetype(rdp_sourcefilenames[rdp_sourcefilenumber], "m");

  if (rdp_filter)
  {
    rdp_sourcefilenames[0] = "-";
    rdp_outputfilename = "-";
    rdp_sourcefilenames[1] = NULL;     /* make sure no further filenames are taken from the array */

  }
  if ((rdp_sourcefilename = rdp_sourcefilenames[0]) == NULL)
     arg_help("no source files specified");

  if (rdp_sourcefilenames[1] != NULL)
    text_message(TEXT_FATAL, "multiple source files not allowed\n");
  text_init(rdp_textsize, 25, 100, (int) rdp_tabwidth);
  scan_init(0, 0, 0, rdp_symbol_echo, rdp_tokens);
  if (rdp_lexicalise)
    scan_lexicalise();
  rdp_set_initialise();
  rdp_load_keywords();
  if (rdp_verbose)
     text_printf("\nMini_syn V1.50 (c) Adrian Johnstone 1997\n" RDP_STAMP "\n\n");
  for (rdp_pass = 1; rdp_pass <= RDP_PASSES; rdp_pass++)
  {
    text_echo(rdp_line_echo_all || (rdp_line_echo && rdp_pass == RDP_PASSES));

    for (rdp_sourcefilenumber = 0; (rdp_sourcefilename = rdp_sourcefilenames[rdp_sourcefilenumber]) != NULL; rdp_sourcefilenumber++)
    {
      if (text_open(rdp_sourcefilename) == NULL)
        arg_help("unable to open source file");

      text_get_char();
      scan_();

      program();            /* call parser at top level */
      if (text_total_errors() != 0)
        text_message(TEXT_FATAL, "error%s detected in source file ''\n", text_total_errors() == 1 ? "" : "s", rdp_sourcefilename);   /* crash quietly */ 
    }
  }

  rdp_sourcefilename = rdp_sourcefilenames[0];     /* Reset filename to first file in the list */

  if (rdp_symbol_statistics)
  {
    symbol_print_all_table_statistics(11);
    symbol_print_all_table();

  }
  text_print_total_errors();
  if (rdp_verbose)
  {
    rdp_finish_time = clock();
    text_message(TEXT_INFO, "%.3f CPU seconds used\n", ((double) (rdp_finish_time-rdp_start_time)) / CLOCKS_PER_SEC);
  }
  return rdp_error_return;
}

/* End of mini_syn.c */
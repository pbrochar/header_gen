#include "header_gen.h"

/* 
** Declarations for argp
*/
const char *argp_program_version = VERSION;
const char *argp_program_bug_address = MAIL;
static char doc[] = DOC;
static char args_doc[] = "source1.c ... sourceN.c header.h";
static struct argp_option options[] = {
	{"count", 'c', 0, 0, "Print the number of prototype create by hgen"},
    {"verbose", 'v', 0, 0, "Print each prototypes create by hgen in std output"},
    {"append", 'a', 0, 0, "Create a new header file with prototype of other header file"},
	{"sort", 's', 0, 0, "Sorts the different protypes in ascii order"},
	{0}
};
static struct argp argp = {options, parse_opt, args_doc, doc};

/* 
** Init structs t_hgen and t_args
** c/p/a_opt A is a state variable allowing to transmit to the program the options
** Argcount is like argc bu tonly for args
** Count is the number of prototype find and put in file, use with 'c' option. 
*/
void init_args_parse(t_hgen *opt, t_args *args, int argc, char **argv)
{
	args->c_opt = 0;
    args->v_opt = 0;
    args->a_opt = 0;
	args->s_opt = 0;
	args->argcount = 0;
    opt->count = 0;
	opt->lst_a_opt = NULL;
	argp_parse(&argp, argc, argv, 0, 0, args);
}

/*
** Parsing options and add in structs using argp lib
*/
error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	t_args *arguments;
	int     i;

    arguments = state->input;
	i = 0;
	switch (key)
    {
        case 'a':
            arguments->a_opt = 1;
            break;
		case 'c':
			arguments->c_opt = 1;
			break;
		case 's':
			arguments->s_opt = 1;
			break;
        case 'v':
            arguments->v_opt = 1;
            break;
		case ARGP_KEY_ARGS:
      		if (state->arg_num >= 2)
        		argp_usage(state);
				arguments->argvalue = &state->argv[state->next];
				while (arguments->argvalue[i])
					i++;
				arguments->argcount = i;
      		break;
    	case ARGP_KEY_END:
      		if (state->arg_num < 2)
        	argp_usage (state);
      		break;
    	default:
      		return ARGP_ERR_UNKNOWN;	
    }
	return 0;
}



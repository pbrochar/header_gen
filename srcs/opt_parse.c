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
	{0}
};

static struct argp argp = {options, parse_opt, args_doc, doc};

void init_args_parse(t_hgen *opt, t_args *args, int argc, char **argv)
{
	args->c_opt = 0;
	args->argcount = 0;
    opt->count = 0;
	argp_parse(&argp, argc, argv, 0, 0, args);
}

error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	t_args *arguments;
	int     i;

    arguments = state->input;
	i = 0;
	switch (key)
    {
		case 'c':
			arguments->c_opt = 1;
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



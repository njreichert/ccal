/**
 * command_line.cpp
 *
 * By Nikolaus J. Reichert <nikolaus@njreichert.ca>
 *
 * Defninitions for command-line parsing routines.
 */

/**
 * @struct CommandOpts
 * @brief Options to pass back to the main program.
 *
 * @var CommandOpts::exit Whether the program should immediately exit.
 *     (We don't want to do anything if we call -h or -v.)
 *
 * @var CommandOpts::is_one_shot Whether the program should evaluate argv directly.
 *     In this case, ccal will print out the top of the stack after evaluation and exit.
 *
 * @var CommandOpts::one_shot_start The argument to get the one-shot statement from.
 *     The statement parser will concatenate all arguments starting from this one.
 */
typedef struct COMMAND_OPTS {
    bool exit;
    bool is_one_shot;
    int one_shot_start;
} CommandOpts;

/**
 * @brief Determine whether any valid arguments are passed to argv.
 *
 * @param argc The number of arguments.
 * @param argv All arguments passed by the operating system to main().
 *
 * @returns a struct which can be used to determine initial program state.
 */
CommandOpts parse_argv(int argc, char **argv);

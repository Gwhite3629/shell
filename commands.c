typedef struct command_t {
    char name[32];
    int hash;
	int id;
} command_t;

#define TABLESIZE 4

command_t COMMANDS[TABLESIZE] = {
{
    "EXIT",
    2089051583,
    0
},
{
    "PRINT",
    232054898,
    1
},
{
    "HELP",
    2089138798,
    2
},
{
    "CLEAR",
    216417516,
    3
}
};
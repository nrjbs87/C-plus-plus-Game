//#include "Model.h"
void do_swim_command(Model&);
void do_go_command(Model&);
void do_run_command(Model&);
void do_eat_command(Model&);
void do_float_command(Model&);
void do_zoom_command(Model&);
void do_attack_command(Model&);
void handle_new_command(Model*);
//saving and loading
void save_file(Model*);
void restore_file(Model*);


#ifndef INSTALL_H
#define INSTALL_H

extern char base_path[512];
extern char settings_path[512];
extern char cache_path[512];
extern char logs_path[512];

int install();
int init_paths(void);

#endif // INSTALL_H

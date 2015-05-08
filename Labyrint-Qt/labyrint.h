#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#define VELIKOST 9
#define POCET_PREDMETU 20
#define POCET_BODU 5
#define NIC -1
#define KONEC -2

using namespace std;

//struktura pro kazde policko
typedef struct {
int druh;
int otoceni;
int predmet;
} Policko;

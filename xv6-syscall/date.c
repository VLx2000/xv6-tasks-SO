#include "types.h"
#include "user.h"
#include "date.h"

int main(int argc, char *argv[])
{
	struct rtcdate r;

	if (date(&r)) {
		printf(2, "date failed\n");
		exit();
	}
	//Imprime data no formato Hora Minuto Segundo - Dia/Mes/Ano
    printf(1, "%dh %dmin %ds - %d/%d/%d", r.hour, r.minute, r.second, r.day, r.month, r.year);
	exit();
}
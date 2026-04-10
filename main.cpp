#include <cstdio>
#include <cstdlib>
#include "config.h"

int main() {
   char command[256];

    snprintf(command, sizeof(command),
        "curl -s 'http://%s/printer/objects/query?extruder'",
        PRINTER_IP
    );

    FILE* pipe = popen(command, "r");
    if (!pipe) {
    }

    FILE* out = fopen("response.json", "w");
    if (!out) {
        pclose(pipe);
        return 1;
    }

    char buffer[4096];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), pipe)) > 0) {
        fwrite(buffer, 1, bytes, out);
    }

    fclose(out);
    pclose(pipe);

    return 0;
}
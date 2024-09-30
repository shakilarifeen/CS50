#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("USAGE: ./recover FILE\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if (!card)
    {
        return 1;
    }


    uint8_t buffer[512];

    int i = 0;
    char *filename = malloc(4);
    sprintf(filename, "%03i,jpg", i);
    FILE *img = fopen(filename, "w");

    while (fread(buffer, 1, 512, card) == 512)
    {
        if (buffer[0] == 0xff)
        {
            if (buffer[1] == 0xd8)
            {
                if (buffer[2] == 0xff)
                {
                    if ((buffer[3] & 0xf0) == 0xe0)
                    {
                        if (i == 0)
                        {
                            fwrite(buffer, 1, 512, img);
                            i++;
                        }
                        else if (i > 0)
                        {
                            fwrite(buffer, 1, 512, img);
                            i++;
                        }

                    }
                }
            }
        }
        else
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    free(filename);
    fclose(img);
    fclose(card);

}

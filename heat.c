#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int start_day = 1;
    int end_day = 22;

    srand(time(NULL));

    for (int day = start_day; day <= end_day; day++) {

        // 70% chance commit ka
        if (rand() % 10 < 7) {

            int hour = 10 + rand() % 13;
            int minute = rand() % 60;

            char date[50];
            sprintf(date, "2026-04-%02dT%02d:%02d:00", day, hour, minute);

            // File update (IMPORTANT)
            FILE *fp = fopen("activity.txt", "a");
            if (fp != NULL) {
                fprintf(fp, "Commit on %s\n", date);
                fclose(fp);
            }

            char cmd[200];

            // git add
            sprintf(cmd, "git add .");
            system(cmd);

            // git commit with date
            sprintf(cmd, "git commit --date=\"%s\" -m \"commit %s\"", date, date);
            system(cmd);

            // git push
            sprintf(cmd, "git push");
            system(cmd);

            printf("Committed: %s\n", date);
        }
    }

    printf("DONE ✅\n");
    return 0;
}
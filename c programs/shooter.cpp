/* SimpleConsoleShooter.c
   Compile in Dev C++ (Windows). 
   Uses conio.h and windows.h (Sleep).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>   // for kbhit(), getch()
#include <windows.h> // for Sleep()

#define WIDTH 40
#define HEIGHT 20

#define MAX_BULLETS 8
#define MAX_ENEMIES 20

typedef struct {
    int x, y;
    int active;
} Bullet;

typedef struct {
    int x, y;
    int active;
} Enemy;

char screen[HEIGHT][WIDTH+1];

void clearScreenBuffer() {
    for (int r = 0; r < HEIGHT; ++r) {
        for (int c = 0; c < WIDTH; ++c) screen[r][c] = ' ';
        screen[r][WIDTH] = '\0';
    }
}

void drawBuffer() {
    // move cursor to top-left to avoid flicker from full clear
    // ANSI escape may not work on older Windows consoles; using system("cls") below is simpler but flickers.
    // We'll print lines; using system("cls") for reliability in Dev C++.
    system("cls");
    for (int r = 0; r < HEIGHT; ++r) {
        printf("%s\n", screen[r]);
    }
}

int main() {
    int playerX = WIDTH/2;
    int playerY = HEIGHT - 1;
    Bullet bullets[MAX_BULLETS] = {0};
    Enemy enemies[MAX_ENEMIES] = {0};
    int score = 0;
    int lives = 3;
    int frame = 0;
    int spawnRate = 12; // frames between spawns
    srand((unsigned int)time(NULL));

    // initialize enemies inactive
    for (int i=0;i<MAX_ENEMIES;i++) enemies[i].active = 0;
    for (int i=0;i<MAX_BULLETS;i++) bullets[i].active = 0;

    printf("Simple Console Shooter\nControls: a-left, d-right, space-shoot, q-quit\nPress any key to start...");
    getch();

    while (1) {
        // Input (non-blocking)
        if (kbhit()) {
            int ch = getch();
            if (ch == 'a' || ch == 'A') {
                if (playerX > 0) playerX--;
            } else if (ch == 'd' || ch == 'D') {
                if (playerX < WIDTH-1) playerX++;
            } else if (ch == ' ') {
                // fire bullet
                for (int i=0;i<MAX_BULLETS;i++) {
                    if (!bullets[i].active) {
                        bullets[i].active = 1;
                        bullets[i].x = playerX;
                        bullets[i].y = playerY - 1;
                        break;
                    }
                }
            } else if (ch == 'q' || ch == 'Q') {
                printf("\nQuit selected. Final score: %d\n", score);
                break;
            } else {
                // handle arrow keys (optional - two getch calls)
                if (ch == 0 || ch == 224) { // extended key
                    int ch2 = getch();
                    if (ch2 == 75 && playerX > 0) playerX--; // left arrow
                    if (ch2 == 77 && playerX < WIDTH-1) playerX++; // right arrow
                }
            }
        }

        // Update bullets
        for (int i=0;i<MAX_BULLETS;i++) {
            if (bullets[i].active) {
                bullets[i].y--;
                if (bullets[i].y < 0) bullets[i].active = 0;
            }
        }

        // Spawn enemies occasionally
        if (frame % spawnRate == 0) {
            // find inactive enemy slot
            for (int i=0;i<MAX_ENEMIES;i++) {
                if (!enemies[i].active) {
                    enemies[i].active = 1;
                    enemies[i].x = rand() % WIDTH;
                    enemies[i].y = 0;
                    break;
                }
            }
            // gradually increase difficulty
            if (spawnRate > 4 && frame % 200 == 0) spawnRate--;
        }

        // Move enemies downward
        for (int i=0;i<MAX_ENEMIES;i++) {
            if (enemies[i].active) {
                // simple movement: move every few frames to slow them
                if (frame % 2 == 0) enemies[i].y++;
                if (enemies[i].y >= HEIGHT) {
                    // enemy passed player -> lose life
                    enemies[i].active = 0;
                    lives--;
                    if (lives <= 0) {
                        clearScreenBuffer();
                        drawBuffer();
                        printf("\nGame Over! Score: %d\n", score);
                        return 0;
                    }
                }
            }
        }

        // Collision detection: bullets vs enemies
        for (int b=0;b<MAX_BULLETS;b++) {
            if (!bullets[b].active) continue;
            for (int e=0;e<MAX_ENEMIES;e++) {
                if (!enemies[e].active) continue;
                if (bullets[b].x == enemies[e].x && bullets[b].y == enemies[e].y) {
                    bullets[b].active = 0;
                    enemies[e].active = 0;
                    score += 10;
                    // small chance to give extra life
                    if (rand()%1000 < 10) lives++;
                    break;
                }
            }
        }

        // Collision detection: enemies with player
        for (int e=0;e<MAX_ENEMIES;e++) {
            if (enemies[e].active && enemies[e].y == playerY && enemies[e].x == playerX) {
                enemies[e].active = 0;
                lives--;
                if (lives <= 0) {
                    clearScreenBuffer();
                    drawBuffer();
                    printf("\nGame Over! Score: %d\n", score);
                    return 0;
                }
            }
        }

        // Draw to buffer
        clearScreenBuffer();
        // draw borders (optional)
        for (int c=0;c<WIDTH;c++) screen[0][c] = '-';
        for (int c=0;c<WIDTH;c++) screen[HEIGHT-2][c] = '-'; // horizon line

        // draw enemies
        for (int i=0;i<MAX_ENEMIES;i++) {
            if (enemies[i].active) {
                int ex = enemies[i].x, ey = enemies[i].y;
                if (ey >= 0 && ey < HEIGHT) screen[ey][ex] = 'V';
            }
        }

        // draw bullets
        for (int i=0;i<MAX_BULLETS;i++) {
            if (bullets[i].active) {
                int bx = bullets[i].x, by = bullets[i].y;
                if (by >= 0 && by < HEIGHT) screen[by][bx] = '|';
            }
        }

        // draw player
        screen[playerY][playerX] = 'A'; // player representation

        // draw HUD (score/lives) on last line (overwrite a bit)
        char hud[80];
        snprintf(hud, sizeof(hud), " Score: %d   Lives: %d   (a/d to move, space to shoot, q to quit) ", score, lives);
        int len = (int)strlen(hud);
        int place = 0;
        if (place + len >= WIDTH) len = WIDTH - place;
        for (int i=0;i<len;i++) screen[HEIGHT-1][place+i] = hud[i];

        // Render
        drawBuffer();

        // Frame control
        Sleep(80); // 80 ms ~ 12.5 FPS
        frame++;
    }
    return 0;
}

